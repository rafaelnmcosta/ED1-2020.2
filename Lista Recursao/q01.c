#include <stdio.h>

int somatorio(int);

int main(){

    int N, resultado;

    printf("Informe o numero N: ");
    scanf("%d", &N);

    resultado = somatorio(N);

    printf("O somatorio dos numero de 1 a %d eh %d.", N, resultado);

    return 0;
}

int somatorio(int N){

    if(N==1){
        return N;
    }
    else return N + somatorio(N-1);
}