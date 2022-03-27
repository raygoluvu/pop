#ifndef STACK_PTR_H
#define STACK_PTR_H
#include "list_ptr.h"

#define declare_Stack_Function_To_(type)                                \
    void push_ptr_to_##type(ListNodeHead_ptr_to_##type head, type val); \
    void pop_ptr_to_##type(ListNodeHead_ptr_to_##type head);            \
    void STACK_DEMO_PTR_TO_##type(ListNodeHead_ptr_to_##type head, char *dt, int op, type *v);

declare_Stack_Function_To_(int)
    declare_Stack_Function_To_(float)
        declare_Stack_Function_To_(double)
            declare_Stack_Function_To_(char)
                declare_Stack_Function_To_(long)
                    declare_Stack_Function_To_(short)
#endif