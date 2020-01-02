#ifndef DEQUE_H
#define DEQUE_H

typedef struct dequenode {
	void* data;
	struct dequenode* next;
	struct dequenode* previous;
} doublynode;

dequenode* dequenode_new(void* data);

typedef struct deque {
	struct deque* front;
	struct deque* back;
	int size;
} deque;

deque* deque_new(void);
void deque_init(deque* d);
void deque_free(deque* d);
int deque_size(const deque* d);
int deque_empty(const deque* d);
void* deque_getfirst(const deque* d);
void* deque_getlast(const deque* d);
void* deque_setfirst(deque* d, void* e);
void* deque_setlast(deque* d, void* e);
void deque_addfirst(deque* d, void* e);
void deque_addlast(deque* d, void* e);
void* deque_removefirst(deque* d);
void* deque_removelast(deque* d);
int deque_contains(const deque* d, void* e);
void deque_clear(deque* d);

#endif
