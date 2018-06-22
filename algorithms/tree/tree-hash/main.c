#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


int main()
{
    Hash *tabela;

    int op, pos, chave, funcao = -1, tam, ender = -1, sond = -1;
    char ok;

    // inicialização da tabela
    tam = 31;
    tam = 11;
    tabela = criarHashing(tam);
    funcao = 2;
    ender = 1; // O '3' é o 'Fechado'
    // ender = 3;
    printf("\n\nParâmetros: \n Função: %d \n Endereçamento: %d \n Sondagem: %d\n\n", funcao, ender, sond);

    // Data insert example
    pos = inserir(tabela, 32, ender, funcao, sond);
    pos = inserir(tabela, 31, ender, funcao, sond);
    pos = inserir(tabela, 31, ender, funcao, sond);
    pos = inserir(tabela, 39, ender, funcao, sond);
    pos = inserir(tabela, 12, ender, funcao, sond);
    pos = inserir(tabela, 11, ender, funcao, sond);
    pos = remover(tabela, 32, ender, funcao, sond);
    // pos = buscar(tabela, chave, ender, funcao, sond);
    printf("output: ");
    mostrarTabela(tabela);
    printf("\n\n");

    // libera memória da tabela hashing
    //liberarHashing(tabela);

    return 0;
}
