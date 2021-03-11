#include <stdio.h>
#define MAX 10

void exibeArray(int*, int);

int main(){

    int vet[MAX]={0,1, 2,3,4,5,6,7,8,9};
    int i=0;
    exibeArray(vet, i);

    return 0;
}

void exibeArray(int* vet, int i){

    if(i<MAX){
        printf("%d ", vet[i]);
        i++;
        exibeArray(vet, i);
    }
}