#ifndef QUEUE_PTR_H
#define QUEUE_PTR_H
#include "list_ptr.h"

#define declare_Queue_Function_To_(type)                                \
    void addq_ptr_to_##type(ListNodeHead_ptr_to_##type head, type val); \
    void deleteq_ptr_to_##type(ListNodeHead_ptr_to_##type head);        \
    void QUEUE_DEMO_PTR_TO_##type(ListNodeHead_ptr_to_##type head, char *dt, int op, type *v);

declare_Queue_Function_To_(int)
    declare_Queue_Function_To_(double)
        declare_Queue_Function_To_(float)
            declare_Queue_Function_To_(char)
                declare_Queue_Function_To_(short)
                    declare_Queue_Function_To_(long)

#endif