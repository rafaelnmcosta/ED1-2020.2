#include <stdio.h>

int multiplica(int, int);

int main(){

    int n1, n2, resultado;

    printf("Informe o n1 e n2, respectivamente: ");
    scanf("%d %d", &n1, &n2);
    resultado = multiplica(n1, n2);

    printf("O resultado de %dx%d eh %d", n1, n2, resultado);
    
    return 0;
}

int multiplica(int n1, int n2){

    if(n2==1){
        return n1;
    }
    else return n1 + multiplica(n1, n2-1);
}