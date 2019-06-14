#include <stdio.h>
/*  
    Prova LabEstrutura de dados
prof: Fabio Jr
aluno: Caio César

implementação : Encadeaento separado com metodo de multiplicação




             _   _   _____   ______   _   _
            | | | | |  _  | |  ____| | | | |                                    
            | |_| | | |_| | | |____  | |_| |
            |  _  | |  _  | |____  | |  _  |
            | | | | | | | |  ____| | | | | |
            |_| |_| |_| |_| |______| |_| |_|

 infelizmente tanto o | quanto o _ o compilador fala qua são caracteres epeciais    

*/

#include <stdlib.h>
#include "TabelaHash.h"


void verif(int veri){
    if(veri > 0)
        printf("Sucesso\n");
    else
        printf("ERRO !!\n");
}

int main(){
    int tamanho = 100;
    Hashing *tabela = criarTabela(tamanho);
    int i;
    struct num n;
    printf("\n\n------------\n");
    for(i=0; i < tamanho; i++){
        int x = (13118 + rand() % 15323);
        n.numero = x;
        inserirTabela(tabela,n);
        printf("%d\n",n.numero );
    }

    //printf("%d\n",n.numero );
    
    printf("------------\n\n");


    verif(buscarTabela(tabela, 13159, &n));

    liberaTabela(tabela);

    //printf("%d\n",n.numero );// aparece um edereço de lixo de memoria 


    return 0;
}
