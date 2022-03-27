//#include"list.h"
#include "mm.h"
#include "queue.h"

#define define_Queue_Function(type)                                             \
    void addq_##type(ListNodeHead_##type head, type val)                        \
    {                                                                           \
        ListNodePtr_##type tmp = findTop_##type(head);                          \
        tmp->next = newNode_##type(val);                                        \
        tmp->next->prior = tmp;                                                 \
    }                                                                           \
    void deleteq_##type(ListNodeHead_##type head)                               \
    {                                                                           \
        if (isEmpty_##type(head))                                               \
        {                                                                       \
            printf("\nWARNING: Invalid operation!\n\n");                        \
            return;                                                             \
        }                                                                       \
        ListNodePtr_##type tmp = head->next;                                    \
        if (!head->next->next)                                                  \
        {                                                                       \
            head->next = NULL;                                                  \
            myfree(tmp->next);                                                  \
        }                                                                       \
        else                                                                    \
        {                                                                       \
            head->next = head->next->next;                                      \
            head->next->prior = head;                                           \
            myfree(tmp);                                                        \
        }                                                                       \
    }                                                                           \
    void QUEUE_DEMO_##type(ListNodeHead_##type head, char *dt, int op, type *v) \
    {                                                                           \
        print_List_##type(head);                                                \
        head = newNode_##type(0);                                               \
        v = (type *)mymalloc(sizeof(type));                                     \
        while (op != -1)                                                        \
        {                                                                       \
            printf("Please enter your operation\n:");                           \
            scanf("%d", &op);                                                   \
                                                                                \
            if (op == 1)                                                        \
            {                                                                   \
                printf("Enter %s: ", dt);                                       \
                scanf(data_format(dt), v);                                      \
                addq_##type(head, *v);                                          \
            }                                                                   \
            if (op == 2)                                                        \
            {                                                                   \
                deleteq_##type(head);                                           \
            }                                                                   \
            if (op == -1)                                                       \
            {                                                                   \
                while (head->next != NULL)                                      \
                {                                                               \
                    deleteq_##type(head);                                       \
                }                                                               \
                myfree(head);                                                   \
                break;                                                          \
            }                                                                   \
            print_List_##type(head);                                            \
        }                                                                       \
    }

define_Queue_Function(int)
    define_Queue_Function(float)
        define_Queue_Function(short)
            define_Queue_Function(long)
                define_Queue_Function(double)
                    define_Queue_Function(char)
