#include <stdio.h>
#include <stdlib.h>

struct lista{

    int inicio, final;
    int *vetor;
};

void insertion (struct lista *dados);

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

    insertion(dados);
}


void insertion (struct lista *dados){

    int i, k, j, aux;

    for(i=0; i<dados->final; i++){
        if (dados->vetor[dados->final] < dados->vetor[i]){
            //entao a gente desloca a partir de i:
            aux= dados->vetor[dados->final];
            for (j=dados->final-1; j>=i ; j--){
                dados->vetor[j+1] = dados->vetor[j];

                for (k=0; k<dados->final; k++){
                    printf("%d ", dados->vetor[k]);
                }
                printf("%d\n", dados->vetor[k]);

            }
            dados->vetor[i] = aux;

            for (k=0; k<dados->final; k++){
                printf("%d ", dados->vetor[k]);
            }
            printf("%d\n", dados->vetor[k]);

        }


    }

}