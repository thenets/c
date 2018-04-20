#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "com112_sort.h"
#include "com112_file.h"

#define REPORTS_SIZE 3 // Number of sort methods

#include <string.h>

// Headers
int * generateRandomArray (int array_size);


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
                bubbleSortArray(array_data, array_size, &moves, &iterations, &benchmark_time);
                strcpy(reports_array[0].sortName, "Bubble Sort");
                reports_array[0].moves = moves;
                reports_array[0].iterations = iterations;
                reports_array[0].benchmark_time = benchmark_time;
                relatorio(array_size, "com112_relatorio.txt", reports_array, 1);
                break;

        case 2: // Selection Sort
                selectionSortArray(array_data, array_size, &moves, &iterations, &benchmark_time);
                strcpy(reports_array[0].sortName, "Selection Sort");
                reports_array[0].moves = moves;
                reports_array[0].iterations = iterations;
                reports_array[0].benchmark_time = benchmark_time;
                relatorio(array_size, "com112_relatorio.txt", reports_array, 1);
                break;

        case 3: // Insertion Sort
                insertionSortArray(array_data, array_size, &moves, &iterations, &benchmark_time);
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
                bubbleSortArray(array_data, array_size, &moves, &iterations, &benchmark_time);
                strcpy(reports_array[0].sortName, "Bubble Sort");
                reports_array[0].moves = moves;
                reports_array[0].iterations = iterations;
                reports_array[0].benchmark_time = benchmark_time;

                selectionSortArray(array_data, array_size, &moves, &iterations, &benchmark_time);
                strcpy(reports_array[1].sortName, "Selection Sort");
                reports_array[1].moves = moves;
                reports_array[1].iterations = iterations;
                reports_array[1].benchmark_time = benchmark_time;

                insertionSortArray(array_data, array_size, &moves, &iterations, &benchmark_time);
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

  
  menu(data_array, n_data);
  return 0;

  // Sort
  // =================================================
  int moves, iterations;
  float benchmark_time;
  int reports_size = 3;
  struct report_struct reports_array[reports_size-1];

  bubbleSortArray(data_array, n_data, &moves, &iterations, &benchmark_time);
  strcpy(reports_array[0].sortName, "Bubble Sort");
  reports_array[0].moves = moves;
  reports_array[0].iterations = iterations;
  reports_array[0].benchmark_time = benchmark_time;

  selectionSortArray(data_array, n_data, &moves, &iterations, &benchmark_time);
  strcpy(reports_array[1].sortName, "Selection Sort");
  reports_array[1].moves = moves;
  reports_array[1].iterations = iterations;
  reports_array[1].benchmark_time = benchmark_time;

  insertionSortArray(data_array, n_data, &moves, &iterations, &benchmark_time);
  strcpy(reports_array[2].sortName, "Insertion Sort");
  reports_array[2].moves = moves;
  reports_array[2].iterations = iterations;
  reports_array[2].benchmark_time = benchmark_time;

  // Generate report
  relatorio(n_data, "com112_relatorio.txt", reports_array, reports_size);
  // =================================================


  // DEBUG Print sorted array
  if(DEBUG) printf("[OUTPUT] ");
  for(i=0; i<n_data; i++)
    if(DEBUG) printf("%2d ", data_array[i]);

  saveArrayToFile(data_array, n_data, "com112_saida.txt");

  printf("\n... Done!");
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