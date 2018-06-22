/******************************************************************************/
/** Programa desenvolvido por Elisa Rodrigues
/** Atualizado em 20/06/2018
/******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


int main()
{
    Hash *tabela;

    int op, pos, chave, funcao = -1, tam, ender = -1, sond = -1;
    char ok;

    printf("\nDigite o tamanho da tabela (número inteiro primo): ");
    scanf("%d", &tam);

    // inicialização da tabela
    tabela = criarHashing(tam);

    // escolha do método para função hashing
    printf("\nEscolha a função de hashing a ser utilizada:");
    printf("\n1 - Método da Divisão");
    printf("\n2 - Método da Multiplicação");
    printf("\n3 - Método da Dobra");
    printf("\nDigite uma opção: ");

    do{

        scanf("%d", &funcao);

        if(funcao < 1 || funcao > 3){
            printf("\nOpção inválida! Digite novamente.");
        }

    }while(funcao < 1 || funcao > 3);

    // escolha do tipo de endereçamento
    printf("\nEscolha o tipo de endereçamento da tabela hashing:");
    printf("\n1 - Sem Colisão");
    printf("\n2 - Aberto");
    printf("\n3 - Fechado");
    printf("\nDigite uma opção: ");

    do{
        scanf("%d", &ender);

        if(ender < 1 || ender > 3){
            printf("\nOpção inválida! Digite novamente.");
        }

    }while(ender < 1 || ender > 3);

    if(ender == 2){
        printf("\nEscolha o tipo de sondagem: ");
        printf("\n1 - Linear");
        printf("\n2 - Quadrática");
        printf("\n3 - Duplo Hash");
        printf("\nDigite uma opção: ");
        do{
            scanf("%d", &sond);

            if(sond < 1 || sond > 3){
                printf("\nOpção inválida! Digite novamente.");
            }

        }while(sond < 1 || sond > 3);

    }

    printf("\n\nParâmetros: \n Função: %d \n Endereçamento: %d \n Sondagem: %d\n\n", funcao, ender, sond);

    // escolha da operação sobre a tabela hashing
    do{
        printf("\n\n***********************************************");
        printf("\nMENU DE OPÇÕES\n");
        printf("\n1 - Inserir elemento");
        printf("\n2 - Remover elemento");
        printf("\n3 - Buscar elemento");
        printf("\n4 - Mostrar tabela hashing");
        printf("\n5 - Sair");
        printf("\n***********************************************\n");
        printf("\nDigite uma opção: ");

        do{
            scanf("%d", &op);

            if(op < 1 || op > 5){
                printf("\nOpção inválida! Digite novamente.");
            }

        }while(op < 1 || op > 5);

        switch(op){
            case 1:
                do{
                    printf("\nDigite o número inteiro a ser inserido: ");
                    scanf("%d", &chave);

                    pos = inserir(tabela, chave, ender, funcao, sond);

                    if(pos >= 0)
                        printf("Elemento %d inserido com sucesso na posição %d da tabela hashing!", chave, pos);
                    else
                        printf("Ocorreu erro durante a inserção do elemento!");

                    printf("\n\nDeseja inserir outro elemento?(S ou N): ");
                    scanf(" %c", &ok);

                }while(ok == 'S' || ok == 's');

                break;

            case 2:
                printf("\nDigite o número inteiro a ser removido: ");
                scanf("%d", &chave);

                pos = remover(tabela, chave, ender, funcao, sond);

                if(pos >= 0)
                    printf("Elemento %d removido com sucesso da posição %d da tabela hashing!", chave, pos);
                else
                    printf("Ocorreu erro durante a remoção do elemento!");
                break;

            case 3:
                printf("\nDigite o número inteiro a ser buscado: ");
                scanf("%d", &chave);

                pos = buscar(tabela, chave, ender, funcao, sond);

                if(pos >= 0)
                    printf("Elemento %d buscado foi encontrado na posição %d da tabela hashing!", chave, pos);
                else
                    printf("Elemento %d buscado não foi encontrado na tabela hashing!", chave);
                break;

            case 4:
                mostrarTabela(tabela);
                break;
        }

    }while(op != 5);

    // libera memória da tabela hashing
    liberarHashing(tabela);

    return 0;
}
