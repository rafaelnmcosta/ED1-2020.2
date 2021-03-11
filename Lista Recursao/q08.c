#include <stdio.h>

void decresce(int);

int main(){

    int n;

    printf("Informe o numero de inicio da contagem: ");
    scanf("%d", &n);

    decresce(n);

    return 0;
}

void decresce(int n){

    if(n==0){
        printf("0");
    }
    else{
        printf("%d ", n);
        n--;
        decresce(n);
    }
}