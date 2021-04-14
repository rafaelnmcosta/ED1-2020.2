#include <stdio.h>
#include <stdlib.h>
#include "Exercicio2.h"

/*--------------------------------*/
/* Funcoes pedidas no exercicio 2 */
/*--------------------------------*/

bool enfileiraAlternativa(TipoFilaEstatica* fila, int n){

    /* Verifica se a fila esta cheia */
    if(fila->inicio == 0 && fila->final == MAX) return false;

    /* Se a fila nao esta cheia mas o ultimo item chegou ao fim do vetor, realoca os itens para o inicio do vetor */
    if(fila->final == MAX){
        int i, aux = 0;
        for(i=fila->inicio; i<=fila->final; i++){
            fila->item[aux] = fila->item[i];
            aux++;
        }
        fila->inicio = 0;
        fila->final = aux-1;
    }

    /* Insere o item informado */
    fila->item[fila->final+1] = n;
    fila->final++;
    return true;
}

bool desenfileiraAlternativa(TipoFilaEstatica* fila){
    /* Verifica se a fila esta vazia */
    if(vaziaEstatica(*fila) == true) return false;

    /* Simplesmente muda o inicio para o proximo item da fila */
    fila->inicio++;
    return true;
}

/*------------------------------------------*/
/* Funcoes de controle e manuseio das filas */
/*------------------------------------------*/

bool iniciafilaEstatica(TipoFilaEstatica* fila){
    fila->inicio = 0;
    fila->final = fila->inicio;

    if(fila->inicio == fila->final == 0) return true;
    else return false;
}
bool vaziaEstatica(TipoFilaEstatica fila){
    if(fila.inicio == fila.final) return true;
    else return false;
}
bool insereEstatica(TipoFilaEstatica *fila, int valor){

    if(fila->final == MAX) return false;

    fila->item[fila->final] = valor;
    fila->final++;
    return true;
}
int removeEstatica(TipoFilaEstatica *fila){

    if(fila->inicio == fila->final){
        printf("Fila vazia!");
    }
    else{
        int valor = fila->item[fila->inicio];
        
        for(int i=0; i<fila->final; i++){
            fila->item[i] = fila->item[i+1];
        }
        fila->final--;
        return valor;
    }
}
void imprimeFilaEstatica(TipoFilaEstatica fila){

    printf("Fila: ");
    for(int i=fila.inicio; i<=fila.final; i++){
        printf("%d ", fila.item[i]);
    }
}