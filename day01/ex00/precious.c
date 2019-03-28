#include "header.h"

t_list *createElem(char c, t_list *prev)
{
	t_list *newElem;

	newElem = calloc(sizeof(t_list), 1);
	newElem->c = c;
	newElem->next = NULL;
	newElem->prev = prev;
	return newElem;
}

t_list *initList(void) {
	t_list *listHead;
	t_list *temp;
	int i = 0;

	listHead = createElem(CS[i++], NULL);
	temp = listHead;
	while (CS[i])
	{
		temp->next = createElem(CS[i], temp);
		temp = temp->next;
		i++;
	}
	temp->next = listHead;
	listHead->prev = temp;
	return listHead;
}

void printList(t_list *list)
 {
	 while (list) {
		 printf("%c->", list->c);
		 list = list->prev;
	 }
 }

char *precious(int *text, int size)
{
	t_list *list;
	int i = 0;
	int temp;
	char *ret = calloc(size+1,1);

	list = initList();
	while (i < size) {
		temp = text[i];
		while(temp != 0) {
			if (temp < 0) {
				temp++;
				list = list->prev;
			} else {
				temp--;
				list = list->next;
			}
		}
		ret[i] = list->c;
		i++;
	}
	return ret;
}
