#include <stdio.h>
#define MAX 5

int somaVetor(int*,int, int);

int main(){

    int vet[MAX] = {1,2,3,4,5};
    int soma = 0;
    int i = 0;

    printf("%d", somaVetor(vet,i , soma));

    return 0;
}

int somaVetor(int* vet, int i, int soma){

    if(i==MAX){
        return soma;
    }
    else{
        soma = soma+vet[i];
        i++;
        somaVetor(vet, i, soma);
    }
}