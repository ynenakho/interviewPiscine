#include "header.h"

void insertionSort(t_player **players) {
	int i = 1, j;
	t_player *temp;

	while(players[i]) {
		temp = players[i];
		j = i - 1;
		while (j >= 0 && players[j]->score < temp->score) {
			players[j + 1] = players[j];
			j--;
		}
		players[j + 1] = temp;
		i++;
	}
}
