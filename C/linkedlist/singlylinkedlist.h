#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

typedef struct singlynode {
	void* data;
	struct singlynode* next;
} singlynode;

singlynode* singlynode_new(void* data);

typedef struct singlylinkedlist {
	struct singlynode* head;
	struct singlynode* tail;
	int size;
} singlylinkedlist;

singlylinkedlist* singlylinkedlist_new(void);
void singlylinkedlist_init(singlylinkedlist* list);
void singlylinkedlist_free(singlylinkedlist* list);
int singlylinkedlist_size(const singlylinkedlist* list);
int singlylinkedlist_empty(const singlylinkedlist* list);
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
int singlylinkedlist_contains(const singlylinkedlist* list, void* e);
int singlylinkedlist_index(const singlylinkedlist* list, void* e);
int singlylinkedlist_erase(singlylinkedlist* list, void* e);
void singlylinkedlist_clear(singlylinkedlist* list);

#endif
