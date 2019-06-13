#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

arraylist* arraylist_new() {
	arraylist* list = NULL;
	list = malloc(sizeof(arraylist));
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
	list->data = malloc(INITIAL_CAPACITY * sizeof(void*));
	return list;
}

void arraylist_init(arraylist* list) {
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
	list->data = malloc(INITIAL_CAPACITY * sizeof(void*));
}

void arraylist_free(arraylist* list) {
	free(list->data);
	free(list);
}

int arraylist_size(const arraylist* list) {
	return list->size;
}

int arraylist_capacity(const arraylist* list) {
	return list->capacity;
}

bool arraylist_empty(const arraylist* list) {
	return list->size == 0;
}

void* arraylist_get(const arraylist* list, int index) {
	return list->data[index];
}

void arraylist_set(arraylist* list, int index, void* e) {
	list->data[index] = e;
}

void arraylist_add(arraylist* list, void* e) {
	if (list->size == list->capacity) {
		list->data = realloc(list->data, list->capacity * 2);
		list->capacity *= 2;
	}
	
	list->data[list->size] = e;
	++(list->size);
}

void arraylist_insert(arraylist* list, int index, void* e) {
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


bool arraylist_contains(const arraylist* list, void* e) {
	int i;
	for (i = 0; i < list->size; ++i) {
		if (list->data[i] == e) {
			return true;
		}
	}
	return false;
}

int arraylist_index(const arraylist* list, void* e) {
	int i;
	for (i = 0; i < list->size; ++i) {
		if (list->data[i] == e) {
			return i;
		}
	}
	return -1;
}

void* arraylist_erase(arraylist* list, int index) {
	void* temp = list->data[index];
	int i;
	--(list->size);
	for (i = index; i < list->size; ++i) {
		list->data[i] = list->data[i + 1];
	}
	return temp;
}

bool arraylist_remove(arraylist* list, void* e) {
	int i = arraylist_index(list, e);
	if (i >= 0) {
		arraylist_erase(list, i);
		return true;
	}
	return false;
}

void arraylist_clear(arraylist* list) {
	free(list->data);
	list->size = 0;
	list->capacity = INITIAL_CAPACITY;
	list->data = malloc(INITIAL_CAPACITY * sizeof(void*));
}
