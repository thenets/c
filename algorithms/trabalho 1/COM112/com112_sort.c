#include "com112_sort.h"


void bubbleSort(int *V, int n, int *n_comp, int *n_mov){

  int aux;

  // laço com a quantidade de elementos do vetor
  for(int i=0;i<n;i++)
  {
    // laço que percorre da primeira à penúltima posição do vetor
    for(int j=0;j<(n-1);j++)
    {
      // acrescenta 1 comparação
      (*n_comp)++;

      if(V[j] > V[j+1]){

        // acrescenta 1 movimentação
        (*n_mov)++;

        aux = V[j];
        V[j] = V[j+1];
        V[j+1] = aux;
      }
    }
  }
}

void insertionSort(int *V, int n, int *n_comp, int *n_mov){

  int eleito, j;

  // laço com a quantidade de elementos do vetor - 1
  for(int i=1;i<n;i++){
    eleito = V[i];
    j = i - 1;

    // acrescenta 1 comparação
    (*n_comp)++;

    // laço que percorre os elementos à esquerda do número eleito ou até encontrar a posição para recolocação do eleito em ordem crescente
    while(j >= 0 && V[j] > eleito)
    {
      // acrescenta 1 comparação
      (*n_comp)++;

      // acrescenta 1 comparação
      (*n_mov)++;

      V[j+1] = V[j];
      j--;
    }

    V[j+1] = eleito;
  }
}
