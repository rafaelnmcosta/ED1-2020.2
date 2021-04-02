#define MAX 10
#define false 0
#define true 1

typedef int bool;

/*--------------------------------*/
/* Tipos de dados usados na lista */
/*--------------------------------*/
typedef struct celula{
  int item;
  struct TipoCelula *prox;
} tipoCelula;

typedef struct lista{
    struct tipoCelula *inicio;
    struct tipoCelula *fim;
} tipoLista;

/*------------------------------------------*/
/* Funcoes pedidas nos exercicios de 6 a 10 */
/*------------------------------------------*/
tipoLista geraListaPorVetor(int, int*);
tipoLista concatenaListas(tipoLista, tipoLista);
bool removeRepetidos(tipoLista*);
tipoLista intercalaListas(tipoLista, tipoLista);
int somaValoresLista(tipoLista);

/*-----------------------------------------*/
/* Funcoes de controle e manuseio da lista */
/*-----------------------------------------*/
bool iniciaLista(tipoLista*);
bool insereItem(tipoLista*, int);
bool existeItem(tipoLista, int);
bool removeItemPorValor(tipoLista*, int);
bool removeItemPorPosicao(tipoLista*, tipoCelula*);
void imprimeLista(tipoLista);

