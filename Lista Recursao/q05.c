#include <stdio.h>

int fibo(int);

int main(){

    int n, resultado;

    printf("Informe o numero do termo da sequencia de fibonacci a ser calculado: ");
    scanf("%d", &n);
    resultado = fibo(n);

    printf("O %do termo da sequencia eh %d", n, resultado);

    return 0;
}

int fibo(int n){

    if(n==2){
        return 1;
    }
    else if(n==1){
        return 0;
    }
    else return fibo(n-1) + fibo(n-2);
}