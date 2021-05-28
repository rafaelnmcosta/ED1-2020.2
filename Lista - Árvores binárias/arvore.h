#define false 0
#define true 1
#define MAX  10

typedef int bool;

typedef struct no{
  int chave;
  struct no *esq;
  struct no *dir;
} tipoNo;

/*--------------------------------*/
/* Funcoes pedidas nos exercicios */
/*--------------------------------*/
int contaNos(tipoNo*);
int contaNosNaoFolha(tipoNo*);
int contaNosFolha(tipoNo*);
int calculaAltura(tipoNo*);
int encontraMax(tipoNo*);

/*-------------------------------*/
/* Funcoes de controle da arvore */
/*-------------------------------*/
tipoNo* inicializaArvore();
bool insereNo(tipoNo*, int);
tipoNo* buscaNo(tipoNo*, int);
tipoNo* noAnterior(tipoNo*, tipoNo*);
