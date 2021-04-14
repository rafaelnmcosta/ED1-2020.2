#define false 0
#define true 1

typedef int bool;

/*---------------------------------------*/
/* Tipos de dados pedidos no exercicio 4 */
/*---------------------------------------*/
typedef struct processo{
    int PID;
    int tempo;
    struct TipoProcesso *prox;
} TipoProcesso;

typedef struct filaProcessos{
    struct TipoFilaProcessos *inicio;
    struct TipoFilaProcessos *final;
} TipoFilaProcessos;

/*--------------------------------*/
/* Funcoes pedidas no exercicio 4 */
/*--------------------------------*/

bool insereProcesso(TipoFilaProcessos*, int);
bool retiraProcessoPorTempo(TipoFilaProcessos*);
void imprimeFilaProcessos(TipoFilaProcessos);


/*------------------------------------------*/
/* Funcoes de controle e manuseio das filas */
/*------------------------------------------*/
bool iniciaFilaProcessos(TipoFilaProcessos*);
bool vaziaProcessos(TipoFilaProcessos);