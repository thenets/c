#include <stdio.h>
#include <stdlib.h>

#include "com112_sort.h"



/*****************************************************************************************/
/** Programa principal                                                                   */
/*****************************************************************************************/
int main(void) {
  
  int n = 5;
  int V[n], i, opcao, n_comp, n_mov;
  
  // menu
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

