#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 100

struct noDinorex{
    int idade;
    char nome[12];
    char raca[12];
    struct noDinorex *prox;
};
 
typedef struct noDinorex Extinto;
 
Extinto* criaLista(){
    Extinto *E;
    E = (Extinto*) calloc(1, sizeof(Extinto));
    return E;
}
 
int Inserir(int idade, char nome[12], Extinto *E){
    Extinto *novo = (Extinto*) malloc(sizeof(Extinto));
    
    novo->idade = idade;
    
    if(E == NULL){
        novo->prox=NULL;
        E = novo;
    }
    else{
        Extinto *aux;
        aux = E;
        printf("Idade inserida na lista: %d \n", idade);
        while(aux->prox != NULL && aux->prox->idade < idade){
            
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    return 1;
}
 
//Remover
int eliminaValor(int valor, char nome[12] ,Extinto *E){
    Extinto* ant = NULL;
    Extinto* p = E;
    
    while (p != NULL && p->idade != valor){
        ant = p;
        p = p->prox;
    }
    
    if( p == NULL) return 0;
    if(ant == NULL) {
        E =p->prox;
        
    }
    else{
        ant->prox = p->prox;
        printf("Valor removido da lista: %d\n", valor);
    }
    free(p);
    return 1;
}
 
//Imprimir
void imprimeExtinto(Extinto *E){
    if(E != NULL){
        Extinto *aux;
        aux = E;
        while(aux->prox != NULL){
            aux = aux->prox;
            printf("Idades na lista: %d\n", aux->idade);
        }
        printf("\n");
    }
    else{
        printf("Lista vazia. \n");
    }
}
 
Extinto* Apagar(Extinto *E){
    Extinto* p = E;
    Extinto* t;
    
    while(p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }
    return p;
}
 
int main(){
    Extinto *E = criaLista();
    
    Inserir(15, "Jos", E);
    Inserir(17, "Sos", E);
    Inserir(8, "Mos", E);
    Inserir(23, "Dos", E);
    Inserir(1, "Wos", E);
    Inserir(05, "Kos", E);
    
    printf("\n");

    imprimeExtinto(E);

    eliminaValor(17, "Jos", E);
    eliminaValor(05, "Jos", E);
    eliminaValor(1, "Jos", E);

    printf("\n");

    imprimeExtinto(E);

    E = Apagar(E);

    imprimeExtinto(E);

 return 0;
}