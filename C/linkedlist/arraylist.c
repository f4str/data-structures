#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

array_list* array_list_new() {
	array_list* list = NULL;
	list = (array_list*)malloc(sizeof(array_list));
	list->data = malloc(INITIAL_CAPACITY);
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
	return list;
}

void array_list_delete(array_list* list) {
	if (list != NULL) {
		free(list->data);
		free(list);
	}
}

void array_list_add(array_list* list, void* e) {
	if (list == NULL) {
		return;
	}
	array_list_resize(list);
	list->data[list->size] = e;
	list->size++;
}

void array_list_insert(array_list* list, void* e, int index) {
	if (list == NULL) {
		return NULL;
	}
	else if (index < 0 || index > list->size) {
		return NULL;
	}
	array_list_resize(list);
	int i;
	list->size++;
	for (i = list->size; i >= index; --i) {
		list->data[i] = list->data[i - 1];
	}
	list->data[index] = e;
}

void* array_list_remove(array_list* list, int index) {
	if (list == NULL) {
		return NULL;
	}
	else if (index < 0 || index > list->size) {
		return NULL;
	}
	void* temp = list->data[index];
	int i;
	list->size--;
	for (i = index; i < list->size; ++i) {
		list->data[i] = list->data[i + 1];
	}
	return temp;
}

void* array_list_get(const array_list* list, int index) {
	if (list == NULL) {
		return NULL;
	}
	else if (index < 0 || index > list->size) {
		return NULL;
	}
	return list->data[index];
}

void array_list_set(array_list* list, int index, void* e) {
	if (list == NULL) {
		return NULL;
	}
	else if (index < 0 || index > list->size) {
		return NULL;
	}
	list->data[index] = e;
}

void array_list_clear(array_list* list) {
	if (list == NULL) {
		return;
	}
	list->data = malloc(INITIAL_CAPACITY);
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
}

void array_list_resize(array_list* list) {
	if (list == NULL) {
		return;
	}
	if (list->size == list->capacity) {
		realloc(list->data, list->capacity * 2);
		list->capacity *= 2;
	}
}
