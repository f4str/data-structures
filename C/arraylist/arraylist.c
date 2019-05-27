#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

array_list* array_list_new() {
	array_list* list = NULL;
	list = (array_list*)malloc(sizeof(array_list) * sizeof(void*));
	list->data = malloc(INITIAL_CAPACITY);
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
	return list;
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

void* array_list_get(const array_list* list, int index) {
	return list->data[index];
}

void array_list_set(array_list* list, const void* e, int index) {
	list->data[index] = e;
}

void array_list_add(array_list* list, void* e) {
	if (list->size == list->capacity) {
		realloc(list->data, list->capacity * 2);
		list->capacity *= 2;
	}
	
	list->data[list->size] = e;
	list->size++;
}

void array_list_insert(array_list* list, const void* e, int index) {
	if (list->size == list->capacity) {
		realloc(list->data, list->capacity * 2);
		list->capacity *= 2;
	}
	
	list->size++;
	int i;
	for (i = list->size; i >= index; --i) {
		list->data[i] = list->data[i - 1];
	}
	list->data[index] = e;
}

void* array_list_remove(array_list* list, int index) {
	void* temp = list->data[index];
	int i;
	list->size--;
	for (i = index; i < list->size; ++i) {
		list->data[i] = list->data[i + 1];
	}
	return temp;
}

void array_list_clear(array_list* list) {
	free(list->data);
	list->data = malloc(INITIAL_CAPACITY);
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
}
