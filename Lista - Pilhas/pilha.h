#define false 0
#define true 1
#define MAX 10

typedef int bool;

typedef struct celula{
    int valor;
    char letra; // O campo letra sera usado apenas no exercicio 4
    struct tipoCelula *prox;
} tipoCelula;

typedef struct pilha{
    tipoCelula* topo;
} tipoPilha;

/*-------------------------------*/
/* Fila usada p/ gestao e no ex 5*/
/*-------------------------------*/
typedef struct fila{
    tipoCelula* inicio;
    tipoCelula* fim;
} tipoFila;

/*--------------------------------*/
/* Funcoes pedidas nos exercicios */
/*--------------------------------*/
int retornaTopo(tipoPilha*);
bool maiorMenorMedia(tipoPilha, int*, int*, int*);
bool invertePilha(tipoPilha*);
bool palindromo(tipoPilha);
void criaPilhaPorFilas();

/*--------------------------------*/
/* Funcoes de controle das pilhas */
/*--------------------------------*/
bool iniciaPilha(tipoPilha*);
int contaElementos(tipoPilha);
void imprimePilha(tipoPilha);
bool vaziaPilha(tipoPilha);
bool push(tipoPilha*, int);
int pop(tipoPilha*);
tipoPilha* copiaPilha(tipoPilha);

/*-------------------------------*/
/* Funcoes de controle das filas */
/*-------------------------------*/
bool iniciaFila(tipoFila*);
bool vaziaFila(tipoFila);
bool insereFila(tipoFila*, int);
int removeFila(tipoFila*);