#include "header.h"

void printReverse(struct s_node *lst)
{
	static struct s_node *head;

	if (!head)
		head = lst;
	if (lst->next) {
		printReverse(lst->next);
		printf(" ");
	}
	printf("%s",lst->word);
	if (lst == head)
		printf("\n");
}
