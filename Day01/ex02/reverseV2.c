#include "header.h"



t_stack *stackInit() {
	t_stack *newStack;

	newStack = calloc(sizeof(t_stack), 1);
	return newStack;
}

void push(t_stack *stack, char *word)
{
	t_item *newItem;

	if (!stack)
		return;
	newItem = calloc(sizeof(t_item), 1);
	newItem->word = word;
	if (stack->item) {
		newItem->next = stack->item;
	}
	stack->item = newItem;
}

void *pop(t_stack *stack)
{
	char *ret;
	if (!stack || !stack->item)
		return NULL;
	ret = stack->item->word;
	stack->item = stack->item->next;
	return (void *)ret;
}

void printReverseV2(t_node *lst) {
	t_stack *stack;

	stack = stackInit();
	while(lst) {
		push(stack, lst->word);
		lst = lst->next;
	}
	while(stack->item) {
		printf("%s", (char *)pop(stack));
		if (stack->item)
			printf(" ");
	}
	printf("\n");
}
