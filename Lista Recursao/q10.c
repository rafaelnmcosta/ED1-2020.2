#include <stdio.h>

void contaParDecresc(int);

int main(){

    int n;

    printf("Informe o numero PAR de inicio da contagem: ");
    scanf("%d", &n);

    contaParDecresc(n);

    return 0;
}

void contaParDecresc(int n){

    if(n==0){
        printf("0");
    }
    else{
        printf("%d ", n);
        n = n-2;
        contaParDecresc(n);
    }
}