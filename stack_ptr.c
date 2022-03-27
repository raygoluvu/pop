#include "list_ptr.h"
#include "stack_ptr.h"
#include "list.h"

#define define_Stack_Function_(type)                                                          \
    void push_ptr_to_##type(ListNodeHead_ptr_to_##type head, type val)                        \
    {                                                                                         \
        ListNodeHead_ptr_to_##type new_add_node = newNode_ptr_to_##type(val);                 \
        if (!head->next)                                                                      \
        {                                                                                     \
            head->next = new_add_node;                                                        \
            new_add_node->prior = head;                                                       \
        }                                                                                     \
        else                                                                                  \
        {                                                                                     \
            ListNodeHead_ptr_to_##type tmp = findTop_ptr_to_##type(head);                     \
            tmp->next = new_add_node;                                                         \
            new_add_node->prior = tmp;                                                        \
        }                                                                                     \
    }                                                                                         \
                                                                                              \
    void pop_ptr_to_##type(ListNodeHead_ptr_to_##type head)                                   \
    {                                                                                         \
        if (isEmpty_ptr_to_##type(head))                                                      \
        {                                                                                     \
            printf("\nUnvalid operation!\n\n");                                               \
        }                                                                                     \
        else                                                                                  \
        {                                                                                     \
            ListNodePtr_to_##type tmp;                                                        \
            tmp = findTop_ptr_to_##type(head);                                                \
            tmp->prior->next = NULL;                                                          \
            myfree(tmp);                                                                      \
        }                                                                                     \
    }                                                                                         \
    void STACK_DEMO_PTR_TO_##type(ListNodeHead_ptr_to_##type head, char *dt, int op, type *v) \
    {                                                                                         \
        print_List_ptr_to_##type(head);                                                       \
        head = (ListNodePtr_to_##type)newNode_ptr_to_##type(0);                               \
        v = (type *)mymalloc(sizeof(type));                                                   \
        while (op != -1)                                                                      \
        {                                                                                     \
            printf("Please enter your operation\n:");                                         \
            scanf("%d", &op);                                                                 \
                                                                                              \
            if (op == 1)                                                                      \
            {                                                                                 \
                printf("Enter %s: ", dt);                                                     \
                scanf(data_format(dt), v);                                                    \
                push_ptr_to_##type(head, *v);                                                 \
            }                                                                                 \
            if (op == 2)                                                                      \
            {                                                                                 \
                pop_ptr_to_##type(head);                                                      \
            }                                                                                 \
            if (op == -1)                                                                     \
            {                                                                                 \
                while (head->next != NULL)                                                    \
                {                                                                             \
                    pop_ptr_to_##type(head);                                                  \
                }                                                                             \
                myfree(head);                                                                 \
                break;                                                                        \
            }                                                                                 \
            print_List_ptr_to_##type(head);                                                   \
        }                                                                                     \
    }

define_Stack_Function_(char)
    define_Stack_Function_(short)
        define_Stack_Function_(int)
            define_Stack_Function_(long)
                define_Stack_Function_(float)
                    define_Stack_Function_(double)