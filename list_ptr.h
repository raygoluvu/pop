#ifndef LIST_PTR_H
#define LIST_PTR_H
#include <stdio.h>
#include <stdlib.h>
#include "mm.h"

#define declare_List_Ptr(type)                                                    \
                                                                                  \
    typedef struct list_ptr_##type                                                \
    {                                                                             \
        type *val;                                                                \
        struct list_ptr_##type *next;                                             \
        struct list_ptr_##type *prior;                                            \
    } * ListNodeHead_ptr_to_##type, *ListNodePtr_to_##type, ListNode_to_##type;   \
                                                                                  \
    ListNodePtr_to_##type newNode_ptr_to_##type(type val);                        \
    int isEmpty_ptr_to_##type(ListNodeHead_ptr_to_##type head);                   \
    ListNodePtr_to_##type findTop_ptr_to_##type(ListNodeHead_ptr_to_##type head); \
    void print_List_ptr_to_##type(ListNodeHead_ptr_to_##type head);

declare_List_Ptr(int)
    declare_List_Ptr(float)
        declare_List_Ptr(long)
            declare_List_Ptr(double)
                declare_List_Ptr(short)
                    declare_List_Ptr(char)
#endif
