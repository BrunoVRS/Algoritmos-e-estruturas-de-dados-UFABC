#include <stdio.h>
#include <stdlib.h>

void posicao_ordenada(int* vetor, int N, int X);

int main(){

    int N, valor, X;
    int i;


    scanf("%d", &N);


    int* vetor = (int*)malloc(N*sizeof(int));

    for(i=0; i<N; i++){
        scanf("%d", &valor);
        vetor[i] = valor;
    }

    scanf("%d", &X);

    posicao_ordenada(vetor, N, X);

}

void posicao_ordenada(int* vetor, int N, int X){
    int i;

    int contador=0;

    for(i=0; i<N; i++){
        if(vetor[i]<X){
            contador++;
        }

    }

    printf("%d\n", contador);
}