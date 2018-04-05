# Merge Sort

* Algoritmo de ordenação por intercalação
* Usa técnina divisão e conquista
* Algoritmo recursivo
* 3 passos em cada nível de recursão
  - dividir: divide o problema em subproblemas
  - Conquistar: Soluciona recursivamente os subproblemas (até o menor subproblemas - caso Base)
  - Combinar:DIvisão combina a solução dos subproblemas para resolver o problema original

* Divisão e conquista aplicada ao Merge Sort
  - Dividir: divide o vetor original de tamanho n em dois subproblemas de tamanho n/2
  - Conquistar: ordenar os subvalores recursivamente
  - Combinar: intercalar os dois subvalores ordenada de forma a ordenar o valor original

* Algoritmo Merge Sort
  ```
  mergeSort(x, inicio, fim) -> função recursivamente

  ```

  ```
  mergeSort(x, inicio, fim, meio) -> função que ordena(intercala)

  ```

* Função mergeSort()
  - dividir o vetor em dois (abstrato)
  - armazenar: inicio e fim (indices do vetor)
  - calcular o meio ()(inicio+fim)/ meio
  - condição de parada da recursão inicio=fim (n=1)
  { 1º subvetor: inicio até meio; 2º subvertor: meio até o fim }

* função merge()
  * 1º subvetor está ordenado
  * 2º subvetor está ordenado
  * intercala os elementos dos 2 subvetores até o vetor original estão ordenados
    - armazena: inicio, fim e meio
    - obter: inicio e inicio2 (indice vão percorrer os subvetores)
    - armazenar os elementos ordenados = aux[]
      - positivo: (indice que percorre o aux[])

  ```
      void mergeSort(x inicio, fim){

        int meio;

        if(inicio < fim){
          meio = (inicio + fim)/2;
          mergeSort(x, inicio, meio);
          mergeSort(x, meio+1, fim);
          merge(x, inicio, fim, meio);
        }
      }

  ```
