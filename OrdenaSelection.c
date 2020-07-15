#include <stdio.h>
#include <stdlib.h>

struct lista{

    int inicio, final;
    int *vetor;
};


void selection (struct lista *dados);


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
    selection(dados);

    free(dados);
}

//Vai ser void pq a gente ta passando por referencia.
void selection (struct lista *dados){

    int min, i, index, j;
    int contador=0;

    while(dados->inicio < dados->final){
        //inicializa o min com sendo o primeiro elemento disponivel
        i = dados->inicio;

        min = dados->vetor[i];
        index = i;

        while(i<dados->final){
            if (dados->vetor[i+1] < min){
                min = dados->vetor[i+1];
                index = i+1;
                contador++;
            }
            i++;
        }

        //Agora troca o valor de minimo com o valor do index dados->inicio
        dados->vetor[index] = dados->vetor[dados->inicio];
        dados->vetor[dados->inicio] = min;

        dados->inicio++;


        for (j=0; j<dados->final; j++){
            printf("%d ", dados->vetor[j]);
        }
        printf("%d\n", dados->vetor[j]);


    }
    for (j=0; j<dados->final; j++){
        printf("%d ", dados->vetor[j]);
    }
    printf("%d\n", dados->vetor[j]);
    printf("%d\n", contador);
}