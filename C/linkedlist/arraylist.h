#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdbool.h>

static const int INITIAL_CAPACITY = 16;

typedef struct array_list {
	void** data;
	int size;
	int capacity;
} array_list;

array_list* array_list_new();
void array_list_delete(array_list* list);
void array_list_add(array_list* list, void* e);
void array_list_insert(array_list* list, void* e, int index);
void* array_list_remove(array_list* list, int index);
void* array_list_get(const array_list* list, int index);
void array_list_set(array_list* list, int index, void* e);
void array_list_clear(array_list* list);
void array_list_resize(array_list* list);

#endif