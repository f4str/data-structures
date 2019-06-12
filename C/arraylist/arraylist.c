#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

array_list* array_list_new() {
	array_list* list = NULL;
	list = malloc(sizeof(array_list));
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
	list->data = malloc(INITIAL_CAPACITY * sizeof(void*));
	return list;
}

void array_list_init(array_list* list) {
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
	list->data = malloc(INITIAL_CAPACITY * sizeof(void*));
}

void array_list_free(array_list* list) {
	free(list->data);
	free(list);
}

int array_list_size(const array_list* list) {
	return list->size;
}

int array_list_capacity(const array_list* list) {
	return list->capacity;
}

bool array_list_empty(const array_list* list) {
	return list->size == 0;
}

void* array_list_get(const array_list* list, int index) {
	return list->data[index];
}

void array_list_set(array_list* list, int index, void* e) {
	list->data[index] = e;
}

void array_list_add(array_list* list, void* e) {
	if (list->size == list->capacity) {
		list->data = realloc(list->data, list->capacity * 2);
		list->capacity *= 2;
	}
	
	list->data[list->size] = e;
	++(list->size);
}

void array_list_insert(array_list* list, int index, void* e) {
	if (list->size == list->capacity) {
		list->data = realloc(list->data, list->capacity * 2);
		list->capacity *= 2;
	}
	
	++(list->size);
	int i;
	for (i = list->size; i >= index; --i) {
		list->data[i] = list->data[i - 1];
	}
	list->data[index] = e;
}


bool array_list_contains(const array_list* list, void* e) {
	int i;
	for (i = 0; i < list->size; ++i) {
		if (list->data[i] == e) {
			return true;
		}
	}
	return false;
}

int array_list_index(const array_list* list, void* e) {
	int i;
	for (i = 0; i < list->size; ++i) {
		if (list->data[i] == e) {
			return i;
		}
	}
	return -1;
}

void* array_list_erase(array_list* list, int index) {
	void* temp = list->data[index];
	int i;
	--(list->size);
	for (i = index; i < list->size; ++i) {
		list->data[i] = list->data[i + 1];
	}
	return temp;
}

bool array_list_remove(array_list* list, void* e) {
	int i = array_list_index(list, e);
	if (i >= 0) {
		array_list_erase(list, i);
		return true;
	}
	return false;
}

void array_list_clear(array_list* list) {
	free(list->data);
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
	list->data = malloc(INITIAL_CAPACITY * sizeof(void*));
}
