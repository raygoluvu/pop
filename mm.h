#ifdef DEBUG /* ******************************** */

#define DEBUG_INFO()                                                                              \
    do                                                                                            \
    {                                                                                             \
        printf("file name: %s, in funtion: %s, in line: %d\n", __FILE__, __FUNCTION__, __LINE__); \
    } while (0)
#else
#define DEBUG_INFO() \
    do               \
    {                \
    } while (0)
#endif
#ifndef MM_H
#define MM_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BLOCK_SIZE 24

typedef struct block *block;

struct block
{
    size_t size;
    block pre;
    block next;
    int free;
    int padding; //擴張符合八位元
    void *ptr;
    char data[1]; //虛擬字段，用來儲存位址
};

void myfree(void *);

void *mymalloc(size_t);

void *myrealloc(void *, size_t);

void *mycalloc(size_t, size_t);

int check_addr(void *ptr);

block get_block(void *ptr);

block find_block(block *last, size_t size);

block extend_heap(block last, size_t s);

size_t align8(size_t s);

void copy_block(block src, block dst);

block merge_near(block b);

void cut_block(block b, size_t s);

#endif