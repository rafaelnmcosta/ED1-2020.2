#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "Exercicio5.h"

/*--------------------------------*/
/* Funcoes pedidas nos exercicios */
/*--------------------------------*/

int contaAvioes(TipoFilaAvioes fila){
    TipoAviao *atual;
    int tamanho = 0;

    atual = fila.inicio;

    while(atual != NULL){
        tamanho++;
        atual = atual->prox;
    }

    return tamanho;
}

bool liberaAviao(TipoFilaAvioes* fila){

    if(vaziaDinamica(*fila) == true) return false;

    TipoAviao* aux;
    int valor;

    aux = fila->inicio;
    fila->inicio = aux->prox;

    free(aux);
    return true;
}

bool insereAviao(TipoFilaAvioes* fila, TipoAviao aviao){
    TipoAviao *novoAviao;
    TipoAviao *aux;

    novoAviao = (TipoAviao*) malloc(sizeof(TipoAviao));

    aux = fila->final;
    aux->prox = novoAviao;

    novoAviao->id = aviao.id;
    strcpy(novoAviao->nome, aviao.nome);
    strcpy(novoAviao->caracteristicas, aviao.caracteristicas);
    novoAviao->prox = NULL;

    fila->final = novoAviao;

    return true;
}

void listaAvioes(TipoFilaAvioes fila){
    TipoAviao *atual;

    atual = fila.inicio;
    printf("Avioes na fila: \n");
    while(atual != NULL){
        printf("Nome: %s - ID: %d\n", atual->nome, atual->id);
        atual = atual->prox;
    }
}

void listaCaracteristicas(TipoFilaAvioes fila){
    TipoAviao *primeiro;

    primeiro = fila.inicio;

    printf("Caracteristicas do 1o aviao:\n");
    printf("Nome: %s\n", primeiro->nome);
    printf("ID: %d\n", primeiro->id);
    printf("Caracteristicas: %s\n", primeiro->caracteristicas);
}

/*------------------------------------------*/
/* Funcoes de controle e manuseio das filas */
/*------------------------------------------*/

bool iniciaFilaAvioes(TipoFilaAvioes* fila){
    fila->inicio = NULL;
    fila->final = NULL;

    if(fila->inicio == fila->final == NULL) return true;
    else return false;
}
bool vaziaAvioes(TipoFilaAvioes fila){
    if(fila.inicio == fila.final) return true;
    else return false;
}