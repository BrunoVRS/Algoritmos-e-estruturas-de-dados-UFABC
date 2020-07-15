#include <stdio.h>
#include <stdlib.h>

struct lista{

    int inicio, final;
    int *vetor;
};


void bubble (struct lista *dados);


int main(){

    int tamanho, inicio;
    int valor;
    int i, j;


    scanf("%d", &tamanho);



    //iniciando a variavel que vai carregar o vetor:
    struct lista *dados = (struct lista*)malloc(sizeof(struct lista));
    dados->final = tamanho-1;
    //Alocando um espaço para o vetor
    dados->vetor = (int*)malloc(tamanho*sizeof(int));
    dados->inicio = 0;


    for (i=0; i<tamanho; i++){
      scanf("%d", &valor);
      //agora, inserimos o valor no vetor:
      dados->vetor[i] = valor;

    }


    for (j=0; j<dados->final; j++){
        printf("%d ", dados->vetor[j]);
    }
    printf("%d\n", dados->vetor[j]);
    bubble(dados);

    free(dados);
}

//Vai ser void pq a gente ta passando por referencia.
void bubble (struct lista *dados){

    int i, aux, j;
    int trocas=0;
    int changes=0;

    while(1){

        // Last i elements are already in place
        for (i=0; i<dados->final; i++){
            if (dados->vetor[i] > dados->vetor[i+1]){
                aux = dados->vetor[i];
                dados->vetor[i] = dados->vetor[i+1];
                dados->vetor[i+1] = aux;

                changes++;
                trocas++;

                for (j=0; j<dados->final; j++){
                    printf("%d ", dados->vetor[j]);
                }
                printf("%d\n", dados->vetor[j]);
            }
        }

        if (changes!=0){
            changes=0;
        }
        else{
            break;
        }
    }

    //Imprime o vetor ordenado final.
    for (j=0; j<dados->final; j++){
        printf("%d ", dados->vetor[j]);
    }
    printf("%d\n", dados->vetor[j]);
    printf("Trocas: %d\n", trocas);
}