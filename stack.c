#include "stack.h"
#include "mm.h"
#include <string.h>

#define define_Stack_Function(type)                                             \
    void push_##type(ListNodeHead_##type head, type v)                          \
    {                                                                           \
        ListNodePtr_##type tmp = findTop_##type(head);                          \
        tmp->next = newNode_##type(v);                                          \
        tmp->next->prior = tmp;                                                 \
    }                                                                           \
    void pop_##type(ListNodeHead_##type head)                                   \
    {                                                                           \
        if (isEmpty_##type(head))                                               \
        {                                                                       \
            printf("\nInvalid operation!\n\n");                                 \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            ListNodePtr_##type tmp;                                             \
            tmp = findTop_##type(head);                                         \
            tmp->prior->next = NULL;                                            \
            myfree(tmp);                                                        \
        }                                                                       \
    }                                                                           \
                                                                                \
    void STACK_DEMO_##type(ListNodeHead_##type head, char *dt, int op, type *v) \
    {                                                                           \
        print_List_##type(head);                                                \
        head = newNode_##type(0);                                               \
        v = (type *)mymalloc(sizeof(type));                                     \
                                                                                \
        while (op != -1)                                                        \
        {                                                                       \
            printf("Please enter your operation\n:");                           \
            scanf("%d", &op);                                                   \
                                                                                \
            if (op == 1)                                                        \
            {                                                                   \
                printf("Enter %s: ", dt);                                       \
                scanf(data_format(dt), v);                                      \
                push_##type(head, *v);                                          \
            }                                                                   \
            if (op == 2)                                                        \
            {                                                                   \
                pop_##type(head);                                               \
            }                                                                   \
            if (op == -1)                                                       \
            {                                                                   \
                while (head->next != NULL)                                      \
                {                                                               \
                    pop_##type(head);                                           \
                }                                                               \
                myfree(head);                                                   \
                break;                                                          \
            }                                                                   \
            print_List_##type(head);                                            \
        }                                                                       \
    }

define_Stack_Function(int)
    define_Stack_Function(double)
        define_Stack_Function(char)
            define_Stack_Function(short)
                define_Stack_Function(float)
                    define_Stack_Function(long)
