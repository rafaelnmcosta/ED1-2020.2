#include <stdio.h>

int h(int, int);

int main(){

    int m, n;

    printf("Informe m e n respectivamente: ");
    scanf("%d %d", &m, &n);

    printf("O resultado da funcao h eh %d", h(m, n));

    return 0;
}

int h(int m, int n){

    if(n==1) return m+1;
    
    else if(m==1) return n+1;

    else return h(m, n-1) + h(m-1, n);
}