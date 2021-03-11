#include <stdio.h>

void contagem(int, int);

int main(){

    int n, i=0;

    printf("Informe o numero final da contagem: ");
    scanf("%d", &n);

    contagem(n, i);

    return 0;
}

void contagem(int n, int i){

    if(i==n){
        printf("%d", n);
    }
    else{
        printf("%d ", i);
        i++;
        contagem(n, i);
    }

}