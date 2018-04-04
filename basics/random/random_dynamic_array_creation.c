#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Create new array dynamically with random values
int * generateRandomArray (int array_size) {
	int i;
	srand(time(NULL)); // Random seed based on current time
	
	// Dinamic array
	int *data_array;
	data_array= (int*)malloc(sizeof(int)*array_size);

	// Populating array
	for(i=0; i<array_size; i++) {
		data_array[i] = rand() % 999;
	}
	
	return data_array;
}


int main () {
	int i;
	
	// Create array dynamically
	int array_size = 20;
	int *data_array;
	data_array = generateRandomArray(array_size);
	
	// Print array
	printf("[RANDOM] ");
	for(i=0; i<array_size; i++)
		printf("%3d ", data_array[i]);
	printf("\n");

	return 0;
}


