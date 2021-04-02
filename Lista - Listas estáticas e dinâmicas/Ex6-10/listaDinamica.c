#include <stdio.h>
#include <stdlib.h>
#include "listaDinamica.h"

/*------------------------------------------*/
/* Funcoes pedidas nos exercicios de 6 a 10 */
/*------------------------------------------*/

tipoLista geraListaPorVetor(int total, int* vet){

    /* Descobre o tamanho do vetor para o laço for */
    int tam = sizeof(vet)/sizeof(vet[0]);
    int i;

    tipoLista lista;
    iniciaLista(&lista);

    for(i=0; i<tam; i++){
        insereItem(&lista, vet[i]);
    }

    return lista;
}


tipoLista concatenaListas(tipoLista lista1, tipoLista lista2){
    tipoLista listaFinal;
    tipoCelula* atual;
    int i;

    iniciaLista(&listaFinal);

    atual = lista1.inicio;

    /* For que roda duas vezes inserindo os itens, uma vez p/ cada lista */
    for(i=0; i<2; i++){
        do{
            insereItem(&listaFinal, atual->item);
            atual = atual->prox;
        }
        while(atual->prox != NULL);

        atual = lista2.inicio;
    }

    imprimeLista(listaFinal);
    return listaFinal;
}


bool removeRepetidos(tipoLista* lista){
    tipoLista verificadora;
    tipoCelula* atual;
    tipoCelula* repetido;

    repetido = atual = lista->inicio;
    

    /* Cria uma lista para guardar os itens e comparar quais foram repetidos */
    iniciaLista(&verificadora);

    insereItem(&verificadora, atual->item);

    /* Começa a verificacao a partir do 2o item da lista */
    atual = atual->prox;

    do{
        if(existeItem(verificadora, atual->item) == false){
            insereItem(&verificadora, atual->item);
            atual = atual->prox;
        }
        else{
            printf("Item repetido encontrado: %d", atual->item);
            repetido = atual;
            atual = atual->prox;
            removeItemPorPosicao(lista, repetido);
        }
    }while(atual->prox != NULL);

    /* Retorna false se nenhum numero foi excluido */
    if(repetido == lista->inicio) return false;

    else return true;
}

tipoLista intercalaListas(tipoLista lista1, tipoLista lista2){
    tipoLista listaFinal;
    tipoCelula* atual1;
    tipoCelula* atual2;

    iniciaLista(&listaFinal);

    atual1 = &lista1;
    atual2 = &lista2;
    
    /* Insere os itens intercalados até que uma das duas listas acabe */
    do{
        insereItem(&listaFinal, atual1->item);
        insereItem(&listaFinal, atual2->item);
        atual1 = atual1->prox;
        atual2 = atual2->prox;

    }while(atual1->prox != NULL && atual2->prox != NULL);
    
    /* Verifica qual lista acabou e insere o restante dos itens da lista que sobrou */
    if(atual1->prox == NULL){
        do{
            insereItem(&listaFinal, atual2->item);
            atual2 = atual2->prox;
        }while(atual2->prox != NULL);
    }
    else{
        do{
            insereItem(&listaFinal, atual1->item);
            atual1 = atual1->prox;
        }while(atual1->prox != NULL);
    }

    return listaFinal;
}

int somaValoresLista(tipoLista lista){
    tipoCelula* atual;
    int soma;

    atual = &lista.inicio;

    do{
        soma += atual->item;
        atual = atual->prox;
    }while(atual->prox != NULL);

    return soma;
}

/*-----------------------------------------*/
/* Funcoes de controle e manuseio da lista */
/*-----------------------------------------*/

bool iniciaLista(tipoLista* lista){
    tipoCelula* novaCelula;
    novaCelula = (tipoCelula*) malloc(sizeof(tipoCelula));
    lista->inicio = novaCelula;
    lista->fim = novaCelula;

    novaCelula->prox = NULL;

    return true;
}

bool insereItem(tipoLista* lista, int n){
    tipoCelula* novaCelula;
    novaCelula = (tipoCelula*) malloc(sizeof(tipoCelula));
    lista->fim = novaCelula;

    novaCelula->item = n;
    novaCelula->prox = NULL;

    return true;    
}

bool existeItem(tipoLista lista, int alvo){
    tipoCelula* atual;

    atual = lista.inicio;

    while(atual->item != alvo || atual->prox != NULL){
        atual = atual->prox;
    }
    if(atual->item == alvo) return true;

    else return false;
}

bool removeItemPorValor(tipoLista* lista, int n){
    tipoCelula* atual;
    tipoCelula* seguinte;
    tipoCelula* anterior;

    atual = lista->inicio;
    seguinte = atual->prox;

    /* Verifica se eh o primeiro item da lista, se for apenas muda o inicio */
    if(atual->item == n){
        lista->inicio = seguinte;
        free (atual);
        return true;
    }

    anterior = lista->inicio;
    atual = anterior->prox;
    seguinte = atual->prox;

    while(atual->prox != NULL){
        if(atual->item == n){
            
            /* Vê se eh o ultimo item pra adaptar o ptr de fim da lista */
            if(atual->prox == NULL){
                lista->fim = anterior;
            }
            
            anterior->prox = seguinte;
            free(atual);
            return true;
        }
    }
    /* Retorna falso caso nao exista o item buscado */
    return false;
}

bool removeItemPorPosicao(tipoLista* lista, tipoCelula* alvo){
    tipoCelula* atual;

    atual = lista->inicio;

    if(atual == alvo){
        lista->inicio = alvo->prox;
        return true;
    }

    do{
        atual = atual->prox;
    }while(atual->prox != alvo || atual->prox != NULL);

    if(atual->prox == alvo){
        atual->prox = alvo->prox;
        free(alvo);
        return true;
    }
    else return false;
}

void imprimeLista(tipoLista lista){
    tipoCelula* atual;
    printf(" Lista: ");

    do{
        printf("%d ", atual->item);
        atual = atual->prox;
    }
    while(atual != NULL);
}