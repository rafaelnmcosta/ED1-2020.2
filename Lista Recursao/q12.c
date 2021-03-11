#include <stdio.h>
#define MAX 5

int encontraMenor(int*, int, int);

int main(){

    int vet[MAX] = {7, 5, 2, 8, 3};
    int menor = vet[0];
    int i = 0;

    printf("%d", encontraMenor(vet, i, menor));

    return 0;
}

int encontraMenor(int* vet, int i, int menor){

    if(i<MAX){
        
        if(menor>vet[i]){
            menor = vet[i];
        }
        i++;
        encontraMenor(vet, i, menor);
    }
    else return menor;
}