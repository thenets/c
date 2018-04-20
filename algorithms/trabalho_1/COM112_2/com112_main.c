#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "com112_sort.h"
#include "com112_file.h"

// Headers
int * generateRandomArray (int array_size);


int main(void) {
  int i, found, value_to_search, DEBUG=0;

  // Create array of random values
  int n_data = 10000;
  int *data_array;
  data_array = generateRandomArray(n_data);
  // for(i=0; i<n_data; i++) data_array[i] = i; // Sequential array
  // for(i=0; i<n_data; i++) data_array[i] = n_data-i; // Inverse sequential array
  saveArrayToFile(data_array, n_data, "com112_entrada.txt");

  // DEBUG Print input
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

  // DEBUG Print sorted array
  if(DEBUG) printf("[OUTPUT] ");
  for(i=0; i<n_data; i++)
    if(DEBUG) printf("%2d ", data_array[i]);

  saveArrayToFile(data_array, n_data, "com112_saida.txt");
  exit(0);

  return 0;
  
  
  int n = 5;
  int V[n], opcao, n_comp, n_mov;
  
  // Menu
  do{
    // zera as variáveis contadoras
    n_comp = 0;
    n_mov = 0;
    
    // menu de opções
    printf("\n--------------------------------------------------------- \n");
    printf(" Escolha uma opção no menu para ordenação: \n");
    printf("\n 1. Bubble Sort \n");
    printf(" 2. Bubble Sort Melhorado Versão 1 \n");
    printf(" 3. Bubble Sort Melhorado Versão 2 \n");
    printf(" 4. Insertion Sort \n");
    printf(" 5. Sair \n\n Opção: ");
    scanf("%i", &opcao);
    printf("--------------------------------------------------------- \n");
    
    if(opcao != 5)
    {  
      // carrega os números no vetor
      printf("\nDigite %i números para serem ordenados: \n", n);
      for(i=0;i<n;i++) scanf("%i", &V[i]);
      
      // ordena o vetor em ordem crescente
      switch(opcao){
        case 1: bubbleSort(V, n, &n_comp, &n_mov);
                break;
        case 2: bubbleSort1(V, n, &n_comp, &n_mov);
                break;   
        case 3: bubbleSort2(V, n, &n_comp, &n_mov);
                break; 
        case 4: insertionSort(V, n, &n_comp, &n_mov);
                break;    
      }
      
      // mostra o vetor ordenado
      printf("\n---------------------------------------------------------");
      printf("\n Vetor ordenado: ");
      for(i=0;i<=4;i++)  printf("%i ", V[i]);
      
      // mostra o número de comparação e movimentações executadas
      printf("\n Tamanho do vetor: %i ", n);
      printf("\n Número de comparações: %i ", n_comp);
      printf("\n Número de movimentações: %i ", n_mov);
      printf("\n---------------------------------------------------------\n\n");
   
    }else{
        printf("\nFinalizando...\n\n");
    }
    
  }while(opcao != 5);
  
  return 0;
  
}



// Generate random array with "array_size" elements
int * generateRandomArray (int array_size) {
	int i;
	srand(time(NULL)); // Random seed based on current time
	
	// Dinamic array
	int *data_array;
	data_array= (int*)malloc(sizeof(int)*array_size);

	// Populating array
	for(i=0; i<array_size; i++) {
		data_array[i] = rand() % 100000;
	}
	
	return data_array;
}