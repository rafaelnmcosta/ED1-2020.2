#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Exercicio3.h"

/*------------------------------*/
/* Funcao pedida no exercicio 3 */
/*------------------------------*/

bool dividePorPrioridade(TipoFilaComPrioridade* filaOriginal, int p, TipoFilaComPrioridade* fila1, TipoFilaComPrioridade* fila2){
    
    /* Verifica se a fila esta vazia */
    if(vaziaComPrioridade(*filaOriginal) == true) return false;
    
    /* Cria e inicia as novas filas */
    TipoFilaComPrioridade novaFila1, novaFila2;
    iniciaFilaComPrioridade(&novaFila1);
    iniciaFilaComPrioridade(&novaFila2);

    /* Percorre a fila passada comparando o valor de p com a prioridade e inserindo os itens nas novas filas */
    TipoCelulaComPrioridade* aux;
    aux = filaOriginal->inicio;
    while(aux->prox != NULL){
        if(aux->prioridade >= p){
            insereComPrioridade(&novaFila1, *aux);
        }
        else{
            insereComPrioridade(&novaFila2, *aux);
        }
        aux = aux->prox;
    }

    /* Atribui o endereço das novas filas aos ponteiros passados como parametro */
    fila1 = &novaFila1;
    fila2 = &novaFila2;

    return true;
}

/*------------------------------------------*/
/* Funcoes de controle e manuseio das filas */
/*------------------------------------------*/
bool iniciaFilaComPrioridade(TipoFilaComPrioridade* fila){
    fila->inicio = NULL;
    fila->final = NULL;

    if(fila->inicio == fila->final == NULL) return true;
    else return false;
}
bool vaziaComPrioridade(TipoFilaComPrioridade fila){
    if(fila.inicio == fila.final) return true;
    else return false;
}
bool insereComPrioridade(TipoFilaComPrioridade* fila, TipoCelulaComPrioridade item){
    TipoCelulaComPrioridade *novaCelula;
    TipoCelulaComPrioridade *aux;

    novaCelula = (TipoCelulaComPrioridade*) malloc(sizeof(TipoCelulaComPrioridade));

    aux = fila->final;
    aux->prox = novaCelula;

    novaCelula->valor = item.valor;
    novaCelula->prioridade = item.prioridade;
    novaCelula->prox = NULL;

    fila->final = novaCelula;

    return true;
}
int removeComPrioridade(TipoFilaComPrioridade* fila){
    if(vaziaComPrioridade(*fila) == true) return false;

    TipoCelulaComPrioridade* aux;
    int valor;

    aux = fila->inicio;
    valor = aux->valor;
    fila->inicio = aux->prox;

    free(aux);
    return valor;
}
