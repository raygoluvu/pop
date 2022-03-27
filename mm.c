#include "mm.h"

void *first_block;

block find_block(block *last, size_t size)
{
    block free_block = first_block;
    while (free_block && !(free_block->free && free_block->size >= size))
    {
        *last = free_block;
        free_block = free_block->next;
    }
    return free_block;
}

//擴增block
block extend_heap(block last, size_t s)
{
    block free_block;
    free_block = sbrk(0);
    if (sbrk(BLOCK_SIZE + s) == (void *)-1) //當sbrk error回傳NULL
        return NULL;
    free_block->size = s;
    free_block->next = NULL;
    if (last)
        last->next = free_block;
    free_block->free = 0;
    return free_block;
}

// 當block佔據空間過大,將block切割
void cut_block(block free_block, size_t s)
{
    block new;
    new = (block)free_block->data + s;
    new->size = free_block->size - s - BLOCK_SIZE;
    new->next = free_block->next;
    new->free = 1;
    free_block->size = s;
    free_block->next = new;
}

// 取得block位置
block get_block(void *ptr)
{
    char *tmp;
    tmp = ptr;
    return (ptr = tmp -= BLOCK_SIZE);
}

// 檢測block的合法性(確認block的確是由mymalloc所分配的記憶體)
int check_addr(void *ptr)
{
    if (first_block)
    {
        if (ptr > first_block && ptr < sbrk(0))
        {
            return ptr == (get_block(ptr))->ptr; //若吻合則回傳1
        }
    }
    return 0;
}

// 解決碎片block,如果block相鄰的區塊也是free狀態,則將相鄰block合併
block merge_near(block free_block)
{
    if (free_block->next && free_block->next->free)
    {
        free_block->size += BLOCK_SIZE + free_block->next->size;
        free_block->next = free_block->next->next; //連接非free的空間
        if (free_block->next)
            free_block->next->pre = free_block;
    }
    return free_block;
}

void myfree(void *ptr)
{
    block toFreeblock;
    if (check_addr(ptr))
    {
        toFreeblock = get_block(ptr);
        toFreeblock->free = 1;
        if (toFreeblock->pre && toFreeblock->pre->free)
            toFreeblock = merge_near(toFreeblock->pre);
        if (toFreeblock->next)
            merge_near(toFreeblock);
        else
        {
            if (toFreeblock->pre)
                toFreeblock->pre->pre = NULL;
            else
                first_block = NULL;
            brk(toFreeblock);
        }
    }
    DEBUG_INFO();
}

// 將分配的記憶體空間以8位元組對齊,將size調整為8的倍數
size_t align8(size_t s)
{
    if ((s & 0x7) == 0)
        return s;
    return ((s >> 3) + 1) << 3;
}

void copy_block(block src, block dst)
{
    size_t *sdata, *ddata;
    size_t i;
    sdata = src->ptr;
    ddata = dst->ptr;
    for (i = 0; (i * 8) < src->size && (i * 8) < dst->size; i++)
        ddata[i] = sdata[i];
}

void *mymalloc(size_t size)
{
    block b = sbrk(0), last;
    size_t s;

    s = align8(size);
    if (first_block)
    {

        last = first_block;
        b = find_block(&last, s);
        if (b)
        {
            if ((b->size - s) >= (BLOCK_SIZE + 8))
                cut_block(b, s);

            b->free = 0;
        }
        else
        {
            b = extend_heap(last, s);
            if (!b)
                return NULL;
        }
    }
    //給定初始空間
    else
    {
        first_block = sbrk(1024);
        block start = (block)first_block;
        start->size = 1024 - sizeof(*start);
        start->pre = start->next = NULL;
        start->free = 0;
        return start;
    }
    DEBUG_INFO();
    return b->data; //紀錄指標位置
}

void *myrealloc(void *ptr, size_t size)
{
    size_t s;
    block free_block, new;
    void *newp;
    if (!ptr)
        // 當ptr傳入NULL時,視為調用mymalloc
        return mymalloc(size);

    if (check_addr(ptr))
    {
        s = align8(size);
        free_block = get_block(ptr);
        if (free_block->size >= s)
        {
            if (free_block->size - s >= (BLOCK_SIZE + 8))
                cut_block(free_block, s);
        }
        else
        {
            // 確認是否可以合併
            if (free_block->next && free_block->next->free && (free_block->size + BLOCK_SIZE + free_block->next->size) >= s)
            {
                merge_near(free_block);
                if (free_block->size - s >= (BLOCK_SIZE + 8))
                    cut_block(free_block, s);
            }
            else
            {
                // 新的mymalloc
                newp = mymalloc(s);
                if (!newp)
                    return NULL;
                new = get_block(newp);       //找到正確位置
                copy_block(free_block, new); //複製舊資料至新空間
                myfree(ptr);                 //釋放舊記憶體空間
                return (newp);
            }
        }
        return (ptr);
    }
    return NULL;
}

void *mycalloc(size_t number, size_t size)
{
    size_t *new;
    size_t number8, i;
    new = mymalloc(number * size);
    if (new)
    {
        number8 = align8(number * size) >> 3;
        for (i = 0; i < number8; i++)
            new[i] = 0;
    }
    return new;
}