#include <stdio.h>
#include <stdlib.h>

void particiona(int* vetor, int p, int N);
void mostra_vetor(int* vetor, int N);

int main(){

    int i;
    int N, p, valor;

    scanf("%d %d", &N, &p);



    int* vetor = (int*)malloc(N*sizeof(int));

    for(i=0; i<N; i++){
        scanf("%d", &valor);
        vetor[i] = valor;
    }

    particiona(vetor, p, N);
    mostra_vetor(vetor, N);

}


void particiona(int* vetor, int p, int N){
    int maior=0;
    int menor=0;

    int i, aux;

    //Vamos ja de cara colocar o pivo no final:
    aux= vetor[p];
    vetor[p] = vetor[N-1];
    vetor[N-1] = aux;

    p = N-1;


    //Para cada elemento
    for(i=0; i<N; i++){
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
    menor++;
    maior++;

    printf("Maior= %d, Menor= %d\n", maior, menor);


}



void mostra_vetor(int* vetor, int N){
    int i;

    for (i=0; i<N; i++){
        printf("%d\n", vetor[i]);
    }
}