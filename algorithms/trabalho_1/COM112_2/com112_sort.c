#include <stdio.h>
#include <stdlib.h>

/*****************************************************************************************/
/** Metodo de ordenacao Bubble Sort (ordem crescente)                                    */
/*****************************************************************************************/
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


/*****************************************************************************************/
/** Metodo de ordenacao Bubble Sort melhorado versão 1 (ordem crescente)                 */
/*****************************************************************************************/
void bubbleSort1(int *V, int n, int *n_comp, int *n_mov){

  int aux;
  
  // laço com a quantidade de elementos do vetor - 1
  for(int i=1;i<n;i++)
  {
    // laço que percorre da última posição à posição i do vetor
    for(int j=(n-1);j>=i;j--)
    {
      // acrescenta 1 comparação
      (*n_comp)++; 
      
      if(V[j] < V[j-1]){
        
        // acrescenta 1 movimentação
        (*n_mov)++;
        
        aux = V[j];
        V[j] = V[j-1];
        V[j-1] = aux;
      }
    }
  }
}


/*****************************************************************************************/
/** Metodo de ordenacao Bubble Sort melhorado versão 2 (ordem crescente)                 */
/*****************************************************************************************/
void bubbleSort2(int *V, int n, int *n_comp, int *n_mov){

  int i, aux;
  int houve_troca = 1;
  
  // laço com a quantidade de elementos do vetor e enquanto houver troca
  while(i <= n && houve_troca)
  {
    houve_troca = 0;
    
    // laço que percorre da primeira à penúltima posição do vetor
    for(int j=0;j<(n-1);j++)
    {
      // acrescenta 1 comparação
      (*n_comp)++; 
      
      if(V[j] > V[j+1]){
        
        // sinaliza que houve troca nesta iteração
        houve_troca = 1;
        
         // acrescenta 1 movimentação
        (*n_mov)++;
        
        aux = V[j];
        V[j] = V[j+1];
        V[j+1] = aux;
      }
    }
    i++;
  }
}



/*****************************************************************************************/
/** Metodo de ordenacao Insertion Sort (ordem crescente)                                 */
/*****************************************************************************************/
void insertionSort(int *V, int n, int *n_comp, int *n_mov){

  int eleito, j;  
  
  // laço com a quantidade de elementos do vetor - 1
  for(int i=1;i<n;i++)
  {
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