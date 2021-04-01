#include <stdio.h>
#include <stdlib.h>
#include "listaEstatica.h"

int main(){
    TipoLista lista1, lista2, lista3;
    TipoItem a, b, c, d, e, f;
    a.valor = 2;
    b.valor = 8;
    c.valor = 3;
    d.valor = 5;
    e.valor = 6;
    f.valor = 9;

    iniciaLista(&lista1);
    iniciaLista(&lista2);

    insereItem(&lista1, a);
    insereItem(&lista1, b);
    insereItem(&lista1, c);
    insereItem(&lista2, d);
    insereItem(&lista2, e);
    insereItem(&lista2, f);

    imprimeLista(lista1);
    imprimeLista(lista2);

    /* Questao 1 */
    lista3 = concatena(&lista1, &lista2);
    imprimeLista(lista3);

    /* Questao 3 */
    int valor, posicao;
    buscaMaior(&lista3, &valor, &posicao);
    printf("%d %d\n", valor, posicao);

    /* Questao 4 */
    int pares;
    pares = contaPares(&lista3);
    printf("%d\n", pares);

    /* Questao 5 */
    float media;
    media = calculaMedia(&lista3);
    printf("%f\n", media);
    
    /* Questao 2 */
    removeItens(&lista3, 2);
    imprimeLista(lista3);

    return 0;
}
