#ifndef QUEUE_H
#define QUEUE_H

typedef struct queuenode {
	void* data;
	struct queuenode* next;
} queuenode;

queuenode* queuenode_new(void* data);

typedef struct queue {
	struct queuenode* front;
	struct queuenode* back;
	int size;
} queue;

queue* queue_new(void);
void queue_init(queue* q);
void queue_free(queue* q);
int queue_size(queue* q);
int queue_empty(queue* q);
void queue_enqueue(queue* q, void* e);
void* queue_peek(queue* q);
void* queue_dequeue(queue* q);
int queue_contains(queue* q, void* e);
void queue_clear(queue* q);

#endif
