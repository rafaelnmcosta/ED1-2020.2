#include <stdio.h>
#include <stdlib.h>
#include "listaEstatica.h"

/*-----------------------------------------*/
/* Funcoes pedidas nos exercicios de 1 a 5 */
/*-----------------------------------------*/

TipoLista concatena(TipoLista* lista1, TipoLista* lista2){
    TipoLista listaFinal;
    int i, ref=0;

    for(i = 0; i < lista1->nroItens; i++){
        listaFinal.v[ref] = lista1->v[i];
        ref++;
    }

    for(i = 0; i < lista2->nroItens; i++){
        listaFinal.v[ref] = lista2->v[i];
        ref++;
    }

    listaFinal.nroItens = lista1->nroItens + lista2->nroItens;

    return listaFinal;
}


bool removeItens(TipoLista* lista, int n){
    if(n > lista->nroItens){
        return false;
    }

    int i, naux = n;

    for(i = 0; i < lista->nroItens; i++){
        lista->v[i] = lista->v[naux];
        naux++;
    }

    lista->nroItens = lista->nroItens - n;

    return true;
}

bool buscaMaior(TipoLista* lista, int* valor, int* pos){
    if(lista->nroItens == 0){
        return false;
    }

    int i, posmaior = 0, maior = lista->v[0].valor;

    for(i = 0; i < lista->nroItens; i++){
        if(lista->v[i].valor > maior){
            maior = lista->v[i].valor;
            posmaior = i;
        }
    }

    *valor = maior;
    *pos = posmaior+1;

    return true;
}

int contaPares(TipoLista* lista){
    int i, pares = 0;

    for(i = 0; i < lista->nroItens; i++){
        if((lista->v[i].valor % 2) == 0){
            pares++;
        }
    }
    return pares;
}

float calculaMedia(TipoLista* lista){
    float soma = 0, media;
    int i;

    for(i = 0; i < lista->nroItens; i++){
        soma += lista->v[i].valor;
    }
    
    media = soma/lista->nroItens;

    return media;
}

/*-----------------------------------------*/
/* Funcoes de controle e manuseio da lista */
/*-----------------------------------------*/

void iniciaLista(TipoLista* lista){
    lista->nroItens = 0;
}

int tamanho(TipoLista* lista){
    return lista->nroItens;
}

void imprimeLista(TipoLista lista){
    printf("\n");
    for(int i = 0; i < lista.nroItens; i++){
        printf("%d ", lista.v[i].valor);
    }
    printf("\n");
}

int buscaItemPorValor(TipoLista* lista, int valor){
    int i = 0;

    while(i < lista->nroItens){
        if(valor == lista->v[i].valor){
            return i;
        }
        else i++;
    }

    return ERRO;
}

bool insereItem(TipoLista* lista, TipoItem item){
    if(lista->nroItens == MAX){
        return false;
    }
    lista->v[lista->nroItens] = item;
    lista->nroItens++;

    return true;
}

bool insereItemPorPos(TipoLista* lista, TipoItem item, int pos){
    if(pos < 0 || lista->nroItens == MAX || pos > lista->nroItens){
        return false;
    }

    for(int j = lista->nroItens; j > pos; j--){
        lista->v[j] = lista->v[j-1];
    }

    lista->v[pos] = item;
    lista->nroItens++;

    return true;
}

bool excluiItemPorValor(TipoLista* lista, int valor){
    int pos = buscaItemPorValor(lista, valor);

    if(pos == ERRO){
        return false;
    }

    for(int j = pos; j < lista->nroItens; j++){
        lista->v[j] = lista->v[j+1];
    }

    lista->nroItens--;

    return true;
}

int main(){
    TipoLista lista1, lista2, lista3;
    TipoItem a, b, c, d, e, f;
    a.valor = 2;
    b.valor = 8;
    c.valor = 3;
    d.valor = 5;
    e.valor = 6;
    f.valor = 9;

    iniciaLista(&lista1);
    iniciaLista(&lista2);

    insereItem(&lista1, a);
    insereItem(&lista1, b);
    insereItem(&lista1, c);
    insereItem(&lista2, d);
    insereItem(&lista2, e);
    insereItem(&lista2, f);

    imprimeLista(lista1);
    imprimeLista(lista2);

    /* Questao 1 */
    lista3 = concatena(&lista1, &lista2);
    imprimeLista(lista3);

    /* Questao 3 */
    int valor, posicao;
    buscaMaior(&lista3, &valor, &posicao);
    printf("%d %d\n", valor, posicao);

    /* Questao 4 */
    int pares;
    pares = contaPares(&lista3);
    printf("%d\n", pares);

    /* Questao 5 */
    float media;
    media = calculaMedia(&lista3);
    printf("%f\n", media);
    
    /* Questao 2 */
    removeItens(&lista3, 2);
    imprimeLista(lista3);

    return 0;
}