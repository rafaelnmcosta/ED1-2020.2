#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Exercicio6.h"

/*------------------------------*/
/* Funcao pedida no exercicio 6 */
/*------------------------------*/

bool concatenaCrescente(TipoFilaDinamica* fila1, TipoFilaDinamica* fila2, TipoFilaDinamica* filaFinal){

    /* Verifica se existem itens em pelo menos uma das filas */
    if(vaziaDinamica(*fila1) == true && vaziaDinamica(*fila2) == true) return false;

    /* Cria uma nova Fila e cria ponteiros para percorrer as filas passadas */
    TipoFilaDinamica novaFila;
    TipoCelula *aux1, *aux2;
    aux1 = fila1->inicio;
    aux2 = fila2->inicio;

    /* Percorre alternadamente ambas as filas adicionando os itens em ordem crescente */
    while(aux1->prox != NULL && aux2->prox != NULL){
        if(aux1->valor < aux2->valor){
            insereDinamica(&novaFila, aux1->valor);
            aux1 = aux1->prox;
        }
        else{
            insereDinamica(&novaFila, aux2->valor);
            aux2 = aux2->prox;
        }
    }
    /* Caso a fila 1 chegue ao fim, adiciona os itens da fila 2 */
    if(aux1->prox == NULL){
        while(aux2->prox != NULL){
            insereDinamica(&novaFila, aux2->valor);
            aux2 = aux2->prox;
        }
    }
    /* Caso a fila 2 chegue ao fim, adiciona os itens da fila 1 */
    else{
        while(aux1->prox != NULL){
            insereDinamica(&novaFila, aux1->valor);
            aux1 = aux1->prox;
        }
    }

    /* Atribui o endereço da nova fila concatenada ao ponteiro passado e retorna verdadeiro */
    filaFinal = &novaFila;
    return true;
}

/*------------------------------------------*/
/* Funcoes de controle e manuseio das filas */
/*------------------------------------------*/

bool iniciaFilaDinamica(TipoFilaDinamica* fila){
    fila->inicio = NULL;
    fila->final = NULL;

    if(fila->inicio == fila->final == NULL) return true;
    else return false;
}
bool vaziaDinamica(TipoFilaDinamica fila){
    if(fila.inicio == fila.final) return true;
    else return false;
}

bool estaNaFila(TipoFilaDinamica fila, int n){

    if(vaziaDinamica(fila) == true) return false;

    TipoCelula* aux;
    aux = fila.inicio;

    while(aux->prox != NULL){
        if(n == aux->valor) return true;
        aux = aux->prox;
    }

    return false;
}
bool insereDinamica(TipoFilaDinamica* fila, int n){
    TipoCelula *novaCelula;
    TipoCelula *aux;

    novaCelula = (TipoCelula*) malloc(sizeof(TipoCelula));

    aux = fila->final;
    aux->prox = novaCelula;

    novaCelula->valor = n;
    novaCelula->prox = NULL;

    fila->final = novaCelula;

    return true;
}
int removeDinamica(TipoFilaDinamica* fila){

    if(vaziaDinamica(*fila) == true) return false;

    TipoCelula* aux;
    int valor;

    aux = fila->inicio;
    valor = aux->valor;
    fila->inicio = aux->prox;

    free(aux);
    return valor;
}
int contaElementos(TipoFilaDinamica fila){
    TipoCelula *atual;
    int tamanho = 0;

    atual = fila.inicio;

    while(atual != NULL){
        tamanho++;
        atual = atual->prox;
    }

    return tamanho;
}
void imprimeFilaDinamica(TipoFilaDinamica fila){
    TipoCelula *atual;

    atual = fila.inicio;
    printf("Fila: ");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
}
