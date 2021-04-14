#define false 0
#define true 1

typedef int bool;

/*---------------------------------------*/
/* Tipos de dados pedidos no exercicio 3 */
/*---------------------------------------*/
typedef struct celulaComPrioridade{
    int valor;
    int prioridade;
    struct TipoCelulaComPrioridade *prox;
} TipoCelulaComPrioridade;

typedef struct filaComPrioridade{
    struct TipoCelulaComPrioridade *inicio;
    struct TipoCelulaComPrioridade *final;
} TipoFilaComPrioridade;

/*------------------------------*/
/* Funcao pedida no exercicio 3 */
/*------------------------------*/
bool dividePorPrioridade(TipoFilaComPrioridade* fila, int p, TipoFilaComPrioridade*, TipoFilaComPrioridade*);

/*------------------------------------------*/
/* Funcoes de controle e manuseio das filas */
/*------------------------------------------*/
bool iniciaFilaComPrioridade(TipoFilaComPrioridade*);
bool vaziaComPrioridade(TipoFilaComPrioridade);
bool insereComPrioridade(TipoFilaComPrioridade*, TipoCelulaComPrioridade);
int removeComPrioridade(TipoFilaComPrioridade*);