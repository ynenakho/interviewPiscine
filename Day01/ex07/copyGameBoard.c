#include "header.h"

t_node *copyNextF(t_node *node) {
	t_node *tmp;
	t_node *newNode;
	t_node *ret;

	tmp = node;
	newNode = calloc(sizeof(t_node), 1);
	newNode->value = tmp->value;
	ret = newNode;
	while(tmp->next) {
		tmp = tmp->next;
		newNode->next = calloc(sizeof(t_node), 1);
		newNode->next->value = tmp->value;
		newNode = newNode->next;
	}
	newNode->next = NULL;
	return ret;
}

t_node *findNode(t_node *node, int valueToFind) {
	t_node *tmp = node;
	while (tmp) {
		if (tmp->value == valueToFind) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return NULL;
}

t_node *copyRandomF(t_node *node, t_node *copy) {
	t_node *tmp = node;
	t_node *newCopy = copy;
	t_node *pointTo;
	int valueToFind;

	while(tmp) {
		if (tmp->random) {
			valueToFind = tmp->random->value;
			pointTo = findNode(copy, valueToFind);
			newCopy->random = pointTo;
		}
		tmp = tmp->next;
		newCopy = newCopy->next;
	}
	return copy;
}

t_node *cloneGameBoard(t_node *node) {
	t_node *copyNext;
	t_node *copyRandom;
	copyNext = copyNextF(node);
	copyRandom = copyRandomF(node, copyNext);
	return copyRandom;
}
