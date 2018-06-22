/******************************************************************************/
/** As funções desta biblioteca foram implementadas com
/** com base nos códigos apresentados nos livros:
/** - BACKES, A. Estrutura de Dados Descomplicada em Linguagem C
/** - ASCÊNCIO, A. F. et al. Estrutura de Dados
/******************************************************************************/

#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

    typedef struct hash Hash;

    struct hash{
        int *itens;
        int qtd;
        int TABLE_SIZE;
    };

    Hash *criarHashing(int tamanho);
    void liberarHashing(Hash *h);

    int buscar(Hash *tabela, int chave, int ender, int funcao, int sond);
    int inserir(Hash *tabela, int chave, int ender, int funcao, int sond);
    int remover(Hash *tabela, int chave, int ender, int funcao, int sond);

    void mostrarTabela(Hash *tabela);

    int converterStringInt(char *str);

    // funçoes de hashing
    int funcaoHashing(int chave, int TABLE_SIZE, int funcao);



#endif // HASH_H_INCLUDED
