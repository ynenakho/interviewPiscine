#include "header.h"

t_group *createGroup(int size) {
	t_group *tmpGroup;
	tmpGroup = calloc(sizeof(t_group), 1);
	tmpGroup->size = size;
	tmpGroup->counter = 1;
	tmpGroup->next = NULL;
	return tmpGroup;
}

void bubbleSort(t_group **stone) {
	t_group *tmpPointer = *stone;
	int tmp;
	int tmpCounter;


	while(tmpPointer->next) {
		if(tmpPointer->size > tmpPointer->next->size) {
			tmp = tmpPointer->size;
			tmpCounter = tmpPointer->counter;
			tmpPointer->size = tmpPointer->next->size;
			tmpPointer->counter = tmpPointer->next->counter;
			tmpPointer->next->size = tmp;
			tmpPointer->next->counter = tmpCounter;
			tmpPointer = *stone;
		}
		else
			tmpPointer = tmpPointer->next;
	}
}

void sortStones(struct s_stone **stone)
{
	t_stone *tmpPointer = *stone;

	t_group *group;
	t_group *tmpGroup;

	group = createGroup(tmpPointer->size);
	tmpGroup = group;

	while(tmpPointer) {

		while(tmpPointer->next && (tmpPointer->next->size == tmpPointer->size)) {
			tmpGroup->counter += 1;
			tmpPointer = tmpPointer->next;
		}
		tmpPointer = tmpPointer->next;
		if (tmpPointer) {
			tmpGroup->next = createGroup(tmpPointer->size);
			tmpGroup = tmpGroup->next;
		}
	}
	bubbleSort(&group);
	tmpPointer = *stone;
	tmpGroup = group;
	while(tmpPointer) {
		tmpPointer->size = tmpGroup->size;
		tmpGroup->counter--;
		if (tmpGroup->counter == 0)
			tmpGroup = tmpGroup->next;
		tmpPointer = tmpPointer->next;
	}

}
