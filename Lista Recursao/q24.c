#include <stdio.h>

int tribo(int);

int main(){

    int n;

    printf("Informe o n relativo ao termo da sequencia de tribonacci a ser calculado: ");
    scanf("%d", &n);

    printf("O %do termo da sequencia eh %d", n, tribo(n));

    return 0;
}

int tribo(int n){

    if(n==0||n==1) return 0;

    else if(n==2) return 1;

    else return tribo(n-1)+tribo(n-2)+tribo(n-3);
}