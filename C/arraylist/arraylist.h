#ifndef ARRAYLIST_H
#define ARRAYLIST_H

static const int INITIAL_CAPACITY = 16;

typedef struct arraylist {
	void** data;
	int size;
	int capacity;
} arraylist;

arraylist* arraylist_new(void);
void arraylist_init(arraylist* list);
void arraylist_free(arraylist* list);
int arraylist_size(const arraylist* list);
int arraylist_capacity(const arraylist* list);
int arraylist_empty(const arraylist* list);
void* arraylist_get(const arraylist* list, int index);
void arraylist_set(arraylist* list, int index, void* e);
int arraylist_contains(const arraylist* list, void* e);
int arraylist_index(const arraylist* list, void* e);
void arraylist_add(arraylist* list, void* e);
void arraylist_insert(arraylist* list, int index, void* e);
void* arraylist_remove(arraylist* list, int index);
int arraylist_erase(arraylist* list, void* e);
void arraylist_clear(arraylist* list);

#endif
