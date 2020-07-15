#include <stdio.h>
#include <stdlib.h>

struct lista{

    int inicio, final;
    double *vetor;
};

void insertion (struct lista *dados);
void mostra(struct lista *dados);

int main(){

    int tamanho, inicio;
    double valor;
    int i, j;


    float mediana;

    scanf("%d", &tamanho);



    //iniciando a variavel que vai carregar o vetor:
    struct lista *dados = (struct lista*)malloc(sizeof(struct lista));
    dados->final = tamanho-1;
    //Alocando um espaço para o vetor
    dados->vetor = (double*)malloc(tamanho*sizeof(int));
    dados->inicio = 0;


    for (i=0; i<tamanho; i++){
      scanf("%lf", &valor);
      //agora, inserimos o valor no vetor:
      dados->vetor[i] = valor;

    }

    insertion(dados);
   // printf("%d\n", tamanho);


    //se for par:
    if (tamanho%2 == 0){
        mediana = (dados->vetor[(tamanho-1)/2] + dados->vetor[(tamanho/2)])/2.0;

        printf("%.2f\n", mediana);
    }

    //se for impar:
    else{
        mediana = dados->vetor[(tamanho)/2];
        printf("%.2f\n", mediana);
    }
    //mostra(dados);

}


void insertion (struct lista *dados){

    int i, k, j, aux;

    //Paraca cada elemento do dados->vetor. i=1 pois o primeiro elemento já é assumido entrar logo de cara. Entao, a gente começa a partir do segundo elemento.
    for (i=1; i<= dados->final; i++){
        //Para cada elemento já ordenado:
        for(j=0; j<i; j++){
            if (dados->vetor[i] < dados->vetor[j]){
                //Entao a gente desloca todo mundo, de j até i, e coloca o valor de i em j
                aux = dados->vetor[i];
                for(k=i; k>j; k--){
                    dados->vetor[k] = dados->vetor[k-1];
                }
                //agora a gente posiciona o valor de aux na posição q antes era do j:
                dados->vetor[j] = aux;
            }
        }
    }

    //mostra(dados);

}

void mostra(struct lista* dados){
    int k;

    for (k=0; k<dados->final; k++){
        printf("%lf ", dados->vetor[k]);
    }
    printf("%lf\n", dados->vetor[k]);


}