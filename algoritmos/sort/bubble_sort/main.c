#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// Cria um vetor com X elementos
int * generateRandomArray (int array_size) {
	int i;
	srand(time(NULL)); // Random seed based on current time
	
	// Dinamic array
	int *data_array;
	data_array= (int*)malloc(sizeof(int)*array_size);

	// Populating array
	for(i=0; i<array_size; i++) {
		data_array[i] = rand() % 1000;
	}
	
	return data_array;
}

// Bubble sort
void bubbleSortArray (int array_data[], int array_size) {
	int i, j, higher, tmp;
	int nIterations=0;
	int nMoves=0;
	
	higher = array_data[0];
	
	for (j=0; j<array_size; j++) {
		printf("\n"); // DEBUG
		
		for (i=0; i<array_size-j; i++) {
			printf("#");// DEBUG
			
			if(array_data[i] > array_data[i-1]) {
				higher = array_data[i];
				
				tmp = array_data[i-1];
				array_data[i-1] = array_data[i];
				array_data[i] = tmp;
				
				nMoves++;
			}
			nIterations++;
		}

	}
	
	// DEBUG
	printf("\nHigher: %d", array_data[array_size-1]);
	printf("\nIterations: %d", nIterations);
	printf("\nMoves: %d", nMoves);
}



int main () {
	int i, found, value_to_search;
	
	// Create array of random values
	int n_data = 10;
	int *data_array;
	data_array = generateRandomArray(n_data);
	
	
	// Print unsorted array
	for(i=0; i<n_data; i++) {
		printf("%d ", data_array[i]);
	}
	
	// Sort
	bubbleSortArray(data_array, n_data);
	
	
	// Print sorted array
	printf("\n");
	for(i=0; i<n_data; i++) {
		printf("%d ", data_array[i]);
	}

	
	return 0;
}

