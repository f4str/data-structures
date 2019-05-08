#ifndef ARRAYLIST_H
#define ARRAYLIST_H

static const int INITIAL_CAPACITY = 16;

typedef struct array_list {
	void** data;
	int size;
	int capacity;
} array_list;

array_list* array_list_new();
void array_list_free(array_list* list);
int array_list_size(const array_list* list);
int array_list_capacity(const array_list* list);
void array_list_add(array_list* list, void* e);
void array_list_insert(array_list* list, void* e, int index);
void* array_list_remove(array_list* list, int index);
void* array_list_get(const array_list* list, int index);
void array_list_set(array_list* list, int index, void* e);
void array_list_clear(array_list* list);

#endif