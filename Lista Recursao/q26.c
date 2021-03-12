#include <stdio.h>

int padovan(int);

int main(){

    int n;

    printf("Informe o n relativo ao termo da sequencia de Padovan a ser encontrado: ");
    scanf("%d", &n);

    printf("O %do termo da sequencia eh %d", n, padovan(n-1));
    
    return 0;
}

int padovan(int n){

    if(n==0||n==1||n==2) return 1;

    else return padovan(n-2)+padovan(n-3);
}