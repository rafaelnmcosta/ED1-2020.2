#include <stdio.h>

int superFat(int, int, int);

int main(){

    int n, k=1, proxK=1;

    printf("Informe o numero n cujo o super fatorial sera calculado: ");
    scanf("%d", &n);

    printf("O resultado eh %d", superFat(n, k, proxK));

    return 0;
}

int superFat(int n, int k, int proxK){

    if(n==1) return 1;

    else if(k==1){
        proxK++;
        k=proxK;
        return n*superFat(n-1, k, proxK);
    }
    else return n*superFat(n, k-1, proxK);
}