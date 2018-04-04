#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// =========================================================
// Insertion sort
//
// https://en.wikipedia.org/wiki/Insertion_sort
// =========================================================


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

// Insertion sort
//
// How it works:
//  - Check first 	element and move it to the left ordenated position
//  - Check second 	element and move it to the left ordenated position
//  - Check third 	element and move it to the left ordenated position
//  - Check N 		element and move it to the left ordenated position
void insertionSortArray (int array_data[], int array_size) {
	int i, j, correctPosition, tmp;
	int nIterations=0;
	int nMoves=0;
	
	int DEBUG=0;
	
	// Loop between all "array_data" elements
	for (j=1; j<array_size; j++) {
		if(DEBUG) printf("\n");
		
		correctPosition = j;
		
		// Find correct position
		for (i=j; i>0; i--) {
			// Move to the next position
			if(array_data[i] < array_data[i-1]) {
				tmp = array_data[i-1];
				array_data[i-1] = array_data[i];
				array_data[i] = tmp;
				nMoves++;
			}
			nIterations++;
		}
	
		
		if(DEBUG) printf("LOOP [%2d]", j);
		if(DEBUG) for(i=0; i<array_size; i++) if(DEBUG) printf("%2d ", array_data[i]);
	}
	
	// DEBUG
	if(DEBUG) printf("\nHigher     : %d", array_data[array_size-1]);
	if(DEBUG) printf("\nIterations : %d", nIterations);
	if(DEBUG) printf("\nMoves      : %d", nMoves);
}



int main () {
	int i, found, value_to_search, DEBUG=0;
	
	// Create array of random values
	int n_data = 20000;
	int *data_array;
	data_array = generateRandomArray(n_data);
	
	// Sequential array
	//for(i=0; i<n_data; i++) data_array[i] = i;
	
	// Inverse sequential array
	for(i=0; i<n_data; i++) data_array[i] = n_data-i;
	
	// PRINT INPUT
	if(DEBUG) printf("[INPUT]  ");
	for(i=0; i<n_data; i++)
		if(DEBUG) printf("%2d ", data_array[i]);
	
	// Sort
	// =================================================
	float startTime, endTime, timeElapsed;
	startTime = (float)clock()/CLOCKS_PER_SEC;
	insertionSortArray(data_array, n_data);
	endTime = (float)clock()/CLOCKS_PER_SEC;
	timeElapsed = endTime - startTime;
	// =================================================
	
	printf("\n[BENCHMARK] %.7fs\n", timeElapsed);
	
	// Print sorted array
	if(DEBUG) printf("[OUTPUT] ");
	for(i=0; i<n_data; i++)
		if(DEBUG) printf("%2d ", data_array[i]);

	
	return 0;
}

