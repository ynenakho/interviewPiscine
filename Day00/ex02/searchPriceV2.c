#include "header.h"

int binnarySearch(struct s_art **arts,char *name, int low, int high) {
	if (low <= high) {
		int pivot = (high - low) / 2 + low;
		if (strcmp(arts[pivot]->name, name) == 0)
			return arts[pivot]->price;
		if (strcmp(arts[pivot]->name, name) > 0) {
			return binnarySearch(arts, name, low, pivot - 1);
		} else if (strcmp(arts[pivot]->name, name) < 0) {
			return binnarySearch(arts, name, pivot + 1, high);
		}
	}
	return -1;

}

int searchPrice(struct s_art **arts, int n, char *name)
{
	return binnarySearch(arts, name, 0, n-1);
}
