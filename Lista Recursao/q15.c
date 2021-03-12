#include <stdio.h>

float somaS(float);

int main(){

    float n;

    printf("Informe o numero n>0 a ser usado na funcao: ");
    scanf("%f", &n);

    printf("O resultado eh %.2f", somaS(n));

    return 0;
}

float somaS(float n){

    if(n==1) return 2;
    
    else return ((1+n*n)/n)+somaS(n-1);
}