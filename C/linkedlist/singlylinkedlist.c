#include <stdio.h>
#include <stdlib.h>
#include "singlylinkedlist.h"

singlynode* singlynode_new(void* data) {
	singlynode* node = NULL;
	node = malloc(sizeof(singlynode));
	node->data = data;
	node->next = NULL;
	return node;
}

singlylinkedlist* singlylinkedlist_new() {
	singlylinkedlist* list = NULL;
	list = malloc(sizeof(singlylinkedlist));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

void singlylinkedlist_init(singlylinkedlist* list) {
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

void singlylinkedlist_free(singlylinkedlist* list) {
	if (list->size == 0) {
		free(list);
		return;
	}
	singlynode* current = list->head;
	singlynode* temp = current->next;
	while (temp != NULL) {
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	free(list);
}

int singlylinkedlist_size(const singlylinkedlist* list) {
	return list->size;
}

bool singlylinkedlist_empty(const singlylinkedlist* list) {
	return list->size == 0;
}

void* singlylinkedlist_getfirst(const singlylinkedlist* list) {
	if (list->head == NULL) {
		return NULL;
	}
	return list->head->data;
}

void* singlylinkedlist_getlast(const singlylinkedlist* list) {
	if (list->tail == NULL) {
		return NULL;
	}
	return list->head->data;
}

void* singlylinkedlist_get(const singlylinkedlist* list, int index) {
	if (index == 0) {
		return singlylinkedlist_getfirst(list);
	}
	else if (index == list->size - 1) {
		return singlylinkedlist_getlast(list);
	}
	singlynode* current = list->head;
	int i;
	for (i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->data;
}

void* singlylinkedlist_setfirst(singlylinkedlist* list, void* e) {
	void* data = singlylinkedlist_getfirst(list);
	if (list->size == 0) {
		singlylinkedlist_addfirst(list, e);
	}
	else {
		list->head->data = e;
	}
	return data;
}

void* singlylinkedlist_setlast(singlylinkedlist* list, void* e) {
	void* data = singlylinkedlist_getlast(list);
	if (list->size == 0) {
		singlylinkedlist_addlast(list, e);
	}
	else {
		list->tail->data = e;
	}
	return data;
}

void* singlylinkedlist_set(singlylinkedlist* list, int index, void* e) {
	if (index == 0) {
		return singlylinkedlist_setfirst(list, e);
	}
	else if (index == list->size - 1) {
		return singlylinkedlist_setlast(list, e);
	}
	singlynode* current = list->head;
	int i;
	for (i = 0; i < index; ++i) {
		current = current->next;
	}
	void* data = current->data;
	current->data = e;
	return data;
}

void singlylinkedlist_addfirst(singlylinkedlist* list, void* e) {
	singlynode* temp = singlynode_new(e);
	if (list->size == 0) {
		list->head = temp;
		list->tail = temp;
	}
	else {
		temp->next = list->head;
		list->head = temp;
	}
	++(list->size);
}

void singlylinkedlist_addlast(singlylinkedlist* list, void* e) {
	singlynode* temp = singlynode_new(e);
	if (list->size == 0) {
		list->tail = temp;
		list->head = temp;
	}
	else {
		list->tail->next = temp;
		list->tail = temp;
	}
	++(list->size);
}

void singlylinkedlist_add(singlylinkedlist* list, int index, void* e) {
	if (index == 0) {
		singlylinkedlist_addfirst(list, e);
		return;
	}
	else if (index == list->size - 1) {
		singlylinkedlist_addlast(list, e);
		return;
	}
	singlynode* previous = list->head;
	singlynode* current = previous->next;
	int i;
	for (i = 0; i < index; ++i) {
		previous = current;
		current = current->next;
	}
	singlynode* temp = singlynode_new(e);
	previous->next = temp;
	temp->next = current;
	++(list->size);
}

void* singlylinkedlist_removefirst(singlylinkedlist* list) {
	void* data = singlylinkedlist_getfirst(list);
	singlynode* current;
	if (list->head == list->tail) {
		singlylinkedlist_clear(list);
	}
	else {
		current = list->head->next;
		free(list->head);
		list->head = current;
		--(list->size);
	}
	return data;
}

void* singlylinkedlist_removelast(singlylinkedlist* list) {
	void* data = singlylinkedlist_getlast(list);
	singlynode* current;
	if (list->head == list->tail) {
		singlylinkedlist_clear(list);
	}
	else {
		current = list->head;
		while (current->next != list->tail) {
			current = current->next;
		}
		free(list->tail);
		current->next = NULL;
		list->tail = current;
		--(list->size);
	}
	return data;
}

void* singlylinkedlist_remove(singlylinkedlist* list, int index) {
	if (index == 0) {
		return singlylinkedlist_removefirst(list);
	}
	else if (index == list->size - 1) {
		return singlylinkedlist_removelast(list);
	}
	singlynode* previous = list->head;
	singlynode* current = previous->next;
	int i;
	for (i = 0; i < index; ++i) {
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
	void* data = current->data;
	free(current);
	--(list->size);
	return data;
}

bool singlylinkedlist_contains(const singlylinkedlist* list, void* e) {
	singlynode* current = list->head;
	while (current != NULL) {
		if (current->data == e) {
			return true;
		}
		current = current->next;
	}
	return false;
}

int singlylinkedlist_index(const singlylinkedlist* list, void* e) {
	singlynode* current = list->head;
	int i;
	for (i = 0; current != NULL; ++i) {
		if (current->data == e) {
			return i;
		}
	}
	return -1;
}

bool singlylinkedlist_erase(singlylinkedlist* list, void* e) {
	int index = singlylinkedlist_index(list, e);
	if (index >= 0) {
		singlylinkedlist_remove(list, index);
		return true;
	}
	return false;
}

void singlylinkedlist_clear(singlylinkedlist* list) {
	if (list->size == 0) {
		return;
	}
	
	singlynode* current = list->head;
	singlynode* temp = current->next;
	while (temp != NULL) {
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}
