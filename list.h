#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "mm.h"

#define declare_list_(type)                                        \
                                                                   \
    typedef struct list_##type                                     \
    {                                                              \
        type val;                                                  \
        struct list_##type *next;                                  \
        struct list_##type *prior;                                 \
    } * ListNodeHead_##type, *ListNodePtr_##type, ListNode_##type; \
                                                                   \
    ListNodePtr_##type newNode_##type(type val);                   \
    int isEmpty_##type(ListNodeHead_##type head);                  \
    void print_List_##type(ListNodeHead_##type head);              \
    ListNodePtr_##type findTop_##type(ListNodeHead_##type head);

char *translate(int num);
char *data_format(char *datatype);

declare_list_(int)
    declare_list_(char)
        declare_list_(double)
            declare_list_(float)
                declare_list_(short)
                    declare_list_(long)
#endif