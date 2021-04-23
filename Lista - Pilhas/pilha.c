#include <stdio.h>
#include <malloc.h>
#include "pilha.h"

/*--------------------------------*/
/* Funcoes pedidas nos exercicios */
/*--------------------------------*/

/* Questao 1 */
int retornaTopo(tipoPilha* pilha){
    tipoCelula* topo = pilha->topo;
    int retorno = topo->valor;

    tipoCelula* aux = topo;
    topo = topo->prox;

    free(aux);
    return retorno;
}

/* Questao 2 */
bool maiorMenorMedia(tipoPilha pilha, int* maior, int* menor, int* media){
    tipoCelula* atual = pilha.topo;
    int soma;

    maior = atual->valor;
    menor = atual->valor;
    soma = 0;


    do{
        if(atual->valor > maior){
            maior = atual->valor;
        }
        if(atual->valor < menor){
            menor = atual->valor;
        }

        soma = soma + atual->valor;

        atual = atual->prox;

    } while(atual->prox != NULL);

    int nroElem = contaElementos(pilha);
    media = soma / nroElem;

    return true;
}

/* Questao 3 */
bool invertePilha(tipoPilha* pilha){
    tipoFila filaAux;

    iniciaFila(&filaAux);

    int valor;

    while(vaziaPilha(*pilha) == false){
        valor = pop(pilha);
        insereFila(&filaAux, valor);
    }

    int auxInsercao;

    while(vaziaFila(filaAux) == false){
        auxInsercao = removeFila(&filaAux);
        push(pilha, auxInsercao);
    }

    return true;
}

/* Questao 4 */
bool palindromo(tipoPilha pilha){
    tipoPilha* pilhaAux = copiaPilha(pilha);
    invertePilha(pilhaAux);

    tipoCelula* atual = pilha.topo;
    tipoCelula* atualAux = pilhaAux->topo;

    do{
        if(atual->letra != atualAux->letra) return false;
        atual = atual->prox;
        atualAux = atualAux->prox;
    } while (atual->prox != NULL);

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


/*-------------------------------*/
/* Funcoes de controle das filas */
/*-------------------------------*/