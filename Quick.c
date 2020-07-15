#include <stdio.h>
#include <stdlib.h>


void mostra_vetor(int* vetor, int N);
int particiona(int* vetor, int inicio, int fim);
void quick_sort(int* vetor, int inicio, int fim);


int main(){

    int i;
    int N, p, valor;

    scanf("%d", &N);



    int* vetor = (int*)malloc(N*sizeof(int));

    for(i=0; i<N; i++){
        scanf("%d", &valor);
        vetor[i] = valor;
    }


    quick_sort(vetor, 0, N-1);
    mostra_vetor(vetor, N);

}

void quick_sort(int* vetor, int inicio, int fim){
    int menor, maior;


    if (fim>inicio){
        menor, maior = particiona(vetor, inicio, fim);


        printf("Inicio= %d, Menor= %d, Maior= %d\n", inicio, menor, maior);


        //Esses -1 e +1 serve pra ignorar o pivo, qual já esta no lugar correto.
        //a esquerda:
        quick_sort(vetor, inicio, menor-1);
        //a direita
        quick_sort(vetor, menor+1, maior);
    }
}

int particiona(int* vetor, int inicio, int fim){
    int maior=0;
    int menor=0;

    int i, aux, p;

    p = fim;


    //Para cada elemento
    for(i=inicio; i<=fim; i++){
        //Se i não é o pivo:

        //Se o valor em questao for maior do que o pivo:
        if (vetor[i] > vetor[p]){
            maior++;
        }
        else if(vetor[i] < vetor[p] && maior==menor){
            maior++;
            menor++;
        }
        else if(vetor[i] < vetor[p] && maior!=menor){
            //Dai a gente coloca o valor de vetor[i] no primeiro slot dos que são maiores:
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
            maior++;
            menor++;
        }
        // printf("Maior= %d, Menor= %d\n", maior, menor);
        // mostra_vetor(vetor, N);

    }
    //agora sim, ao fim do loop, podemos colocar o pivo no lugar certo
    aux = vetor[p];
    vetor[p] = vetor[menor];
    vetor[menor] = aux;
    // menor++;
    // maior++;

    return menor, maior;

}


void mostra_vetor(int* vetor, int N){
    int i;

    for (i=0; i<N; i++){
        printf("%d\n", vetor[i]);
    }
}
