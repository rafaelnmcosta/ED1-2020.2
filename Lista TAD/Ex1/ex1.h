//typedef int bool;
#define FALSO 1
#define VERDADEIRO 0

typedef struct conjunto Conj;

int criaConjunto(Conj* C); //inicia o conjunto

int conjuntoVazio(Conj* C); //verifica se o conjunto está vazio

int insereElementoConjunto(int x, Conj* C); //insere o numero informado no conjunto

int excluirElementoConjunto(int x, Conj* C); //exclui o número informado do conjunto

int tamanhoConjunto(Conj* C); //retorna o quantidade de numeros do conjunto

int maior(int x, Conj* C); //retorna quantos numeros do conjunto sao maiores que o x informado

int menor(int x, Conj* C); //retorna quantos numeros do conjunto sao menores que o x informado

int pertenceConjunto(int x, Conj* C); //verifica se o numero informado pertence ao conjunto

int conjuntosIdenticos(Conj* C1, Conj* C2); //verifica se dois conjuntos são iguais

int subconjunto(Conj* C1, Conj* C2); //verifica se o conjunto C1 é subconjunto de C2

Conj complemento(Conj* C1, Conj* C2); //retorna um conjunto com os números que estão em C2 e não estão em C1

Conj uniao(Conj* C1, Conj* C2); //retorna um conjunto com os elementos de C1 e C2 juntos sem se repetirem

Conj interseccao(Conj* C1, Conj* C2); //retorna um conjunto com os elementos que estão simultaneamente em ambos conjuntos

Conj diferenca(Conj* C1, Conj C2); //retorna os elementos que estão em C1 mas que não estão em C2

Conj conjuntoPartes(Conj* C); //(?????) gera o conjunto das partes de C

void mostraConjunto(Conj* C, char* ordem); //Exibe os elementos em ordem crescente ou decrescente de acordo com o informado

int copiarConjunto(Conj* C1, Conj* C2); //Copia os elementos do conjunto C1 para o conjunto C2;

int destroiConjunto(Conj* C); //Elimina o conjunto C da memória
