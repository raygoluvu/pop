#ifndef QUEUE_H
#define QUEUE_H
#include "list.h"

#define declare_Queue_Function_(type)                     \
    void addq_##type(ListNodeHead_##type head, type val); \
    void deleteq_##type(ListNodeHead_##type head);        \
    void QUEUE_DEMO_##type(ListNodeHead_##type head, char *dt, int op, type *v);

declare_Queue_Function_(int)
    declare_Queue_Function_(double)
        declare_Queue_Function_(float)
            declare_Queue_Function_(char)
                declare_Queue_Function_(short)
                    declare_Queue_Function_(long)

#endif