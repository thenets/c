#include <stdio.h>
#include <stdlib.h>

// Create new array dynamically
int * generateArray (int array_size) {
	int i;
	
	// Dinamic array
	int *data_array;
	data_array= (int*)malloc(sizeof(int)*array_size);

	// Clean memory garbage
	for(i=0; i<array_size; i++)
		data_array[i] = 0;
	
	return data_array;
}

int main () {
	int i;
	
	// Create array dynamically
	int array_size = 20;
	int *data_array;
	data_array = generateArray(array_size);
	
	// Show before
	printf("[BEFORE]");
	for(i=0; i<array_size; i++)
		printf("%3d ", data_array[i]);
	printf("\n");
	
	// Change data to n*n
	for(i=0; i<array_size; i++)
		data_array[i] = i*i;
	
	// Show after
	printf("[AFTER ]");
	for(i=0; i<array_size; i++)
		printf("%3d ", data_array[i]);
	printf("\n");

	return 0;
}

