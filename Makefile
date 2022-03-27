CC = gcc
LIB1 = mm.h list.h list_ptr.h queue.h queue_ptr.h
LIB2 = mm.h list.h list_ptr.h stack.h stack_ptr.h
DEP = mm.o list.o list_ptr.o
OBJ = stack.o main_stack.o queue.o stack_ptr.o queue_ptr.o

all : main_stack main_queue

main_stack : $(DEP) stack.o stack_ptr.o main_stack.o $(LIB2)
	$(CC) main_stack.o stack.o stack_ptr.o  $(DEP) -o $@

main_queue : $(DEP) queue.o queue_ptr.o main_queue.o $(LIB1)
	$(CC) main_queue.o queue.o queue_ptr.o $(DEP) -o $@

%.o : %.c $(LIB1) stack.h stack_ptr.h
	$(CC) $< -c -DDEBUG

dep : $(DEP) $(DEP_PTR) $(OBJ)

clean: 
	rm -rf main_stack main_queue *.o