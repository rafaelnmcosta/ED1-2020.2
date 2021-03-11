#include <stdio.h>

void contaParCresc(int, int);

int main(){

    int n, i=0;

    printf("Informe o numero PAR final da contagem: ");
    scanf("%d", &n);

    contaParCresc(n, i);

    return 0;
}

void contaParCresc(int n, int i){

    if(i==n){
        printf("%d", n);
    }
    else{
        printf("%d ", i);
        i=i+2;
        contaParCresc(n, i);
    }
}