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

//void mergeSort2(x inicio, fim){
//
//  int meio;
//
//  if(inicio < fim){
//    meio = (inicio + fim)/2;
//    mergeSort(x, inicio, meio);
//    mergeSort(x, meio+1, fim);
//    merge(x, inicio, fim, meio);
//  }
//}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortJoin(int array_data, int i_start, int i_middle, int i_end) {
	
}


void mergeSortSlice (int array_data[], int i_start, int i_end) {
	int i_middle;
	
	printf("l[%d] r[%d]", i_start, i_end);
	
	
	if(i_start < i_end) {
		i_middle = (i_start + i_end)/2;
		
		mergeSortSlice(array_data, i_start, i_middle);
		mergeSortSlice(array_data, i_middle+1, i_end);
		mergeSortSlice(array_data, i_start, i_end);
		exit(0);
	}

	
//				tmp = array_data[i-1];
//				array_data[i-1] = array_data[i];
//				array_data[i] = tmp;
				
//		if(DEBUG) printf("\n[LOOP %2d]", i);
//		if(DEBUG) for(j=0; j<array_size; j++) if(DEBUG) printf("%2d ", array_data[j]);

}



// Merge sort
//
// How it works:
//  - 123123123123123
void mergeSortArray (int array_data[], int array_size) {
	int i, j, higher, tmp, hasMove;
	int nIterations=0;
	int nMoves=0;
	
	int DEBUG=0;
	
	higher = array_data[0];
	
	mergeSortSlice(array_data, 0, array_size-1);
	
	// DEBUG
	if(DEBUG) printf("\nHigher     : %d", array_data[array_size-1]);
	if(DEBUG) printf("\nIterations : %d", nIterations);
	if(DEBUG) printf("\nMoves      : %d", nMoves);
}

int main () {
	int i, found, value_to_search, DEBUG=1;
	
	// Create array of random values
	int n_data = 20;
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
	mergeSortArray(data_array, n_data);
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
