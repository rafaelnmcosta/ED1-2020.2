#include <stdio.h>

int sequenciaF(int);

int main(){

    int n;
    
    printf("Informe a o numero sobre qual a sequencia sera calculada: ");
    scanf("%d", &n);

    printf("O resultado eh %d", sequenciaF(n));

    return 0;
}

int sequenciaF(int n){

    if(n==1) return 1;

    else if(n==2) return 2;

    else return 2*sequenciaF(n-1) + 3*sequenciaF(n-2);
}