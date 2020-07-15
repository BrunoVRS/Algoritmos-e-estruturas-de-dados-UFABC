#include <stdio.h>
#include <stdlib.h>


void MergeSort(int* vetor, int inicio, int fim, int N);
void merge(int* vetor, int inicio, int meio, int fim, int N);
void mostra_vetor(int* vetor3, int inicio, int fim);

int main(){

    int N, inicio, meio, fim, valor;
    int i;

    int* vetor = (int*)malloc(N*sizeof(int));


    scanf("%d", &N);

    for(i=0; i<N; i++){
        scanf("%d", &valor);

        vetor[i] = valor;

    }

    mostra_vetor(vetor, 0, N-1);
    MergeSort(vetor, 0, N-1, N);
    mostra_vetor(vetor, 0, N-1);


}


void MergeSort(int* vetor, int inicio, int fim, int N){

    int meio;

    if (fim-inicio>=1){
        meio = (fim+inicio)/2;
        MergeSort(vetor, inicio, meio, N); //A esquerda
        MergeSort(vetor, meio+1, fim, N); //A direita
        merge(vetor, inicio, meio, fim, N);
    }
}


//O merge é como um intercala:
void merge(int* vetor, int inicio, int meio, int fim, int N){

    // printf("Subvetor= ");
    // mostra_vetor(vetor, inicio, fim);

    mostra_vetor(vetor, 0, N-1);


    int i= inicio;
    int j= meio+1;
    int k=0;

    int index_aux=0;

    int* vetor_aux = (int*)malloc((fim+1-inicio)*sizeof(int));



    while(k<=fim){
        if(i<=meio && j<=fim){
            if (vetor[i] < vetor[j]){

                vetor_aux[k] = vetor[i];
                i++;
            }
            else{
                vetor_aux[k] = vetor[j];
                j++;

            }

        }

        else if(j>fim && i<=meio){
            vetor_aux[k] = vetor[i];
            i++;
        }

        else if(i>meio && j<=fim){
            vetor_aux[k] = vetor[j];
            j++;
        }

        k++;

    }


    //Agora, a gente passa essa ordenação ao vetor original
    k=0;
    for(i=inicio; i<=fim; i++){
        vetor[i] = vetor_aux[k];
        k++;
    }

}


void mostra_vetor(int* vetor3, int inicio, int fim){
    int k;

    for(k=inicio; k<fim; k++){
        printf("%d ", vetor3[k]);
    }
    printf("%d", vetor3[fim]);

    printf("\n");

}