#define MAX 10
#define false 0
#define true 1
#define ERRO -1

typedef int bool;
/*--------------------------------*/
/* Tipos de dados usados na lista */
/*--------------------------------*/

typedef struct item{
    int valor;
} TipoItem;

typedef struct lista{
    TipoItem v[MAX];
    int nroItens;
} TipoLista;

/*-----------------------------------------*/
/* Funcoes pedidas nos exercicios de 1 a 5 */
/*-----------------------------------------*/
TipoLista concatena(TipoLista*, TipoLista*);
bool removeItens(TipoLista*, int);
bool buscaMaior(TipoLista*, int*, int*);
int contaPares(TipoLista*);
float calculaMedia(TipoLista*);

/*-----------------------------------------*/
/* Funcoes de controle e manuseio da lista */
/*-----------------------------------------*/
void iniciaLista(TipoLista*);
int tamanho(TipoLista*);
void imprimeLista(TipoLista);
int busca(TipoLista*, int);
bool insereItem(TipoLista*, TipoItem);
bool insereItemPorPos(TipoLista*, TipoItem, int);
bool excluiItemPorValor(TipoLista*, int);
