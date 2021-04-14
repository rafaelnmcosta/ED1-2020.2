#define false 0
#define true 1
#define MAXCHAR 20

typedef int bool;

/*---------------------------------------*/
/* Tipos de dados pedidos no exercicio 5 */
/*---------------------------------------*/
typedef struct aviao{
    int id;
    char nome[MAXCHAR];
    char caracteristicas[MAXCHAR];
    struct TipoAviao *prox;
} TipoAviao;

typedef struct filaAvioes{
    struct TipoFilaAvioes *inicio;
    struct TipoFilaAvioes *final;
} TipoFilaAvioes;

/*--------------------------------*/
/* Funcoes pedidas no exercicio 5 */
/*--------------------------------*/
int contaAvioes(TipoFilaAvioes);
int liberaAviao(TipoFilaAvioes*);
bool insereAviao(TipoFilaAvioes*, TipoAviao);
void listaAvioes(TipoFilaAvioes);
void listaCaracteristicas(TipoFilaAvioes);

/*------------------------------------------*/
/* Funcoes de controle e manuseio das filas */
/*------------------------------------------*/

bool iniciaFilaAvioes(TipoFilaAvioes*);
bool vaziaAvioes(TipoFilaAvioes);