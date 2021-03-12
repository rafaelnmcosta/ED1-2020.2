#include <stdio.h>

int fatDuplo(int);

int main(){

    int n;

    printf("Informe o numero IMPAR cujo fatorial duplo sera calculado: ");
    scanf("%d", &n);

    printf("O resultado eh %d", fatDuplo(n));

    return 0;
}

int fatDuplo(int n){

    if(n==1) return 1;

    else return n*fatDuplo(n-2);
}