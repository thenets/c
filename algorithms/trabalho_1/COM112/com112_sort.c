#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Selection sort
//
// How it works:
//  - Check if i[1] is lower than i[0],   switch if is true
//  - Check if i[2] is lower than i[1],   switch if is true
//  - Check if i[3] is lower than i[2],   switch if is true
//  - Check if i[4] is lower than i[3],   switch if is true
//  - Check if i[n] is lower than i[n-1], switch if is true
void bubbleSortArray (int array_data[], int array_size, int *moves, int *iterations, float *benchmark_time) {
	int i, j, higher, tmp, hasMove;
	int nIterations=0;
	int nMoves=0;
	
	int DEBUG=0;
	
	higher = array_data[0];

	// Start benchmark
	float startTime, endTime, timeElapsed;
	startTime = (float)clock()/CLOCKS_PER_SEC;
	
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

	// Finish benchmark
	endTime = (float)clock()/CLOCKS_PER_SEC;
	timeElapsed = endTime - startTime;
	
	// DEBUG
	if(DEBUG) printf("\nHigher     : %d", array_data[array_size-1]);
	if(DEBUG) printf("\nIterations : %d", nIterations);
	if(DEBUG) printf("\nMoves      : %d", nMoves);

	// Returning data by reference
	*moves = nMoves;
	*iterations = nIterations;
	*benchmark_time = timeElapsed;
}




// Insertion sort
//
// How it works:
//  - Check first 	element and move it to the left ordenated position
//  - Check second 	element and move it to the left ordenated position
//  - Check third 	element and move it to the left ordenated position
//  - Check N 		element and move it to the left ordenated position
void insertionSortArray (int array_data[], int array_size, int *moves, int *iterations, float *benchmark_time) {
	int i, j, correctPosition, tmp;
	int nIterations=0;
	int nMoves=0;
	
	int DEBUG=0;

	// Start benchmark
	float startTime, endTime, timeElapsed;
	startTime = (float)clock()/CLOCKS_PER_SEC;
	
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

	// Finish benchmark
	endTime = (float)clock()/CLOCKS_PER_SEC;
	timeElapsed = endTime - startTime;
	
	// DEBUG
	if(DEBUG) printf("\nHigher     : %d", array_data[array_size-1]);
	if(DEBUG) printf("\nIterations : %d", nIterations);
	if(DEBUG) printf("\nMoves      : %d", nMoves);

	// Returning data by reference
	*moves = nMoves;
	*iterations = nIterations;
	*benchmark_time = timeElapsed;
}


// Selection sort
//
// How it works:
//  - Find the higher value and send it to the final
//  - Find the 2nd higher value and send it to the final-1
//  - Find the N higher value and send it to the final-N
void selectionSortArray (int array_data[], int array_size, int *moves, int *iterations, float *benchmark_time) {
	int i, j, higher, tmp;
	int nIterations=0;
	int nMoves=0;
	
	int DEBUG=0;

	higher = array_data[0];

	// Start benchmark
	float startTime, endTime, timeElapsed;
	startTime = (float)clock()/CLOCKS_PER_SEC;
	
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

	// Finish benchmark
	endTime = (float)clock()/CLOCKS_PER_SEC;
	timeElapsed = endTime - startTime;
	
	// DEBUG
	if(DEBUG) printf("\nHigher     : %d", array_data[array_size-1]);
	if(DEBUG) printf("\nIterations : %d", nIterations);
	if(DEBUG) printf("\nMoves      : %d", nMoves);

	// Returning data by reference
	*moves = nMoves;
	*iterations = nIterations;
	*benchmark_time = timeElapsed;
}


void merge(int V[], int inicio, int fim, int meio, int *n_comp, int *n_mov){

  int poslivre, inicio1, inicio2, i;
  int aux[fim+1];
  
  inicio1 = inicio;
  inicio2 = meio + 1;
  poslivre = inicio;
  
  while(inicio1 <= meio && inicio2 <= fim)
  { 
    // acrescenta 1 comparação
    (*n_comp)++; 
    
    if(V[inicio1] <= V[inicio2])
    {
      aux[poslivre] = V[inicio1];
      inicio1++;
      
    }else
    {
      aux[poslivre] = V[inicio2];
      inicio2++;
    }
    
    poslivre++;
  }

  for(i=inicio1; i<=meio; i++)
  {
    aux[poslivre] = V[i];
    poslivre++;
  }
  
  for(i=inicio2; i<=fim; i++)
  {
    aux[poslivre] = V[i];
    poslivre++;
  }  
  
  for(i=inicio; i<=fim; i++)
  {
    (*n_mov)++; 
    
    V[i] = aux[i];
  }  
      
}

void mergeSort(int V[], int inicio, int fim, int *n_comp, int *n_mov){
  
  int meio;
  
  if(inicio < fim){
    meio = (inicio + fim) / 2;
    mergeSort(V, inicio, meio, n_comp, n_mov);
    mergeSort(V, meio+1, fim, n_comp, n_mov);
    merge(V, inicio, fim, meio, n_comp, n_mov);
  }
  
}
void mergeSortArray (int array_data[], int array_size, int *moves, int *iterations, float *benchmark_time) {
	// Start benchmark
	float startTime, endTime, timeElapsed;
	startTime = (float)clock()/CLOCKS_PER_SEC;
	
	int *c = malloc(sizeof(int) * array_size);
	mergeSort(array_data, 0, array_size, iterations, moves);
	free(c);

	// Finish benchmark
	endTime = (float)clock()/CLOCKS_PER_SEC;
	timeElapsed = endTime - startTime;

	// Returning data by reference
	// *moves = nMoves;
	*benchmark_time = timeElapsed;
}


// Quick sort
int particiona (int V[], int p, int r, int *n_comp, int *n_mov){
	  int pivo, i, j;
	  pivo = V[(p+r)/2];
	  i = p - 1;
	  j = r + 1;
	   
	  while(i < j)
	  { 
	    
	    do
	    {
	      j--;
	      
	      
	      (*n_comp)++;
	      
	    }while(V[j] > pivo);
	    
	  
	    do
	    {
	      i++;
	    
	      (*n_comp)++;
	      
	    }while(V[i] < pivo);   
	  
	    if(i < j)
	    {
	      int aux;
	      aux = V[i];
	      V[i] = V[j];
	      V[j] = aux;
	      
	      (*n_mov)++; 
	    }
	  }
	  return j;
}
void quicksort(int vet[],int inicio, int fim, int *n_comp, int *n_mov){
    int meio;
    if(inicio < fim){
        meio = particiona(vet,inicio,fim, n_comp, n_mov);
        quicksort(vet,inicio,meio-1, n_comp, n_mov);
      	quicksort(vet,meio+1,fim, n_comp, n_mov);
    }
}
void quickSortArray (int array_data[], int array_size, int *moves, int *iterations, float *benchmark_time) {
	// Start benchmark
	float startTime, endTime, timeElapsed;
	startTime = (float)clock()/CLOCKS_PER_SEC;
	
	(*moves) = 0;
	(*iterations) = 0;
	quicksort(array_data, 0, array_size, iterations, moves);

	// Finish benchmark
	endTime = (float)clock()/CLOCKS_PER_SEC;
	timeElapsed = endTime - startTime;

	// Returning data by reference
	*benchmark_time = timeElapsed;
}