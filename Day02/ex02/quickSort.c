#include "header.h"

void swap(t_player **a, t_player **b)
{
    t_player t = **a;
    **a = **b;
    **b = t;
}

int partition (t_player **arr, int low, int high)
{
    int pivot = arr[high]->score;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j]->score > pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void qSort(t_player **arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        qSort(arr, low, pi - 1);
        qSort(arr, pi + 1, high);
    }
}

void quickSort(t_player **players)
{
	int len = 0;
	while (players[len]) {
		len++;
	}
	qSort(players, 0, len - 1);
}
