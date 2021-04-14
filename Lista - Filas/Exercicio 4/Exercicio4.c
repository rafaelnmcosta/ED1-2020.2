#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Exercicio4.h"

/*--------------------------------*/
/* Funcoes pedidas no exercicio 4 */
/*--------------------------------*/
bool insereProcesso(TipoFilaProcessos* fila, int id){
    TipoProcesso *novoProcesso;
    TipoProcesso *aux;

    novoProcesso = (TipoProcesso*) malloc(sizeof(TipoProcesso));

    /* Acerta o ponteiro do ultimo elemento */
    aux = fila->final;
    aux->prox = novoProcesso;

    novoProcesso->PID = id;
    /* Atribui a hora que o processo foi criado, assim podendo dizer quao antigo ele eh */
    novoProcesso->tempo = clock();
    novoProcesso->prox = NULL;

    /* Acerta o ponteiro da fila para o novo elemento */
    fila->final = novoProcesso;

    return true;
}

bool retiraProcessoPorTempo(TipoFilaProcessos* fila){
    
    /* Verifica se a fila esta fazia */
    if(vaziaProcessos(*fila) == true) return false;

    TipoProcesso *aux, *maisAntigo;
    int comparador;

    aux = fila->inicio;
    comparador = aux->tempo;

    /* Percorre a fila para encontrar o processo que esta esperando ha mais tempo */
    while(aux->prox != NULL){
        if(aux->tempo < comparador){
            comparador = aux->tempo;
            maisAntigo = aux;
        }
        aux = aux->prox;
    }

    /* Retorna a variavel auxiliar para o inicio da fila */
    aux = fila->inicio;

    /* Percorre a fila até chegar um processo antes do mais antigo */
    while(aux->prox != maisAntigo){
        aux = aux->prox;
    }

    /* Ajeita os ponteiros para que nao haja um buraco na fila e apaga o processo mais antigo */
    aux->prox = maisAntigo->prox;
    free(maisAntigo);

    return true;
}

void imprimeFilaProcessos(TipoFilaProcessos fila){
    TipoProcesso *aux;
    int tempoAux;

    aux = fila.inicio;

    /* Percorre a fila imprimindo os dados dos processos */
    printf("Fila de processos atual:\n\n");
    while(aux->prox != NULL){
        printf("PID: %d\n", aux->PID);
        /* Calcula o tempo de espera do processo de acordo com a hora que ele foi criado e a hora atual */
        tempoAux = clock();
        tempoAux = tempoAux - aux->tempo;
        printf("Tempo de espera: %d\n\n", tempoAux);
    }

}

/*------------------------------------------*/
/* Funcoes de controle e manuseio das filas */
/*------------------------------------------*/
bool iniciaFilaProcessos(TipoFilaProcessos* fila){
    fila->inicio = NULL;
    fila->final = NULL;

    if(fila->inicio == fila->final == NULL) return true;
    else return false;
}
bool vaziaProcessos(TipoFilaProcessos fila){
    if(fila.inicio == fila.final) return true;
    else return false;
}