#define false 0
#define true 1
#define MAX 10

typedef int bool;

/*---------------------------------------*/
/* Tipos de dados pedidos no exercicio 2 */
/*---------------------------------------*/
typedef struct filaEstatica{
    int item[MAX];
    int inicio;
    int final;
} TipoFilaEstatica;

/*--------------------------------*/
/* Funcoes pedidas no exercicio 2 */
/*--------------------------------*/
bool enfileiraAlternativa(TipoFilaEstatica*, int);
bool desenfileiraAlternativa(TipoFilaEstatica*);

/*------------------------------------------*/
/* Funcoes de controle e manuseio das filas */
/*------------------------------------------*/
bool iniciafilaEstatica(TipoFilaEstatica*);
bool vaziaEstatica(TipoFilaEstatica);
bool insereEstatica(TipoFilaEstatica*, int);
int removeEstatica(TipoFilaEstatica*);
void imprimeFilaEstatica(TipoFilaEstatica);
