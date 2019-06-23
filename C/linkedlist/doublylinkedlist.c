#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

doublynode* doublynode_new(void* data) {
	doublynode* node = NULL;
	node = malloc(sizeof(doublynode));
	node->data = data;
	node->next = NULL;
	node->previous = NULL;
	return node;
}

doublylinkedlist* doublylinkedlist_new() {
	doublylinkedlist* list = NULL;
	list = malloc(sizeof(doublylinkedlist));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

void doublylinkedlist_init(doublylinkedlist* list) {
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

void doublylinkedlist_free(doublylinkedlist* list) {
	if (list->size == 0) {
		free(list);
		return;
	}
	doublynode* current = list->head;
	doublynode* temp = current->next;
	while (temp != NULL) {
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	free(list);
}

int doublylinkedlist_size(const doublylinkedlist* list) {
	return list->size;
}

int doublylinkedlist_empty(const doublylinkedlist* list) {
	return list->size == 0;
}

void* doublylinkedlist_getfirst(const doublylinkedlist* list) {
	if (list->head == NULL) {
		return NULL;
	}
	return list->head->data;
}

void* doublylinkedlist_getlast(const doublylinkedlist* list) {
	if (list->tail == NULL) {
		return NULL;
	}
	return list->head->data;
}

void* doublylinkedlist_get(const doublylinkedlist* list, int index) {
	if (index == 0) {
		return doublylinkedlist_getfirst(list);
	}
	else if (index == list->size - 1) {
		return doublylinkedlist_getlast(list);
	}
	doublynode* current = list->head;
	int i;
	for (i = 0; i < index; ++i) {
		current = current->next;
	}
	return current->data;
}

void* doublylinkedlist_setfirst(doublylinkedlist* list, void* e) {
	void* data = doublylinkedlist_getfirst(list);
	if (list->size == 0) {
		doublylinkedlist_addfirst(list, e);
	}
	else {
		list->head->data = e;
	}
	return data;
}

void* doublylinkedlist_setlast(doublylinkedlist* list, void* e) {
	void* data = doublylinkedlist_getlast(list);
	if (list->size == 0) {
		doublylinkedlist_addlast(list, e);
	}
	else {
		list->tail->data = e;
	}
	return data;
}

void* doublylinkedlist_set(doublylinkedlist* list, int index, void* e) {
	if (index == 0) {
		return doublylinkedlist_setfirst(list, e);
	}
	else if (index == list->size - 1) {
		return doublylinkedlist_setlast(list, e);
	}
	doublynode* current = list->head;
	int i;
	for (i = 0; i < index; ++i) {
		current = current->next;
	}
	void* data = current->data;
	current->data = e;
	return data;
}

void doublylinkedlist_addfirst(doublylinkedlist* list, void* e) {
	doublynode* temp = doublynode_new(e);
	if (list->size == 0) {
		list->head = temp;
		list->tail = temp;
	}
	else {
		temp->next = list->head;
		temp->previous = NULL;
		list->head = temp;
	}
	++(list->size);
}

void doublylinkedlist_addlast(doublylinkedlist* list, void* e) {
	doublynode* temp = doublynode_new(e);
	if (list->size == 0) {
		list->tail = temp;
		list->head = temp;
	}
	else {
		list->tail->next = temp;
		temp->previous = list->tail;
		list->tail = temp;
	}
	++(list->size);
}

void doublylinkedlist_add(doublylinkedlist* list, int index, void* e) {
	if (index == 0) {
		doublylinkedlist_addfirst(list, e);
		return;
	}
	else if (index == list->size - 1) {
		doublylinkedlist_addlast(list, e);
		return;
	}
	doublynode* current = list->head;
	int i;
	for (i = 0; i <= index; ++i) {
		current = current->next;
	}
	doublynode* temp = doublynode_new(e);
	current->previous->next = temp;
	temp->previous = current->previous;
	temp->next = current;
	++(list->size);
}

void* doublylinkedlist_removefirst(doublylinkedlist* list) {
	void* data = doublylinkedlist_getfirst(list);
	doublynode* current;
	if (list->head == list->tail) {
		doublylinkedlist_clear(list);
	}
	else {
		current = list->head->next;
		free(list->head);
		list->head = current;
		list->head->previous = NULL;
		--(list->size);
	}
	return data;
}

void* doublylinkedlist_removelast(doublylinkedlist* list) {
	void* data = doublylinkedlist_getlast(list);
	doublynode* current;
	if (list->head == list->tail) {
		doublylinkedlist_clear(list);
	}
	else {
		current = list->tail->previous;
		free(list->tail);
		list->tail = current;
		list->tail->next = NULL;
		--(list->size);
	}
	return data;
}

void* doublylinkedlist_remove(doublylinkedlist* list, int index) {
	if (index == 0) {
		return doublylinkedlist_removefirst(list);
	}
	else if (index == list->size - 1) {
		return doublylinkedlist_removelast(list);
	}
	doublynode* current = list->head;
	int i;
	for (i = 0; i < index; ++i) {
		current = current->next;
	}
	current->previous->next = current->next;
	void* data = current->data;
	free(current);
	--(list->size);
	return data;
}

int doublylinkedlist_contains(const doublylinkedlist* list, void* e) {
	doublynode* current = list->head;
	while (current != NULL) {
		if (current->data == e) {
			return 1;
		}
		current = current->next;
	}
	return 0;
}

int doublylinkedlist_index(const doublylinkedlist* list, void* e) {
	doublynode* current = list->head;
	int i;
	for (i = 0; current != NULL; ++i) {
		if (current->data == e) {
			return i;
		}
	}
	return -1;
}

int doublylinkedlist_erase(doublylinkedlist* list, void* e) {
	int index = doublylinkedlist_index(list, e);
	if (index >= 0) {
		doublylinkedlist_remove(list, index);
		return 1;
	}
	return 0;
}

void doublylinkedlist_clear(doublylinkedlist* list) {
	if (list->size == 0) {
		return;
	}
	
	doublynode* current = list->head;
	doublynode* temp = current->next;
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
