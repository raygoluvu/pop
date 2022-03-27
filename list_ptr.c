#include "list_ptr.h"
#include "list.h"

#define define_List_Ptr_Function_(type)                                          \
                                                                                 \
    ListNodePtr_to_##type newNode_ptr_to_##type(type val)                        \
    {                                                                            \
        ListNodePtr_to_##type node = mymalloc(sizeof(ListNode_to_##type));       \
        node->val = mymalloc(sizeof(type));                                      \
        node->next = NULL;                                                       \
        *(node->val) = val;                                                      \
        printf("Initial sucess!\n");                                             \
        return node;                                                             \
    }                                                                            \
                                                                                 \
    int isEmpty_ptr_to_##type(ListNodeHead_ptr_to_##type head)                   \
    {                                                                            \
        return (head->next) ? 0 : 1;                                             \
    }                                                                            \
                                                                                 \
    ListNodePtr_to_##type findTop_ptr_to_##type(ListNodeHead_ptr_to_##type head) \
    {                                                                            \
        while (head->next)                                                       \
        {                                                                        \
            head = head->next;                                                   \
        }                                                                        \
        return head;                                                             \
    }                                                                            \
                                                                                 \
    void print_List_ptr_to_##type(ListNodeHead_ptr_to_##type head)               \
    {                                                                            \
        printf("\n--NOW--\n");                                                   \
        while (head && head->next)                                               \
        {                                                                        \
            printf(data_format(#type), *head->next->val);                        \
            head = head->next;                                                   \
        }                                                                        \
        puts(" \n");                                                             \
    }

define_List_Ptr_Function_(int)
    define_List_Ptr_Function_(float)
        define_List_Ptr_Function_(double)
            define_List_Ptr_Function_(char)
                define_List_Ptr_Function_(long)
                    define_List_Ptr_Function_(short)