#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

/*--------------------------------*/
/* Funcoes pedidas nos exercicios */
/*--------------------------------*/

/* Questao 1 */
int contaNos(tipoNo* raiz){

  if(raiz == NULL) return 0;

  return contaNos(raiz->esq) + 1 + contaNos(raiz->dir);
}

/* Questao 2 */
int contaNosNaoFolha(tipoNo* raiz){

  if(contaNos(raiz) == 0) return 0;
  
  return contaNosNaoFolha(raiz->esq) + 1 + contaNosNaoFolha(raiz->dir);
}

/* Questao 3 */
int contaNosFolha(tipoNo* raiz){

  int nos = contaNos(raiz);
  int nosNaoFolha = contaNosNaoFolha(raiz);

  return (nos - nosNaoFolha);
}

/* Questao 4 */
int calculaAltura(tipoNo* raiz){

  int altEsq, altDir;

  if (raiz == NULL){
    return -1;
  }
  else {
    altEsq = calculaAltura(raiz->esq);
    altDir = calculaAltura(raiz->dir);

    if(altEsq < altDir){
      return altDir + 1;
    }
    else{
      return altEsq + 1;
    }
  }
}

/* Questao 5 */
int encontraMax(tipoNo* raiz){

  if(raiz->dir != NULL){
    encontraMax(raiz->dir);
  }
  else return raiz->chave;
}


/*-------------------------------*/
/* Funcoes de controle da arvore */
/*-------------------------------*/

tipoNo* inicializaArvore(){
  return NULL;
}

bool insereNo(tipoNo *raiz, int novaChave){
  tipoNo *novoNo;
  
  novoNo = (tipoNo*) malloc(sizeof(tipoNo));
  novoNo->chave = novaChave;
  novoNo->esq = NULL;
  novoNo->dir = NULL;

  if(raiz == NULL){
    raiz = novoNo;
    return true;
  }

  if(novaChave < raiz->chave){
    insereNo(raiz->esq, novaChave);
  }
  else{
    insereNo(raiz->dir, novaChave);
  }
}

tipoNo* buscaNo(tipoNo* raiz, int chaveBuscada){

  if(raiz == NULL) return NULL;

  if(chaveBuscada == raiz->chave) return raiz;

  if(chaveBuscada < raiz->chave){

    if(raiz->esq != NULL){
      buscaNo(raiz->esq, chaveBuscada);
    }
    else{
      printf("\nA chave buscada nao esta na arvore!");
    }
  }

  else{

    if(raiz->dir != NULL){
      buscaNo(raiz->dir, chaveBuscada);
    }
    else{
      printf("\nA chave buscada nao esta na arvore!");
    }
  }
}

tipoNo* noAnterior(tipoNo* raiz, tipoNo* noBuscado){

  if(noBuscado == raiz->esq || noBuscado == raiz->dir){
    return raiz;
  }

  if(noBuscado->chave < raiz->chave){
    noAnterior(raiz->esq, noBuscado);
  }
  else{
    noAnterior(raiz->dir, noBuscado);
  }

}
