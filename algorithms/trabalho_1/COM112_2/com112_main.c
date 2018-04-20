#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "com112_sort.h"
#include "com112_file.h"

#define REPORTS_SIZE 3 // Number of sort methods

#include <string.h>

// Headers
void menu(int array_data[], int array_size);
int * generateRandomArray (int array_size);
int * cloneIntArray(int const * src, size_t len);


int main(void) {
  int i, found, value_to_search, DEBUG=0;

  // Create array of random values
  int array_size = 10000;
  int *array_data;
  array_data = generateRandomArray(array_size);
  // for(i=0; i<array_size; i++) array_data[i] = i; // Sequential array
  // for(i=0; i<array_size; i++) array_data[i] = array_size-i; // Inverse sequential array
  saveArrayToFile(array_data, array_size, "com112_entrada.txt");

  // DEBUG Print input
  if(DEBUG) printf("[INPUT]  ");
  for(i=0; i<array_size; i++)
    if(DEBUG) printf("%2d ", array_data[i]);
  
  // menu(array_data, array_size);
  // return 0;

  // DEBUG
  // =================================================
  int moves, iterations;
  float benchmark_time;
  int reports_size = 3;
  struct report_struct reports_array[reports_size-1];

  bubbleSortArray(cloneIntArray(array_data, array_size), array_size, &moves, &iterations, &benchmark_time);
  strcpy(reports_array[0].sortName, "Bubble Sort");
  reports_array[0].moves = moves;
  reports_array[0].iterations = iterations;
  reports_array[0].benchmark_time = benchmark_time;

  selectionSortArray(cloneIntArray(array_data, array_size), array_size, &moves, &iterations, &benchmark_time);
  strcpy(reports_array[1].sortName, "Selection Sort");
  reports_array[1].moves = moves;
  reports_array[1].iterations = iterations;
  reports_array[1].benchmark_time = benchmark_time;

  insertionSortArray(cloneIntArray(array_data, array_size), array_size, &moves, &iterations, &benchmark_time);
  strcpy(reports_array[2].sortName, "Insertion Sort");
  reports_array[2].moves = moves;
  reports_array[2].iterations = iterations;
  reports_array[2].benchmark_time = benchmark_time;

  // Generate report
  relatorio(array_size, "com112_relatorio.txt", reports_array, reports_size);
  // =================================================


  // DEBUG Print sorted array
  if(DEBUG) printf("[OUTPUT] ");
  for(i=0; i<array_size; i++)
    if(DEBUG) printf("%2d ", array_data[i]);

  saveArrayToFile(array_data, array_size, "com112_saida.txt");

  printf("\n... Done!");
  return 0;
  
}

int * cloneIntArray(int const * src, size_t len) {
   int * p = malloc(len * sizeof(int));
   memcpy(p, src, len * sizeof(int));
   return p;
}

void menu(int array_data[], int array_size) {
  int moves, iterations;
  float benchmark_time;
  int reports_size = REPORTS_SIZE;
  struct report_struct reports_array[reports_size-1];

  int n = 5, i;
  int V[n], opcao, n_comp, n_mov;
  
  // Menu
  do{
    // zera as variáveis contadoras
    n_comp = 0;
    n_mov = 0;
    
    // menu de opções
    printf("\n--------------------------------------------------------- \n");
    printf(" Escolha uma opção no menu para ordenação: \n\n");
    printf(" 1. Bubble Sort \n");
    printf(" 2. Selection Sort \n");
    printf(" 3. Insertion Sort \n");
    printf(" 4. Merge Sort \n");
    printf(" 5. Quick Sort \n");
    printf(" 6. Todos os métodos \n");
    printf(" 7. Sair \n\n Opção: ");
    scanf("%i", &opcao);
    printf("--------------------------------------------------------- \n");
    
    if(opcao < 7)
    {        
      // ordena o vetor em ordem crescente
      switch(opcao){
        case 1: // Bubble Sort
                bubbleSortArray(cloneIntArray(array_data, array_size), array_size, &moves, &iterations, &benchmark_time);
                strcpy(reports_array[0].sortName, "Bubble Sort");
                reports_array[0].moves = moves;
                reports_array[0].iterations = iterations;
                reports_array[0].benchmark_time = benchmark_time;
                relatorio(array_size, "com112_relatorio.txt", reports_array, 1);
                break;

        case 2: // Selection Sort
                selectionSortArray(cloneIntArray(array_data, array_size), array_size, &moves, &iterations, &benchmark_time);
                strcpy(reports_array[0].sortName, "Selection Sort");
                reports_array[0].moves = moves;
                reports_array[0].iterations = iterations;
                reports_array[0].benchmark_time = benchmark_time;
                relatorio(array_size, "com112_relatorio.txt", reports_array, 1);
                break;

        case 3: // Insertion Sort
                insertionSortArray(cloneIntArray(array_data, array_size), array_size, &moves, &iterations, &benchmark_time);
                strcpy(reports_array[0].sortName, "Insertion Sort");
                reports_array[0].moves = moves;
                reports_array[0].iterations = iterations;
                reports_array[0].benchmark_time = benchmark_time;
                relatorio(array_size, "com112_relatorio.txt", reports_array, 1);
                break;

        case 4: // Merge Sort
                printf("Not implemented yet...\n");
                break;

        case 5: // Quick Sort
                printf("Not implemented yet...\n");
                break;

        case 6: // All
                bubbleSortArray(cloneIntArray(array_data, array_size), array_size, &moves, &iterations, &benchmark_time);
                strcpy(reports_array[0].sortName, "Bubble Sort");
                reports_array[0].moves = moves;
                reports_array[0].iterations = iterations;
                reports_array[0].benchmark_time = benchmark_time;

                selectionSortArray(cloneIntArray(array_data, array_size), array_size, &moves, &iterations, &benchmark_time);
                strcpy(reports_array[1].sortName, "Selection Sort");
                reports_array[1].moves = moves;
                reports_array[1].iterations = iterations;
                reports_array[1].benchmark_time = benchmark_time;

                insertionSortArray(cloneIntArray(array_data, array_size), array_size, &moves, &iterations, &benchmark_time);
                strcpy(reports_array[2].sortName, "Insertion Sort");
                reports_array[2].moves = moves;
                reports_array[2].iterations = iterations;
                reports_array[2].benchmark_time = benchmark_time;

                relatorio(array_size, "com112_relatorio.txt", reports_array, reports_size);
                break;    
      }
      
    }else{
        // nothing...
    }
    
  }while(opcao < 7);
}

// Generate random array with "array_size" elements
int * generateRandomArray (int array_size) {
	int i;
	srand(time(NULL)); // Random seed based on current time
	
	// Dinamic array
	int *array_data;
	array_data= (int*)malloc(sizeof(int)*array_size);

	// Populating array
	for(i=0; i<array_size; i++) {
		array_data[i] = rand() % 100000;
	}
	
	return array_data;
}