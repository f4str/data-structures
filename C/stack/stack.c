#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stacknode* stacknode_new(void* data) {
	stacknode* node = NULL;
	node = malloc(sizeof(stacknode));
	node->data = data;
	node->next = NULL;
	return node;
}

stack* stack_new(void) {
	stack* s = NULL;
	s = malloc(sizeof(stack));
	s->top = NULL;
	s->size = 0;
	return s;
}

void stack_init(stack* s) {
	s->top = NULL;
	s->size = 0;
}

void stack_free(stack* s) {
	if (s->size == 0) {
		free(s);
		return;
	}
	stacknode* current = s->top;
	stacknode* temp = current->next;
	while (temp != NULL) {
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	free(s);
}

int stack_size(stack* s) {
	return s->size;
}

int stack_empty(stack* s) {
	return s->size == 0;
}

void stack_push(stack* s, void* e) {
	stacknode* temp = stacknode_new(e);
	if (s->size == 0) {
		s->top = temp;
	}
	else {
		temp->next = s->top;
		s->top = temp;
	}
	++(s->size);
}

void* stack_peek(stack* s) {
	if (s->top == NULL) {
		return NULL;
	}
	return s->top->data;
}

void* stack_pop(stack* s) {
	if (s->size == 0) {
		return NULL;
	}
	stacknode* node = s->top;
	void* data = node->data;
	s->top = node->next;
	free(node);
	return data;
}

int stack_contains(stack* s, void* e) {
	stacknode* current = s->top;
	while (current != NULL) {
		if (current->data == e) {
			return 1;
		}
		current = current->next;
	}
	return 0;
}

void stack_clear(stack* s) {
	if (s->size == 0) {
		return;
	}
	stacknode* current = s->top;
	stacknode* temp = current->next;
	while (temp != NULL) {
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	
	s->top = NULL;
	s->size = 0;
}
