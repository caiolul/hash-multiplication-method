
#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h" 

struct tabela{
    int quant, tamanho;//quantidade de elementos adcionado na tabela e o tamanho dela
    struct num **itens;
};

Hashing* criarTabela(int tamanho){
    Hashing* ha = (Hashing*) malloc(sizeof(Hashing));
    if(ha != NULL){
        int i;
        ha->tamanho = tamanho;
        ha->itens = (struct num**) malloc(tamanho * sizeof(struct num*));
        if(ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->quant = 0;
        for(i=0; i < ha->tamanho; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}

void liberaTabela(Hashing* ha){
    if(ha != NULL){
        int i;
        for(i=0; i < ha->tamanho; i++){
            if(ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}
int funcMultiHash(int chave, int tamanho){
    double conts = rand() % 1; // valor entre 0 e 1
    double val = chave * conts;// conts não é alterada com a recompilação do codigo
    val = val - (int) val;
    return (int) (tamanho * val);//tranforma em inteiro
}

int inserirTabela(Hashing* ha, struct num n1){
    if(ha == NULL || ha->quant == ha->tamanho)
        return 0;

    int chave = n1.numero;

    int pos = funcMultiHash(chave,ha->tamanho);
    struct num* novo;
    novo = (struct num*) malloc(sizeof(struct num));
    if(novo == NULL)
        return 0;
    else if (ha->itens[pos] != NULL){// caso ja esteja ocupando espaço
        *novo = n1;
        ha->itens[pos]->prox = novo;
        ha->quant++;
    }
    else{
        *novo = n1;
        ha->itens[pos] = novo;
        ha->quant++;   
    }
    return 1;
}


int buscarTabela(Hashing* ha, int mat, struct num* n1){
    if(ha == NULL)
        return 0;

    int pos = funcMultiHash(mat,ha->tamanho);
    if(ha->itens[pos] == NULL)
        return 0;
    else if (ha->itens[pos] != NULL)// caso aja mais de um elemento 
        *n1 = *(ha->itens[pos]->prox);
    else
        *n1 = *(ha->itens[pos]);
    return 1;
}
