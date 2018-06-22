/******************************************************************************/
/** As funções desta biblioteca foram implementadas com
/** com base nos códigos apresentados nos livros:
/** - BACKES, A. Estrutura de Dados Descomplicada em Linguagem C
/** - ASCÊNCIO, A. F. et al. Estrutura de Dados
/******************************************************************************/

struct myHash{
    int **itens;
    int qtd;
    int TABLE_SIZE;
};

typedef struct myHash Hash;

Hash *criarHashing(int tamanho);
void liberarHashing(Hash *h);

int buscar(Hash *tabela, int chave, int ender, int funcao, int sond);
int inserir(Hash *tabela, int chave, int ender, int funcao, int sond);
int remover(Hash *tabela, int chave, int ender, int funcao, int sond);

void mostrarTabela(Hash *tabela);

int converterStringInt(char *str);

// funçoes de hashing
int funcaoHashing(int chave, int TABLE_SIZE, int funcao);


