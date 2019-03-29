#include "header.h"

int main(void)
{
	int n;
	int *rocks;
	int value;

	srand(time(NULL));
	n = rand() % 90 + 10;
	rocks = createRandomArray(n);
	if (rand() % 2)
		value = rand() % 30;
	else
		value = rocks[rand() % n];

	/*-------------------
	launch your test here
	--------------------*/

	printArray(rocks, n);
	printf("Value %d at index %d\n", value, searchShifted(rocks, n, value));
}



// Function used for the test
// Don't go further :)

int *createRandomArray(int n) {
	int *arr, *arrShifted;
	int shift;
	int value = 1;

	if (!(arr = (int *)(malloc(sizeof(int) * n))))
		return (NULL);
	for (int i = 0; i < n; i++) {
		if (rand() % 5 == 0)
			value += rand() % 5;
		arr[i] = value;
	}
	if (!(arrShifted = (int *)(malloc(sizeof(int) * n))))
		return (NULL);
	shift = rand() % 100;
	for (int i = 0; i < n; i++) {
		arrShifted[i] = arr[(i + shift) % n];
	}
	free(arr);
	return (arrShifted);
}

void printArray(int *arr, int n) {
	printf("Index : ");
	for (int i = 0; i < n; i++) {
		printf("%3d ", i);
	}
	printf("\n");
	printf("Rocks : ");
	for (int i = 0; i < n; i++) {
		printf("%3d ", arr[i]);
	}
	printf("\n");
}
