#include <stdio.h>
#include <stdlib.h>
#include <ex1.h>

struct conjunto{
    int x;
    struct conjunto* prox;
};

int criaConjunto(Conj* C){ //inicia a lista

    C = NULL;
}

int conjuntoVazio(Conj* C){

    if (C == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int insereElementoConjunto(int x, Conj* C){

    Conj* novo;
    Conj* atual;

    if (C == NULL){ //verifica se o conjunto está vazio e insere o número no início caso esteja
        novo = (Conj*) malloc(sizeof(Conj));

        novo->x = x;
        novo->prox = NULL;
        C = novo;
    }
    else{
        atual = (Conj*) C;

        while (atual->prox != NULL){ //percorre o conjunto

            if (atual->x != x){ //verifica se o numero informado já faz parte do conjunto
                atual = atual->prox;
            }
            else{
                return 0; //caso o numero já esteja no conjunto a função retorna FALSO
            }
        }

        //caso chegue no fim do conjunto, insere o numero no fim e retorna VERDADEIRO
        novo = (Conj*) malloc(sizeof(Conj));
        atual->prox = novo;
        novo->x = x;
        novo->prox = NULL;

        return 1;
    }
}

int excluirElementoConjunto(int x, Conj* C){

    Conj* atual;
    Conj* anterior = NULL; //incia como NULL por não haver elementos antes do primeiro do conjunto

    atual = (Conj*) C;

    while (atual->x != x || atual->prox != NULL){ //percorre o conjunto enquanto não encontra o numero informado ou não chega ao final
        anterior = atual;
        atual = atual->prox;
    }

    if (atual->prox == NULL){ //se chegou ao final sem encontrar o numero retorna FALSO
        return 0;
    }
    else{
        if (anterior == NULL){ //verifica se é o primeiro elemento do conjunto
            C = atual->prox;
            free(atual);
            return 1;
        }
        else{ //caso não seja o primeiro, ajusta os ponteiros do conjunto além de apagar o numero
            anterior->prox = atual->prox;
            free(atual);
            return 1;
        }
    }


}

int tamanhoConjunto(Conj* C){

    Conj* atual;
    int contador = 1;

    atual = (Conj*) C;

    if (C == NULL){ //verifica se o conjunto está vazio
        return 0;
    }
    else{

        while (atual->prox != NULL){ //percorre o conjunto contando os elementos
            atual = atual->prox;
            contador++;
        }

        return contador;

    }
}

int maior(int x, Conj* C){

    Conj* atual;
    int contador=0;

    atual = (Conj*) C;

    if (C == NULL){ //vereifica se o conjunto está vazio
        return 0;
    }
    else{

        while (atual->prox != NULL){ 
            
            if (atual->x > x){ //compara o numero informado com o numero na posição atual do conjunto
                contador++;
            }
            atual = atual->prox; //percorre o conjunto
        }

        return contador;
    }
}

int menor(int x, Conj* C){

    Conj* atual;
    int contador=0;

    atual = (Conj*) C;

    if (C == NULL){ //verifica se o conjunto está vazio
        return 0;
    }
    else{

        while (atual->prox != NULL){ 
            
            if (atual->x < x){ //compara o numero informado com o numero na posição atual do conjunto
                contador++;
            }
            atual = atual->prox; //percorre o conjunto
        }

        return contador;
    }
}

int pertenceConjunto(int x, Conj* C){

    Conj* atual;

    atual = (Conj*) C;

    while (atual->x != x && atual->prox != NULL){ //percorre o conjunto enquanto não encontra o numero informado
        atual = atual->prox;
    }

    if (atual->prox == NULL && atual->x != x){ //verifica se não é o numero mesmo que seja o ultimo elemento do conjunto
        return 0; 
    }
    else{
        return 1;
    }
}

int conjuntosIdenticos(Conj* C1, Conj* C2){

    Conj* atual_1;
    Conj* atual_2;

    atual_1 = (Conj*) C1;
    atual_2 = (Conj*) C2;

    if (tamanhoConjunto(C1) != tamanhoConjunto(C2)){ //caso o tamanho dos conjuntos não seja igual, eles já não são idênticos
        return 0;
    }
    else{

        while (atual_1->prox != NULL){ //percorre o conjunto
            
            if(atual_1->x == atual_2->x){ //verifica se o elemento atual dos dois conjuntos é igual, caso seja, continua a percorrer
            atual_1 = atual_1->prox;
            atual_2 = atual_2->prox;
            }
            else{   //caso o elemento atual seja diferente retorna FALSO
                return 0;
            }
        }

        if (atual_1->x == atual_2->x && atual_1->prox == NULL){ //verifica se os dois últimos elementos são iguais
            return 1;
        }
        else{
            return 0;
        }

}