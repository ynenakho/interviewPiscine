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
	return queue->first->que_node->name;
}

void enqueue(t_queue *queue, t_node *item) {
	t_que_item *newNode;

	newNode = calloc(sizeof(t_que_item), 1);
	newNode->que_node = item;
	if (isEmpty(queue))
		queue->first = newNode;
	else
		queue->last->next = newNode;
	queue->last = newNode;
}

t_node *dequeue(t_queue *queue) {
	if (isEmpty(queue))
		return NULL;
	t_node *ret;
	ret = queue->first->que_node;
	if (!queue->first->next)
		queue->last = NULL;
	queue->first = queue->first->next;
	return	ret;
}

t_node *dequeueBack(t_queue *queue) {
	if (isEmpty(queue))
		return NULL;
	t_node *ret;
	t_que_item *tmp;
	tmp = queue->first;

	ret = queue->last->que_node;
	while (tmp && tmp->next != queue->last)
		tmp = tmp->next;
	queue->last = tmp;
	if (queue->last)
		queue->last->next = NULL;
	else
		queue->first = NULL;
	return ret;
}

int findAllParents(t_node *root, char *name, t_queue *que) {
	if (!root)
		return 0;
	if (strcmp(root->name, name) == 0)
		return 1;
	enqueue(que, root);
	int i = 0;
	while(root->children[i]) {
		if (findAllParents(root->children[i], name, que)) {
			return 1;
		}
		i++;
	}
	dequeueBack(que);
	return 0;

}

void print_que(t_queue *queue) {
	while (!isEmpty(queue))
		printf("%s->", dequeue(queue)->name);
	printf("\n");
}

t_node *findParent(t_node *root, char *firstSpecies, char *secondSpecies) {
	t_node *parent = NULL ;
	t_queue *que1 = queueInit();
	t_queue *que2 = queueInit();

	findAllParents(root, firstSpecies, que1);
	findAllParents(root, secondSpecies, que2);
	while (!isEmpty(que1) && !isEmpty(que2)) {
		if (strcmp(peek(que1), peek(que2)))
			break;
		parent = dequeue(que1);
		dequeue(que2);
	}
	return parent;
}
