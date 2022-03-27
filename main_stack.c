#include <stdio.h>
#include "stack.h"
#include "stack_ptr.h"
#include "list.h"
#include "list_ptr.h"
#include "mm.h"

int main()
{
    int operator= 0;
    int datatype = 0;
    void *val = 0;
    void *head = 0; // head is empty

    //prompt instruction
    printf("-- \"\nSTACK MODULE USING MACRO\"--\n\n");
    printf("-- \"Choose a datatype we want\"--\n");
    printf("-- \"Types 0 to 5 denote, char, short, int, long, float, and double\"--\n");
    printf("--\" 6 to 11, pointer to char, short, int, long, float, and double\"--\n");

    //demo
    printf("Input the datatype\n:");
    scanf("%d", &datatype);

    switch (datatype)
    {
    case 0:
        STACK_DEMO_char((ListNodeHead_char)head, translate(datatype), operator,(char *) val);
        break;
    case 6:
        STACK_DEMO_PTR_TO_char((ListNodeHead_ptr_to_char)head, translate(datatype), operator,(char *) val);
        break;
    case 1:
        STACK_DEMO_short((ListNodeHead_short)head, translate(datatype), operator,(short *) val);
        break;
    case 7:
        STACK_DEMO_PTR_TO_short((ListNodeHead_ptr_to_short)head, translate(datatype), operator,(short *) val);
        break;
    case 2:
        STACK_DEMO_int((ListNodeHead_int)head, translate(datatype), operator,(int *) val);
        break;
    case 8:
        STACK_DEMO_PTR_TO_int((ListNodeHead_ptr_to_int)head, translate(datatype), operator,(int *) val);
        break;
    case 3:
        STACK_DEMO_long((ListNodeHead_long)head, translate(datatype), operator,(long *) val);
        break;
    case 9:
        STACK_DEMO_PTR_TO_long((ListNodeHead_ptr_to_long)head, translate(datatype), operator,(long *) val);
        break;
    case 4:
        STACK_DEMO_float((ListNodeHead_float)head, translate(datatype), operator,(float *) val);
        break;
    case 10:
        STACK_DEMO_PTR_TO_float((ListNodeHead_ptr_to_float)head, translate(datatype), operator,(float *) val);
        break;
    case 5:
        STACK_DEMO_double((ListNodeHead_double)head, translate(datatype), operator,(double *) val);
        break;
    case 11:
        STACK_DEMO_PTR_TO_double((ListNodeHead_ptr_to_double)head, translate(datatype), operator,(double *) val);
        break;
    default:
        break;
    }
}
