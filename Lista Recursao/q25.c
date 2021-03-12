#include <stdio.h>

int tetra(int);

int main(){

    int n;

    printf("Informe o n relativo ao termo a ser calculado na sequencia de tetranacci: ");
    scanf("%d", &n);

    printf("O %do termo da sequencia eh %d", n, tetra(n));

    return 0;
}

int tetra(int n){

    if(n==0||n==1||n==2||n==3) return 0;

    else if(n==4) return 1;

    else return tetra(n-1)+tetra(n-2)+tetra(n-3)+tetra(n-4);
}