#include <stdio.h>
#include <string.h>
#include "ex1.h"

struct conjunto{
    int x;
    struct conjunto* prox;
};

int criaConjunto(Conj* C){ //inicia o conjunto

    C = NULL;

    return conjuntoVazio(C); //Verifica se o conjunto está vazio, ou seja, se foi criado com sucesso

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

        do{ //percorre o conjunto

            if (atual->x != x){ //verifica se o numero informado já faz parte do conjunto
                atual = atual->prox;
            }
            else{
                return 0; //caso o numero já esteja no conjunto a função retorna FALSO
            }
        } while (atual->prox != NULL);

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

        do{ //percorre o conjunto contando os elementos
            atual = atual->prox;
            contador++;
        } while (atual->prox != NULL);

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

        do{ 
            
            if (atual->x > x){ //compara o numero informado com o numero na posição atual do conjunto
                contador++;
            }
            atual = atual->prox; //percorre o conjunto
        } while (atual->prox != NULL);

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

    Conj* atual;

    atual = (Conj*) C1;

    if (tamanhoConjunto(C1) != tamanhoConjunto(C2)){ //caso o tamanho dos conjuntos não seja igual, eles já não são idênticos
        return 0;
    }
    else{

        do{ //loop que percorre o conjunto 1
            
            if (pertenceConjunto(atual->x, C2) == 1){ //verifica se todos os elementos do conjunto 1 estão presentes no conjunto 2, caso estejam continua a percorrer
                atual = atual->prox; 
            }
            else{ //se um elemento de C1 não está em C2 eles não são idênticos
                return 0; 
            }
        }while (atual->prox != NULL);

        return 1; //caso o loop termine com todos os elementos de C1 pertencendo a C2, retorna VERDADEIRO
    }
}

int subconjunto(Conj* C1, Conj* C2){

    Conj* atual;

    atual = (Conj*) C1;

    do{ //loop que percorre o conjunto 1

        if (pertenceConjunto(atual->x, C2) == 1){ //assim como na função anterior, verifica se os elementos de C1 também pertencem a C2
            atual = atual->prox; 
        }
        else{ //retorna FALSO caso algum elemento de C1 não pertença a C2
            return 0; 
        }
    } while (atual->prox != NULL);

    return 1; //retorna VERDADEIRO caso todos os elementos de C1 pertençam a C2
}


Conj* complemento (Conj* C1, Conj* C2){

    Conj* novo;
    Conj** inicioNovo;
    Conj* atual;

    criaConjunto(novo); //inicia um novo conjunto vazio
    inicioNovo = &novo; //Ponteiro que identifica onde será o início do novo conjunto
    
    atual = (Conj*) C2;


    do{
        if (pertenceConjunto(atual->x, C1) == 1){ //verifica se os elementos de C2 pertencem a C1
            atual = atual->prox;
        }
        else{
            insereElementoConjunto(atual->x, novo); //caso algum não pertença, adiciona esse elemento ao novo conjunto
            atual = atual->prox;
        }
    } while (atual->prox != NULL);

    return inicioNovo; //retorna o endereço do início do novo conjunto
}

Conj* uniao (Conj* C1, Conj* C2){

    Conj* novo;
    Conj** inicioNovo;
    Conj* atual;

    criaConjunto(novo);
    inicioNovo = &novo;

    atual = (Conj*) C1;


    do{ //atribui todos os elementos de C1 ao novo conjunto
        insereElementoConjunto(atual->x, novo);
        atual = atual->prox;
        novo = novo->prox;
    }while (atual->prox == NULL);

    atual = (Conj*) C2; //prepara o ponteiro "atual" para percorrer o C2
    
    do{
        if (pertenceConjunto(atual->x, C1) == 0){ //verifica se o elemento atual de C2 não está em C1 para não se repetir no novo conjunto
            insereElementoConjunto(atual->x, novo);
            atual = atual->prox;
            novo = novo->prox;
        }
        else{
            atual = atual->prox;
        }
    }while (atual->prox == NULL);

    return inicioNovo;
}

Conj* interseccao (Conj* C1, Conj* C2){

    Conj* novo;
    Conj** inicioNovo;
    Conj* atual;

    criaConjunto(novo);
    inicioNovo = &novo;

    atual = (Conj*) C1;

    do{
        if(pertenceConjunto(atual->x, C2) == 1){ //vê quais elementos de C1 também estão em C2 e os adiciona ao novo conjunto
            insereElementoConjunto(atual->x, novo);
            atual = atual->prox;
            novo = novo->prox;
        }
        else{
            atual = atual->prox;
        }
    }while (atual->prox != NULL);

    return inicioNovo;
}

Conj* diferenca(Conj* C1, Conj* C2){

    Conj* novo;
    Conj** inicioNovo;
    Conj* atual;

    criaConjunto(novo);
    inicioNovo = &novo;

    atual = (Conj*) C1;

    do{
        if(pertenceConjunto(atual->x, C2) == 0){ //vê quais elementos de C1 não pertencem a C2 e os adiciona ao novo conjunto
            insereElementoConjunto(atual->x, novo);
            atual = atual->prox;
            novo = novo->prox;
        }
        else{
            atual = atual->prox;
        }
    }while (atual->prox != NULL);

    return inicioNovo;
}

//Conj* conjuntoPartes(Conj* C);
//Não entendi o que essa função deve fazer

void mostraConjunto(Conj* C, char* ordem){

    char decrescente[MAX] = "DECRESCENTE";
    char crescente[MAX] = "CRESCENTE";
    

}