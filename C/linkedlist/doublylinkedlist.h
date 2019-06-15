#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdbool.h>

typedef struct doublynode {
	void* data;
	struct doublynode* next;
	struct doublynode* previous;
} doublynode;

doublynode* doublynode_new(void* data);
void doublynode_free(doublynode* node);

typedef struct doublylinkedlist {
	struct node* head;
	struct node* tail;
	int size;
} doublylinkedlist;

doublylinkedlist* doublylinkedlist_new(void);
void doublylinkedlist_init(doublylinkedlist* list);
void doublylinkedlist_free(doublylinkedlist* list);
int doublylinkedlist_size(const doublylinkedlist* list);
bool doublylinkedlist_empty(const doublylinkedlist* list);
void* doublylinkedlist_getfirst(const doublylinkedlist* list);
void* doublylinkedlist_getlast(const doublylinkedlist* list);
void* doublylinkedlist_get(const doublylinkedlist* list, int index);
void* doublylinkedlist_setfirst(doublylinkedlist* list, void* e);
void* doublylinkedlist_setlast(doublylinkedlist* list, void* e);
void* doublylinkedlist_set(doublylinkedlist* list, int index, void* e);
void doublylinkedlist_addfirst(doublylinkedlist* list, void* e);
void doublylinkedlist_addlast(doublylinkedlist* list, void* e);
void doublylinkedlist_add(doublylinkedlist* list, int index, void* e);
void* doublylinkedlist_removefirst(doublylinkedlist* list);
void* doublylinkedlist_removelast(doublylinkedlist* list);
void* doublylinkedlist_remove(doublylinkedlist* list, int index);
bool doublylinkedlist_contains(const doublylinkedlist* list, void* e);
int doublylinkedlist_index(const doublylinkedlist* list, void* e);
bool doublylinkedlist_erase(doublylinkedlist* list, void* e);
void doublylinkedlist_clear(doublylinkedlist* list);

#endif