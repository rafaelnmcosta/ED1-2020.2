#include <stdio.h>
#include <malloc.h>
#include "pilha.h"

/*--------------------------------*/
/* Funcoes pedidas nos exercicios */
/*--------------------------------*/

/* Questao 1 */
int retornaTopo(tipoPilha* pilha){

    /* Tem o funcionamento igual ao "pop", mas foi repetida por praticidade */

    tipoCelula* topo = pilha->topo;
    int valorTopo = topo->valor;

    tipoCelula* aux = topo;
    pilha->topo = topo->prox;

    free(aux);
    return valorTopo;
}

/* Questao 2 */
bool maiorMenorMedia(tipoPilha pilha, int* maior, int* menor, float* media){

    /* Como deveria retornar muitos valores, faz isso atraves de referencia */

    tipoCelula* atual;
    float soma;
    float auxMedia;
    int auxMaior;
    int auxMenor;

    atual = pilha.topo;
    auxMaior = atual->valor;
    auxMenor = atual->valor;
    soma = atual->valor;

    /* Percorre a pilha ate o final ajustando os valores maior e menor, e aumentando a soma */
    do{
        atual = atual->prox;

        if(atual->valor > auxMaior){
            auxMaior = atual->valor;
        }
        if(atual->valor < auxMenor){
            auxMenor = atual->valor;
        }

        soma = soma + atual->valor;
    } while(atual->prox != NULL);

    /* Calcula a media e define o ultimo valor "retornado" */
    int nroElem = contaElementos(pilha);
    auxMedia = soma / ((float)nroElem);

    *maior = auxMaior;
    *menor = auxMenor;
    *media = auxMedia;

    return true;
}

/* Questao 3 */
bool invertePilha(tipoPilha* pilha){

    /*
    A logica consiste em passar os itens da pilha para uma fila, depois
    desenfileirar os itens novamente para a pilha, fazendo com que sejam 
    inseridos na ordem reversa da que foram retirados
    */

    tipoFila filaAux;
    tipoCelula* aux;

    iniciaFila(&filaAux);

    int valor;

    /* passa os itens para a fila */
    while(vaziaPilha(*pilha) == false){
        valor = pop(pilha);
        insereFila(&filaAux, valor);
    }

    int auxInsercao;

    /* volta os itens para a pilha */
    while(vaziaFila(filaAux) == false){
        auxInsercao = removeFila(&filaAux);
        push(pilha, auxInsercao);
    }

    return true;
}

/* Questao 4 */
bool palindromo(tipoPilha pilha){

    /* cria uma copia da pilha e a inverte para a comparacao */
    tipoPilha* pilhaAux = copiaPilha(pilha);
    invertePilha(pilhaAux);

    tipoCelula* atual = pilha.topo;
    tipoCelula* atualAux = pilhaAux->topo;

    /* percorre as duas pilhas comparando as letras */
    do{
        if(atual->letra != atualAux->letra) return false;
        atual = atual->prox;
        atualAux = atualAux->prox;
    } while (atual->prox != NULL);

    /* caso nao tenha encontrado nenhuma diferenca, sao palindromas */
    return true;
}

/* Questao 5 */
void criaPilhaPorFilas(){
    tipoFila filaImpar;
    tipoFila filaPar;
    tipoPilha pilha;

    iniciaFila(&filaImpar);
    iniciaFila(&filaPar);
    iniciaPilha(&pilha);

    bool verificador = true;
    int valor;
    tipoCelula aux;

    /* roda o menu enquanto o usuario fornece os valores */
    while(verificador == true){
        
        printf("Informe um numero: ");
        scanf("%d", valor);

        if((valor % 2) == 0){
            insereFila(&filaPar, valor);
        }
        else{
            insereFila(&filaImpar, valor);
        }

        printf("\nNumero inserido!\nDigite '1' para continuar inserindo ou '0' para sair: ");
        scanf("%d", verificador);
    }

    /* insere alternadamente os valores pares e impares ate as duas filas estarem vazias */
    do{
        if(vaziaFila(filaImpar) == false){
            valor = removeFila(&filaImpar);
            if(valor >= 0){
                push(&pilha, valor);
            }
            else{
                pop(&pilha);
            }
        }
        if(vaziaFila(filaPar) == false){
            valor = removeFila(&filaPar);
            if(valor >= 0){
                push(&pilha, valor);
            }
            else{
                pop(&pilha);
            }
        }
        
    } while(vaziaFila(filaImpar) == false || vaziaFila(filaPar) == false);

    imprimePilha(pilha);

}

/*--------------------------------*/
/* Funcoes de controle das pilhas */
/*--------------------------------*/

bool iniciaPilha(tipoPilha* pilha){
    pilha->topo = NULL;

    if(pilha->topo == NULL) return true;
    else return false;
}


int contaElementos(tipoPilha pilha){
    tipoCelula* atual;
    int contador = 1;

    atual = pilha.topo;

    do{
        contador++;
        atual = atual->prox;
    } while(atual->prox != NULL);

    return contador;
}

void imprimePilha(tipoPilha pilha){
    tipoCelula* atual;

    atual = pilha.topo;
    printf("\nPilha: %d ", atual->valor);

    if(atual->prox != NULL){
        do{
            atual = atual->prox;
            printf("%d ", atual->valor);
        } while(atual->prox != NULL);
    }
    printf("\n");
}


bool vaziaPilha(tipoPilha pilha){
    if(pilha.topo == NULL) return true;
    else return false;
}


bool push(tipoPilha* pilha, int n){
    tipoCelula* novaCelula;

    novaCelula = (tipoCelula*) malloc(sizeof(tipoCelula));

    novaCelula->valor = n;
    novaCelula->prox = pilha->topo;
    pilha->topo = novaCelula;

    return true;
}


int pop(tipoPilha* pilha){

    if(vaziaPilha(*pilha)){
        printf("A pilha esta vazia!\n");
        return false;
    }
    
    tipoCelula* aux;
    aux = pilha->topo;

    int valorTopo = aux->valor;
    pilha->topo = aux->prox;

    free(aux);
    return valorTopo;
}


tipoPilha* copiaPilha(tipoPilha pilha){

    if(vaziaPilha(pilha)){
        printf("A pilha esta vazia!\n");
    }

    /*
    Cria uma pilha auxiliar pois ao remover os itens da pilha pela primeira vez, eles ficarao
    em ordem oposta a original, portanto precisa ser realocada novamente para que a ordem inicial
    seja preservada na pilha final
    */
    tipoPilha novaPilha;
    tipoPilha pilhaAux;
    iniciaPilha(&novaPilha);
    iniciaPilha(&pilhaAux);

    tipoCelula* aux;
    int v;

    aux = pilha.topo;

    /* copia os valores para uma pilha auxiliar inversa */
    do{
        v = aux->valor;
        push(&pilhaAux, v);
    } while(aux->prox != NULL);

    aux = pilhaAux.topo;

    /* copia a pilha inversa novamente, agora deixando a pilha final correta */
    do{
        v = aux->valor;
        push(&novaPilha, v);
    } while(aux->prox != NULL);

    return &novaPilha;
}

/*-------------------------------*/
/* Funcoes de controle das filas */
/*-------------------------------*/

bool iniciaFila(tipoFila* fila){
    fila->inicio = NULL;
    fila->fim = NULL;

    if(fila->inicio == fila->fim == NULL) return true;
    else return false;
}

bool vaziaFila(tipoFila fila){
    if(fila.inicio == fila.fim) return true;
    else return false;
}

bool insereFila(tipoFila* fila, int n){
    tipoCelula *novaCelula;
    tipoCelula *aux;

    novaCelula = (tipoCelula*) malloc(sizeof(tipoCelula));

    aux = fila->fim;
    aux->prox = novaCelula;

    novaCelula->valor = n;
    novaCelula->prox = NULL;

    fila->fim = novaCelula;

    return true;
}

int removeFila(tipoFila* fila){

    if(vaziaFila(*fila) == true) return false;

    tipoCelula* aux;
    int valor;

    aux = fila->inicio;
    valor = aux->valor;
    fila->inicio = aux->prox;

    free(aux);
    return valor;
}