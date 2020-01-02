#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

dequenode* dequenode_new(void* data) {
	dequenode* node = malloc(sizeof(dequenode));
	node->data = data;
	node->next = NULL;
	node->previous = NULL;
	return node;
}

deque* deque_new() {
	deque* d = malloc(sizeof(deque));
	d->front = NULL;
	d->back = NULL;
	d->size = 0;
	return d;
}

void deque_init(deque* d) {
	d->front = NULL;
	d->back = NULL;
	d->size = 0;
}

void deque_free(deque* d) {
	if (d->size == 0) {
		free(d);
		return;
	}
	
	dequenode* current = d->front;
	dequenode* temp = current->next;
	while (temp != NULL) {
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	free(d);
}

int deque_size(const deque* d) {
	return d->size;
}

int deque_empty(const deque* d) {
	return d->size == 0;
}

void* deque_getfirst(const deque* d) {
	if (d->front == NULL) {
		return NULL;
	}
	return d->front->data;
}

void* deque_getlast(const deque* d) {
	if (d->back == NULL) {
		return NULL;
	}
	return d->front->data;
}

void* deque_setfirst(deque* d, void* e) {
	void* data = deque_getfirst(d);
	if (d->size == 0) {
		deque_addfirst(d, e);
	}
	else {
		d->front->data = e;
	}
	return data;
}

void* deque_setlast(deque* d, void* e) {
	void* data = deque_getlast(d);
	if (d->size == 0) {
		deque_addlast(d, e);
	}
	else {
		d->back->data = e;
	}
	return data;
}

void deque_addfirst(deque* d, void* e) {
	dequenode* temp = dequenode_new(e);
	if (d->size == 0) {
		d->front = temp;
		d->back = temp;
	}
	else {
		temp->next = d->front;
		temp->previous = NULL;
		d->front = temp;
	}
	++d->size;
}

void deque_addlast(deque* d, void* e) {
	dequenode* temp = dequenode_new(e);
	if (d->size == 0) {
		d->back = temp;
		d->front = temp;
	}
	else {
		d->back->next = temp;
		temp->previous = d->back;
		d->back = temp;
	}
	++d->size;
}

void* deque_removefirst(deque* d) {
	void* data = deque_getfirst(d);
	dequenode* current;
	if (d->front == d->back) {
		deque_clear(d);
	}
	else {
		current = d->front->next;
		free(d->front);
		d->front = current;
		d->front->previous = NULL;
		--d->size;
	}
	return data;
}

void* deque_removelast(deque* d) {
	void* data = deque_getlast(d);
	dequenode* current;
	if (d->front == d->back) {
		deque_clear(d);
	}
	else {
		current = d->back->previous;
		free(d->back);
		d->back = current;
		d->back->next = NULL;
		--d->size;
	}
	return data;
}

int deque_contains(const deque* d, void* e) {
	dequenode* current = d->front;
	while (current != NULL) {
		if (current->data == e) {
			return 1;
		}
		current = current->next;
	}
	return 0;
}

int deque_erase(deque* d, void* e) {
	int index = deque_index(d, e);
	if (index >= 0) {
		deque_remove(d, index);
		return 1;
	}
	return 0;
}

void deque_clear(deque* d) {
	if (d->size == 0) {
		return;
	}
	
	dequenode* current = d->front;
	dequenode* temp = current->next;
	while (temp != NULL) {
		free(current);
		current = temp;
		temp = temp->next;
	}
	free(current);
	
	d->front = NULL;
	d->back = NULL;
	d->size = 0;
}
