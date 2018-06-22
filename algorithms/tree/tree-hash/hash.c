/******************************************************************************/
/** As funções desta biblioteca foram implementadas com
/** com base nos códigos apresentados nos livros:
/** - BACKES, A. Estrutura de Dados Descomplicada em Linguagem C
/** - ASCÊNCIO, A. F. et al. Estrutura de Dados
/******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

// Headers
Hash *criarHashing(int tamanho);
void liberarHashing(Hash *h);
int buscar(Hash *tabela, int chave, int ender, int funcao, int sond);
int inserir(Hash *tabela, int chave, int ender, int funcao, int sond);
int remover(Hash *tabela, int chave, int ender, int funcao, int sond);
void mostrarTabela(Hash *tabela);
int converterStringInt(char *str);
int funcaoHashing(int chave, int TABLE_SIZE, int funcao);

int buscarSemColisao(Hash *tabela, int chave, int funcao);
int inserirSemColisao(Hash *tabela, int chave, int funcao);
int removerSemColisao(Hash *tabela, int chave, int funcao);
int buscarEndAberto(Hash *tabela, int chave, int funcao, int sond);
int inserirEndAberto(Hash *tabela, int chave, int funcao, int sond);
int removerEndAberto(Hash *tabela, int chave, int funcao, int sond);
int sondagem(int pos, int chave, int i, int TABLE_SIZE, int sond);
int sondagemLinear(int pos, int i, int TABLE_SIZE);
int sondagemQuadratica(int pos, int i, int TABLE_SIZE);
int duploHash(int H1, int chave, int i, int TABLE_SIZE);
int buscarEndFechado(Hash *tabela, int chave, int funcao);
int inserirEndFechado(Hash *tabela, int chave, int funcao);
int removerEndFechado(Hash *tabela, int chave, int funcao);
int chaveDivisao(int chave, int TABLE_SIZE);
int chaveMultiplicacao(int chave, int TABLE_SIZE);
int chaveDobra(int chave, int TABLE_SIZE);
int converterStringInt(char *str);





/******************************************************************************/
/** Alocação e liberação de memória *******************************************/
/******************************************************************************/

/* Cria tabela hashing */
Hash *criarHashing(int tamanho)
{
    Hash *h;

    h = (Hash*) malloc(tamanho * sizeof(Hash));

    if(h != NULL){
        h->itens = (int**) malloc(tamanho * sizeof(int*));

        if(h->itens == NULL){
            printf("\nMemória insuficiente!");
            free(h);
            return NULL;
        }

        h->TABLE_SIZE = tamanho;
        h->qtd = 0;

        for(int i=0; i<tamanho; i++){
            h->itens[i] = NULL;
        }
    }

    return h;
}

/* libera memória da tabela hashing */
void liberarHashing(Hash *h)
{
    if(h != NULL){
        for(int i=0; i<h->TABLE_SIZE; i++){
            if(h->itens[i] != NULL){
                free(h->itens[i]);
            }
            free(h->itens);
            free(h);
        }
    }
}

/******************************************************************************/
/** Operações sobre a tabela hashing ******************************************/
/******************************************************************************/

/* buscar um elemento na tabela hashing */
int buscar(Hash *tabela, int chave, int ender, int funcao, int sond)
{
    switch(ender){
        case 1:
            return buscarSemColisao(tabela, chave, funcao);

        case 2:
            return buscarEndAberto(tabela, chave, funcao, sond);

        case 3:
            return buscarEndFechado(tabela, chave, funcao);
    }
}

/* inserir um elemento na tabela hashing */
int inserir(Hash *tabela, int chave, int ender, int funcao, int sond)
{
    switch(ender){
       case 1:
            return inserirSemColisao(tabela, chave, funcao);

       case 2:
            return inserirEndAberto(tabela, chave, funcao, sond);

       case 3:
            return inserirEndFechado(tabela, chave, funcao);
    }
}

/* remover um elemento da tabela hashing */
int remover(Hash *tabela, int chave, int ender, int funcao, int sond)
{
    switch(ender){
        case 1:
            return removerSemColisao(tabela, chave, funcao);

        case 2:
            return removerEndAberto(tabela, chave, funcao, sond);

        case 3:
            return removerEndFechado(tabela, chave, funcao);
    }
}

/* exibir toda a tabela hashing */
void mostrarTabela(Hash *tabela)
{
    if(tabela != NULL || tabela->qtd == 0)
        for(int i=0; i<tabela->TABLE_SIZE; i++)
            printf("%d ", tabela->itens[i]);

    else
        printf("Tabela vazia!");
}

/******************************************************************************/
/** Operações para hashing sem colisão ***************************************/
/******************************************************************************/

/* Função busca chave na tabela hashing e retorna posição na tabela em caso de sucesso*/
int buscarSemColisao(Hash *tabela, int chave, int funcao)
{
    if(tabela == NULL)
        return -1;

    int pos = funcaoHashing(chave, tabela->TABLE_SIZE, funcao);

    if(tabela->itens[pos] == NULL)
        return -1;

    if((int)tabela->itens[pos] == (int)chave)
        return pos;

    return -1;
}

/* Função insere a chave nova na tabela hashing e retorna 1 em caso de sucesso*/
int inserirSemColisao(Hash *tabela, int chave, int funcao)
{
    if(tabela == NULL || tabela->qtd == tabela->TABLE_SIZE)
        return -1;

    int pos = funcaoHashing(chave, tabela->TABLE_SIZE, funcao);

    tabela->itens[pos] = chave;
    tabela->qtd++;

    return pos;
}

int removerSemColisao(Hash *tabela, int chave, int funcao)
{
    int pos = buscarSemColisao(tabela, chave, funcao);

    if(pos >= 0)
        tabela->itens[pos] = NULL;

    return pos;
}


/******************************************************************************/
/** Operações para endereçamento aberto ***************************************/
/******************************************************************************/

int buscarEndAberto(Hash *tabela, int chave, int funcao, int sond)
{
    if(tabela == NULL)
        return -1;

    int pos = funcaoHashing(chave, tabela->TABLE_SIZE, funcao);
    int nova_pos;

    for(int i=0; i<tabela->TABLE_SIZE; i++){

        nova_pos = sondagem(pos, chave, i, tabela->TABLE_SIZE, sond);

        if(tabela->itens[nova_pos] == NULL)
            return -1;

        if(tabela->itens[nova_pos] == chave)
            return nova_pos;

    }

    return -1;
}

int inserirEndAberto(Hash *tabela, int chave, int funcao, int sond)
{
    if(tabela == NULL || tabela->qtd == tabela->TABLE_SIZE)
        return -1;

    int pos = funcaoHashing(chave, tabela->TABLE_SIZE, funcao);
    int nova_pos;

    for(int i=0; i<tabela->TABLE_SIZE; i++){

        nova_pos = sondagem(pos, chave, i, tabela->TABLE_SIZE, sond);

        if(tabela->itens[nova_pos] == NULL)
        {
            tabela->itens[nova_pos] = chave;
            tabela->qtd++;

            return nova_pos;
        }
    }

    return -1;
}

int removerEndAberto(Hash *tabela, int chave, int funcao, int sond)
{
    int pos = buscarEndAberto(tabela, chave, funcao, sond);

    if(pos >= 0)
        tabela->itens[pos] = NULL;

    return pos;
}

/** Tratamento de colisões para endereçamento aberto **************************/

int sondagem(int pos, int chave, int i, int TABLE_SIZE, int sond)
{
    switch(sond){
        case 1:
            return sondagemLinear(pos, i, TABLE_SIZE);

        case 2:
            return sondagemQuadratica(pos, i, TABLE_SIZE);

        case 3:
            return duploHash(pos, chave, i, TABLE_SIZE);
    }
}

int sondagemLinear(int pos, int i, int TABLE_SIZE)
{
    return (pos + i) % TABLE_SIZE;
}

int sondagemQuadratica(int pos, int i, int TABLE_SIZE)
{
    pos = pos + 2*i + 5*i*i;

    return pos % TABLE_SIZE;
}

int duploHash(int H1, int chave, int i, int TABLE_SIZE)
{
    int H2 = chaveDivisao(chave, TABLE_SIZE-1) + 1;

    return (H1 + i*H2) % TABLE_SIZE;
}



/******************************************************************************/
/** Operações para endereçamento fechado ***************************************/
/******************************************************************************/

int buscarEndFechado(Hash *tabela, int chave, int funcao)
{
    return -1;
}

int inserirEndFechado(Hash *tabela, int chave, int funcao)
{
    return -1;
}

int removerEndFechado(Hash *tabela, int chave, int funcao)
{
    return -1;
}




/******************************************************************************/
/** Funções de hashing ********************************************************/
/******************************************************************************/

/* Escolhe a função de hashing de acordo com o parâmetro função */
int funcaoHashing(int chave, int TABLE_SIZE, int funcao)
{
    switch(funcao){
        case 1:
            return chaveDivisao(chave, TABLE_SIZE);

        case 2:
            return chaveMultiplicacao(chave, TABLE_SIZE);

        case 3:
            return chaveDobra(chave, TABLE_SIZE);
    }
}


/* Método da Divisão: calcula o resto da divisão entre a chave e o tamanho da tabela */
int chaveDivisao(int chave, int TABLE_SIZE)
{
    return chave % TABLE_SIZE;
}

/* Método da Multiplicação: multiplica a chave por uma constante A, onde 0 < A < 1,
   a parte fracionária do resultado é multiplicada pelo tamanho da tabela,
   e a posição será a parte inteira do resultado */
int chaveMultiplicacao(int chave, int TABLE_SIZE)
{
    float A = 0.6180339887;
    float val = chave * A;
    val = val - (int) val;

    return (int) (TABLE_SIZE * val);
}

/* Método da dobra */
int chaveDobra(int chave, int TABLE_SIZE)
{
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (TABLE_SIZE - 1);

    return (parte1 ^ parte2);
}

/* Converte uma string para um inteiro, que é inserido na tabela hashing como chave */
int converterStringInt(char *str)
{
    int valor = 7;
    int tam = strlen(str);
    for(int i=0; i<tam; i++){
        valor = 31 * valor + (int)str[i];
    }

    return valor;
}
