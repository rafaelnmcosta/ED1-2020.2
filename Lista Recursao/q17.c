#include <stdio.h>

int fatQuad(int, int);

int main(){

    int n, doisN;

    printf("Informe o numero N cujo fatorial quadruplo sera calculado: ");
    scanf("%d", &n);

    doisN = 2*n;

    printf("O resultado eh %d", fatQuad(n, doisN));

    return 0;
}

int fatQuad(int n, int doisN){

    if(doisN==n) return 1;

    else return doisN*fatQuad(n, doisN-1);
}