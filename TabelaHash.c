
#include <stdio.h>
#include <stdlib.h>
#include "TabelaHash.h" 

struct tabela{
    int quant, tamanho;//quantidade de elementos adcionado na tabela e o tamanho dela
    struct num **dado;
};

Hashing* criarTabela(int tamanho){
    Hashing* ha = (Hashing*) malloc(sizeof(Hashing));
    if(ha != NULL){
        int i;
        ha->tamanho = tamanho;
        ha->dado = (struct num**) malloc(tamanho * sizeof(struct num*));
        if(ha->dado == NULL){
            free(ha);
            return NULL;
        }
        ha->quant = 0;
        for(i=0; i < ha->tamanho; i++)
            ha->dado[i] = NULL;
    }
    return ha;
}

void liberaTabela(Hashing* ha){
    if(ha != NULL){
        int i;
        for(i=0; i < ha->tamanho; i++){
            if(ha->dado[i] != NULL)
                free(ha->dado[i]);
        }
        free(ha->dado);
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
    else if (ha->dado[pos] != NULL){// caso ja esteja ocupando espaço
        *novo = n1;
        ha->dado[pos]->prox = novo;
        ha->quant++;
    }
    else{
        *novo = n1;
        ha->dado[pos] = novo;
        ha->quant++;   
    }
    return 1;
}


int buscarTabela(Hashing* ha, int numero, struct num* n1){
    if(ha == NULL)
        return 0;

    int pos = funcMultiHash(numero,ha->tamanho);
    if(ha->dado[pos] == NULL)
        return 0;
    else if (ha->dado[pos] != NULL && ha->dado[pos]->numero != numero){// caso aja mais de um elemento 
        
        if(ha->dado[pos]->prox->numero != numero)
            return 0;
        else
            return 1;
    }
    else{
        if(ha->dado[pos]->numero != numero)
            return 0;
        else
            return 1;
    }
}
