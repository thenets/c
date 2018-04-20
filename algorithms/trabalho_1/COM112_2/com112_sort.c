#include <stdio.h>
#include <stdlib.h>


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