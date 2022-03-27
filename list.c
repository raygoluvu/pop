#include "list.h"
#define define_list_ptr_to(type)                                     \
    ListNodePtr_##type newNode_##type(type val)                      \
    {                                                                \
        ListNodePtr_##type node = mymalloc(sizeof(ListNode_##type)); \
        node->next = NULL;                                           \
        node->val = val;                                             \
        return node;                                                 \
    }                                                                \
    int isEmpty_##type(ListNodeHead_##type head)                     \
    {                                                                \
        return (head->next) ? 0 : 1;                                 \
    }                                                                \
    ListNodePtr_##type findTop_##type(ListNodeHead_##type head)      \
    {                                                                \
        while (head && head->next)                                   \
        {                                                            \
            head = head->next;                                       \
        }                                                            \
        return head;                                                 \
    }                                                                \
    void print_List_##type(ListNodeHead_##type head)                 \
    {                                                                \
        printf("\n--NOW--\n");                                       \
        while (head && head->next)                                   \
        {                                                            \
            printf(data_format(#type), head->next->val);             \
            head = head->next;                                       \
        }                                                            \
        puts(" \n");                                                 \
    }

char *translate(int num)
{
    switch (num)
    {
    case 0:
    case 6:
        return "char";
    case 1:
    case 7:
        return "short";
    case 2:
    case 8:
        return "int";
    case 3:
    case 9:
        return "long";
    case 4:
    case 10:
        return "float";
    case 5:
    case 11:
        return "double";
    }
    return 0;
}
char *data_format(char *datatype)
{
    if (*datatype == 'i')
    {
        return " %d";
    }
    else if (*datatype == 'c')
    {
        return " %c";
    }
    else if (*datatype == 'd')
    {
        return " %lf";
    }
    else if (*datatype == 'f')
    {
        return " %f";
    }
    else if (*datatype == 'l')
    {
        return " %ld";
    }
    else if (*datatype == 's')
    {
        return " %hd";
    }
    else
    {
        return NULL;
    }
}
define_list_ptr_to(int)
    define_list_ptr_to(char)
        define_list_ptr_to(float)
            define_list_ptr_to(long)
                define_list_ptr_to(short)
                    define_list_ptr_to(double)