#include <stdio.h>
#include <stdlib.h>

struct num{
    int numero;
    struct num *prox;
};

typedef struct tabela Hashing;

Hashing* criarTabela(int tamanho);
void liberaTabela(Hashing* ha);
int inserirTabela(Hashing* ha, struct num n1);
int buscarTabela(Hashing* ha, int mat, struct num* n1);
int funcMultiHash(int chave, int tamanho);

