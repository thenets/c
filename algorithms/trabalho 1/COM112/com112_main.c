#include <stdio.h>
#include <stdlib.h>
#include "com112_sort.h"

int menu(int opcao){
    int n = 5;
    int V[n], i, n_comp, n_mov;

    if(opcao != 5){
      // carrega os números no vetor
      printf("\nDigite %i números para serem ordenados: \n", n);
      for(i=0;i<n;i++) scanf("%i", &V[i]);

          // ordena o vetor em ordem crescente
        switch(opcao){
            case 1: bubbleSort(V, n, &n_comp, &n_mov);
                    break;
            case 2: insertionSort(V, n, &n_comp, &n_mov);
            break;
        }
        relatorio(V, n, &n_comp, &n_mov);
    }
    else{
        printf("\nFinalizando...\n\n");
        return 0;
    }
}
void relatorio(int *V, int n, int *n_comp, int *n_mov){
    int i;
    // mostra o vetor ordenado
    printf("\n---------------------------------------------------------");
    printf("\n Vetor ordenado: ");
    for(i=0;i<=4;i++)  printf("%i ", V[i]);

    // mostra o número de comparação e movimentações executadas
    printf("\n Tamanho do vetor: %i ", n);
    printf("\n Número de comparações: %i ", n_comp);
    printf("\n Número de movimentações: %i ", n_mov);
    printf("\n---------------------------------------------------------\n\n");
}
main(){
    int opcao;

    printf("\n--------------------------------------------------------- \n");
    printf(" Escolha uma opção no menu para oordenação: \n");
    printf("\n 1. Bubble Sort \n");
    printf(" 2. Insertion Sort \n");
    scanf("%i", &opcao);
    menu(opcao);
}
