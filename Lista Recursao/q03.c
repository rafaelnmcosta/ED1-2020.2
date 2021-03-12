#include <stdio.h>

int somaCubos(int);

int main(){

    int n, resultado;

    printf("Informe o numero n final da soma dos cubos: ");
    scanf("%d", &n);

    resultado = somaCubos(n);

    printf("O resultado eh %d", resultado);

    return 0;
}

int somaCubos(int n){

    int cubo = n*n*n;

    if(n == 1) return 1;
    
    else return cubo + somaCubos(n-1);
}