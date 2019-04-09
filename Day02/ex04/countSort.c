#include "header.h"

void countSort(unsigned char *utensils, int n) {
	int hash[NUMBER_OF_USTENSILS] = {0};
	int sum = 0;
	int arr[NUMBER_OF_USTENSILS] = {0};
	int *copy = calloc(sizeof(int) * n, 1);
	for (int i = 0; i < n; i++) {
		copy[i] = utensils[i];
	}
	for (int i = 0; i < n; i++) {
		hash[utensils[i]] += 1;
	}
	for (int i = 0; i < NUMBER_OF_USTENSILS + 1; i++) {
		sum += hash[i];
		arr[i] = sum;
	}
	for (int i = 0; i < n; i++) {
		utensils[arr[copy[i]] - 1] = copy[i];
		arr[copy[i]]--;
	}
}
