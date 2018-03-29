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


// Busca um elemento do vetor e retorna a posição dele
// Se não encontrar, return -1
int searchInArray (int array_data[], int array_size, int value_to_search) {
	int i;
	
	for (i=0; i<array_size; i++) {
		if(value_to_search == array_data[i]) {
			return i;
		}
	}
	
	// printf("%d \n", i);
	
	return -1;
}

int main () {
	int i, found, value_to_search;
	
	// Create array of random values
	int n_data = 30000;
	int *data_array;
	data_array = generateRandomArray(n_data);
	
	// DEBUG
	for(i=0; i<n_data; i++) {
//		printf("%d ", data_array[i]);
	}
	printf("\n");
	
	// Search for value in array
	value_to_search = 22;
	found = searchInArray(data_array, n_data, value_to_search);
	if(found == -1) {
		printf("Valor %d nao encontrado!", value_to_search);
	} else {
		printf("Valor %d encontrado na posicao %d", value_to_search, found);		
	}
	
	
	
	//	printf("oi");
	
	return 0;
}

