#include "queue_ptr.h"
#include "list_ptr.h"
#include "list.h"

#define define_Queue_Function_To_(type)                                                       \
    void addq_ptr_to_##type(ListNodeHead_ptr_to_##type head, type val)                        \
    {                                                                                         \
        ListNodePtr_to_##type tmp = findTop_ptr_to_##type(head);                              \
        tmp->next = newNode_ptr_to_##type(val);                                               \
    }                                                                                         \
                                                                                              \
    void deleteq_ptr_to_##type(ListNodeHead_ptr_to_##type head)                               \
    {                                                                                         \
        if (isEmpty_ptr_to_##type(head))                                                      \
        {                                                                                     \
            printf("\nWARNING: Invalid operation!\n\n");                                      \
            return;                                                                           \
        }                                                                                     \
        ListNodePtr_to_##type tmp = head->next;                                               \
        if (!head->next->next)                                                                \
        {                                                                                     \
            head->next = NULL;                                                                \
            myfree(tmp->next);                                                                \
        }                                                                                     \
        else                                                                                  \
        {                                                                                     \
            head->next = head->next->next;                                                    \
            head->next->prior = head;                                                         \
                                                                                              \
            myfree(tmp);                                                                      \
        }                                                                                     \
    }                                                                                         \
    void QUEUE_DEMO_PTR_TO_##type(ListNodeHead_ptr_to_##type head, char *dt, int op, type *v) \
    {                                                                                         \
        print_List_ptr_to_##type(head);                                                       \
        head = (ListNodePtr_to_##type)newNode_ptr_to_##type(0);                               \
        v = mymalloc(sizeof(type));                                                           \
        while (op != -1)                                                                      \
        {                                                                                     \
            printf("Please enter your operation\n:");                                         \
            scanf("%d", &op);                                                                 \
                                                                                              \
            if (op == 1)                                                                      \
            {                                                                                 \
                printf("Enter %s: ", dt);                                                     \
                scanf(data_format(dt), v);                                                    \
                addq_ptr_to_##type(head, *v);                                                 \
            }                                                                                 \
            if (op == 2)                                                                      \
            {                                                                                 \
                deleteq_ptr_to_##type(head);                                                  \
            }                                                                                 \
            if (op == -1)                                                                     \
            {                                                                                 \
                while (head->next != NULL)                                                    \
                {                                                                             \
                    deleteq_ptr_to_##type(head);                                              \
                }                                                                             \
                myfree(head);                                                                 \
                break;                                                                        \
            }                                                                                 \
            print_List_ptr_to_##type(head);                                                   \
        }                                                                                     \
    }
define_Queue_Function_To_(int)
    define_Queue_Function_To_(float)
        define_Queue_Function_To_(short)
            define_Queue_Function_To_(long)
                define_Queue_Function_To_(double)
                    define_Queue_Function_To_(char)
