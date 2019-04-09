#include "header.h"

t_queue *queueInit(void) {
	return (t_queue *)calloc(sizeof(t_queue), 1);
}

int isEmpty(t_queue *queue) {
	return (!queue || !queue->first);
}

char *peek(t_queue *queue) {
	if (isEmpty(queue))
		return NULL;
	return queue->first->message;
}

void enqueue(t_queue *queue, char *message) {
	t_node *newNode;

	newNode = calloc(sizeof(t_node), 1);
	newNode->message = message;
	if (isEmpty(queue))
		queue->first = newNode;
	else
		queue->last->next = newNode;
	queue->last = newNode;
}

char *dequeue(t_queue *queue) {
	if (isEmpty(queue))
		return NULL;
	char *ret;
	ret = queue->first->message;
	if (!queue->first->next)
		queue->last = NULL;
	queue->first = queue->first->next;
	return	ret;
}

