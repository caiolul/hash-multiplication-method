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
void menu(){
    printf(" ----------------------\n");
    printf("/     Tabela Hash     /\n");
    printf("----------------------\n");

}

int main(){
    menu();
    int tamanho, valorBusca,op = 1;
    printf("Digite o tamanho:\n");
    scanf("%d",&tamanho);

    Hashing *tabela = criarTabela(tamanho);
    int i;
    struct num n;
    printf("\n\n------------\n");
    for(i=0; i < tamanho; i++){
        int x = (13118 + rand() % 15323);// valores aleatoris entre 13118 e 15323
        n.numero = x;
        inserirTabela(tabela,n);// inserção randomica
        printf("%d\n",n.numero );
    }
    printf("------------\n\n");
    while(op != 0){
        printf("Digite qual valor deses buscar: \n");
        scanf("%d",&valorBusca);
        verif(buscarTabela(tabela, valorBusca, &n));
        printf("Continuar buscando ? 0 sair 1 continua\n");
        scanf("%d",&op);
    }

    liberaTabela(tabela);

    //printf("%d\n",n.numero );// aparece um edereço de lixo de memoria 

    system("pause");
    return 0;
}
