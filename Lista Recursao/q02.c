#include <stdio.h>

int fatorial(int);

int main(){

    int F, N;

    printf("Informe o numero cujo fatorial sera calculado: ");
    scanf("%d", &N);

    F = fatorial(N);

    printf("O resultado eh %d", F);

    return 0;
}

int fatorial(int N){

    if(N <= 1) return 1;
    
    else return N * fatorial(N-1);
}