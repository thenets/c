#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// =========================================================
// Bubble sort
//
// https://en.wikipedia.org/wiki/Bubble_sort
// =========================================================

// Generate random array with "array_size" elements
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

// Selection sort
//
// How it works:
//  - Check if i[1] is lower than i[0],   switch if is true
//  - Check if i[2] is lower than i[1],   switch if is true
//  - Check if i[3] is lower than i[2],   switch if is true
//  - Check if i[4] is lower than i[3],   switch if is true
//  - Check if i[n] is lower than i[n-1], switch if is true
void bubbleSortArray (int array_data[], int array_size) {
	int i, j, higher, tmp, hasMove;
	int nIterations=0;
	int nMoves=0;
	
	int DEBUG=0;
	
	higher = array_data[0];
	
	hasMove=1;
	while(hasMove){
		hasMove=0;
		for (i=1; i<array_size; i++) {
			if(array_data[i] < array_data[i-1]) {
				higher = array_data[i];
				
				tmp = array_data[i-1];
				array_data[i-1] = array_data[i];
				array_data[i] = tmp;
				
				nMoves++;
				hasMove=1;
			}
			nIterations++;
		}
		
		if(DEBUG) printf("\n[LOOP %2d]", i);
		if(DEBUG) for(j=0; j<array_size; j++) if(DEBUG) printf("%2d ", array_data[j]);
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
	bubbleSortArray(data_array, n_data);
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
