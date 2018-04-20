#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// =========================================================
// Selection sort
//
// https://en.wikipedia.org/wiki/Selection_sort
// =========================================================


// Selection sort
//
// How it works:
//  - Find the higher value and send it to the final
//  - Find the 2nd higher value and send it to the final-1
//  - Find the N higher value and send it to the final-N
void selectionSortArray (int array_data[], int array_size) {
	int i, j, higher, tmp;
	int nIterations=0;
	int nMoves=0;
	
	int DEBUG=0;
	
	higher = array_data[0];
	
	for (j=0; j<array_size; j++) {
		if(DEBUG) printf("\n");
		
		for (i=0; i<array_size-j; i++) {
			if(DEBUG) printf("#");
			
			if(array_data[i] < array_data[i-1]) {
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
	//for(i=0; i<n_data; i++) data_array[i] = n_data-i;
	
	// PRINT INPUT
	if(DEBUG) printf("[INPUT]  ");
	for(i=0; i<n_data; i++)
		if(DEBUG) printf("%2d ", data_array[i]);
	
	// Sort
	// =================================================
	float startTime, endTime, timeElapsed;
	startTime = (float)clock()/CLOCKS_PER_SEC;
	selectionSortArray(data_array, n_data);
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

