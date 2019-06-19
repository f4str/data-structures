#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stacknode {
	void* data;
	struct stacknode* next;
} stacknode;

stacknode* stacknode_new(void* data);

typedef struct stack {
	struct stacknode* top;
	int size;
} stack;

stack* stack_new(void);
void stack_init(stack* s);
void stack_free(stack* s);
int stack_size(stack* s);
bool stack_empty(stack* s);
void stack_push(stack* s, void* e);
void* stack_peek(stack* s);
void* stack_pop(stack* s);
bool stack_contains(stack* s, void* e);
void stack_clear(stack* s);

#endif
