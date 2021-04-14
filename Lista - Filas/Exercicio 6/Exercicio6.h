#define false 0
#define true 1

typedef int bool;

typedef struct celula{
    int valor;
    struct TipoCelula *prox;
} TipoCelula;

typedef struct filaDinamica{
    struct TipoCelula *inicio;
    struct TipoCelula *final;
} TipoFilaDinamica;


/*------------------------------*/
/* Funcao pedida no exercicio 6 */
/*------------------------------*/

bool concatenaCrescente(TipoFilaDinamica*, TipoFilaDinamica*, TipoFilaDinamica*);

/*------------------------------------------*/
/* Funcoes de controle e manuseio das filas */
/*------------------------------------------*/

bool iniciaFilaDinamica(TipoFilaDinamica*);
bool vaziaDinamica(TipoFilaDinamica);
bool insereDinamica(TipoFilaDinamica*, int);
int removeDinamica(TipoFilaDinamica*);
int contaElementos(TipoFilaDinamica);
void imprimeFilaDinamica(TipoFilaDinamica);
