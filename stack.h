#ifndef STACK_H
#define STACK_H

#include "mm.h"
#include "list.h"

#define declare_Stack_Function(type)                      \
    void push_##type(ListNodeHead_##type head, type val); \
    void pop_##type(ListNodeHead_##type head);            \
    void STACK_DEMO_##type(ListNodeHead_##type head, char *dt, int op, type *v);

declare_Stack_Function(int)
    declare_Stack_Function(double)
        declare_Stack_Function(long)
            declare_Stack_Function(short)
                declare_Stack_Function(float)
                    declare_Stack_Function(char)
#endif