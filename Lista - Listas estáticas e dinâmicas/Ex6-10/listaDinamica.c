#include <stdio.h>
#include <stdlib.h>
#include "listaDinamica.h"

/*------------------------------------------*/
/* Funcoes pedidas nos exercicios de 6 a 10 */
/*------------------------------------------*/

tipoLista geraListaPorVetor(int tam, int* vet){

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
    tipoCelula* jaExiste;

    atual = lista->inicio;
    jaExiste = lista->inicio;
    

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
            printf("Item repetido encontrado: %d\n", atual->item);
            jaExiste = atual;
            atual = atual->prox;
            removeItemPorPosicao(lista, jaExiste);
        }
    }while(atual->prox != NULL);

    /* Retorna false se nenhum numero foi excluido */
    if(jaExiste == lista->inicio) return false;

    else return true;
}

tipoLista intercalaListas(tipoLista lista1, tipoLista lista2){
    tipoLista listaFinal;
    tipoCelula* atual1;
    tipoCelula* atual2;

    iniciaLista(&listaFinal);

    atual1 = lista1.inicio;
    atual2 = lista2.inicio;
    
    /* Insere os itens intercalados até que uma das duas listas acabe */
    do{
        insereItem(&listaFinal, atual1->item);
        insereItem(&listaFinal, atual2->item);
        atual1 = atual1->prox;
        atual2 = atual2->prox;

    }while(atual1->prox != NULL && atual2->prox != NULL);
    
    /* Verifica qual lista acabou e insere o restante dos itens da lista que sobrou */
    if(atual2->prox != NULL){
        do{
            insereItem(&listaFinal, atual2->item);
            atual2 = atual2->prox;
        }while(atual2->prox != NULL);
    }
    else if(atual1->prox != NULL){
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

    atual = lista.inicio;
    soma = atual->item;

    do{
        atual = atual->prox;
        soma += atual->item;
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
    tipoCelula* ultima;

    ultima = lista->fim;
    novaCelula = (tipoCelula*) malloc(sizeof(tipoCelula));

    ultima->prox = novaCelula;

    ultima->item = n;
    novaCelula->prox = NULL;
    
    lista->fim = novaCelula;

    return true;  
}

bool existeItem(tipoLista lista, int alvo){
    tipoCelula* atual;

    atual = lista.inicio;

    while(atual->item != alvo && atual->prox != NULL){
        atual = atual->prox;
    }
    if(atual->item == alvo) return true;

    else return false;
}

tipoCelula* buscaItem(tipoLista* lista, int alvo){
    tipoCelula* atual;

    atual = lista->inicio;

    while(atual->item != alvo && atual->prox != NULL){
        atual = atual->prox;
    }
    if(atual->item == alvo) return atual;
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

    while(seguinte != NULL){
        if(atual->item == n){
            anterior->prox = seguinte;
            free(atual);
            return true;
        }
        else{
            anterior = atual;
            atual = atual->prox;
            seguinte = atual->prox;
        }
    }
    /* Retorna falso caso nao exista o item buscado */
    return false;
}

bool removeItemPorPosicao(tipoLista* lista, tipoCelula* alvo){
    tipoCelula* atual;

    atual = lista->inicio;

    /* Verifica se eh o primeiro da lista */
    if(atual == alvo){
        lista->inicio = atual->prox;
        free(alvo);
        return true;
    }
    
    do{
        atual = atual->prox;
    }while(atual->prox != alvo && atual->prox != NULL);

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

    atual = lista.inicio;

    do{
        printf("%d ", atual->item);
        atual = atual->prox;
    }
    while(atual->prox != NULL);
    printf("\n");
}

int main(){

    tipoLista listaVetor1, listaVetor2, listaConcatenada, listaIntercalada;

    int vet1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int vet2[] = {8, 9, 10, 11, 12, 13, 14};
    int tamVet1, tamVet2, soma;

    /* (Eh necessario saber o tamanho dos vetores para passar como parametro da funcao) */
    tamVet1 = sizeof vet1 / sizeof vet1[0];
    tamVet2 = sizeof vet2 / sizeof vet2[0];

    iniciaLista(&listaVetor1);
    iniciaLista(&listaVetor2);
    iniciaLista(&listaConcatenada);
    iniciaLista(&listaIntercalada);

    /* Questao 6 */
    printf("\n--- Questao 6: gerar listas por vetores: ---\n");
    listaVetor1 = geraListaPorVetor(tamVet1, vet1);
    listaVetor2 = geraListaPorVetor(tamVet2, vet2);

    imprimeLista(listaVetor1);
    imprimeLista(listaVetor2);

    /* Questao 7 */
    printf("\n--- Questao 7: concatenar listas: ---\n");
    listaConcatenada = concatenaListas(listaVetor1, listaVetor2);

    /* Questao 8 */
    printf("\n--- Questao 8: remover itens repetidos: ---\n");
    if(removeRepetidos(&listaConcatenada) == false){
        printf("Erro ao remover repetidos");
    }
    else imprimeLista(listaConcatenada);

    /* Questao 9 */
    printf("\n--- Questao 9: intercalar listas: ---\n");
    listaIntercalada = intercalaListas(listaVetor1, listaVetor2);

    imprimeLista(listaIntercalada);

    /* Questao 10 */    
    printf("\n--- Questao 10: somar os valores das listas: ---\n");
    soma = somaValoresLista(listaIntercalada);

    printf("O valor da soma eh %d\n\n", soma);

    return 0;
}