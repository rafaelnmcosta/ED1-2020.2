#include <stdio.h>

int eleva(int, int);

int main(){

    int k, n, resultado;

    printf("Informe a base: ");
    scanf("%d", &k);
    printf("Informe o exponente: ");
    scanf("%d", &n);

    resultado = eleva(k, n);

    printf("O resultado de %d^%d eh %d", k, n, resultado);

    return 0;
}

int eleva(int k, int n){

    if(n==1) return k;
    
    else return k * eleva(k, n-1);
}