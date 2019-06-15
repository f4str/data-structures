#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdbool.h>

typedef struct singlynode {
	void* data;
	struct singlynode* next;
} singlynode;

singlynode* singlynode_new(void* data);
void singlynode_free(singlynode* node);

typedef struct singlylinkedlist {
	struct node* head;
	struct node* tail;
	int size;
} singlylinkedlist;

singlylinkedlist* singlylinkedlist_new(void);
void singlylinkedlist_init(singlylinkedlist* list);
void singlylinkedlist_free(singlylinkedlist* list);
int singlylinkedlist_size(const singlylinkedlist* list);
bool singlylinkedlist_empty(const singlylinkedlist* list);
void* singlylinkedlist_getfirst(const singlylinkedlist* list);
void* singlylinkedlist_getlast(const singlylinkedlist* list);
void* singlylinkedlist_get(const singlylinkedlist* list, int index);
void* singlylinkedlist_setfirst(singlylinkedlist* list, void* e);
void* singlylinkedlist_setlast(singlylinkedlist* list, void* e);
void* singlylinkedlist_set(singlylinkedlist* list, int index, void* e);
void singlylinkedlist_addfirst(singlylinkedlist* list, void* e);
void singlylinkedlist_addlast(singlylinkedlist* list, void* e);
void singlylinkedlist_add(singlylinkedlist* list, int index, void* e);
void* singlylinkedlist_removefirst(singlylinkedlist* list);
void* singlylinkedlist_removelast(singlylinkedlist* list);
void* singlylinkedlist_remove(singlylinkedlist* list, int index);
bool singlylinkedlist_contains(const singlylinkedlist* list, void* e);
int singlylinkedlist_index(const singlylinkedlist* list, void* e);
bool singlylinkedlist_erase(singlylinkedlist* list, void* e);
void singlylinkedlist_clear(singlylinkedlist* list);

#endif