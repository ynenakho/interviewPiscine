#include "header.h"

void merge(t_player **arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    t_player *left[n1], *right[n2];

    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
        if (left[i]->score >= right[j]->score)
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

void mSort(t_player **arr, int l, int r)
{
	int m;

    if (l >= r)
		return;
	m = l + (r - l) / 2;
	mSort(arr, l, m);
	mSort(arr, m + 1, r);
	merge(arr, l, m, r);
}

struct s_player **mergeSort(struct s_player **players)
{
	int len = 0;

	while(players[len])
		len++;
	mSort(players, 0, len - 1);
	return players;
}
