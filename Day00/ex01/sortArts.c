#include "header.h"

void swap(t_art **a, t_art **b)
{
    t_art t = **a;
    **a = **b;
    **b = t;
}

int partition (t_art **arr, int low, int high)
{
    char *pivot = arr[high]->name;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (strcmp(arr[j]->name, pivot) < 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(t_art **arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sortArts(struct s_art **arts)
{
	int len = 0;
	while (arts[len]) {
		len++;
	}
	quickSort(arts, 0, len - 1);
}
