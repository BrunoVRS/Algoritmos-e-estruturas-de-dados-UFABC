#include <stdio.h>
#include <stdlib.h>

struct lista{

    int inicio, final;
    int *vetor;
};

void insertion (struct lista *dados);
void mostra(struct lista *dados);

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

    //Mostrando o primeiro elemento a ser SUPOSTAMENTE INSERIDO:
    mostra(dados);


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
    //Para cada elemento supostamente inserido
    dados->inicio++;

    mostra(dados);
    }


}

void mostra(struct lista* dados){
    int k;

    printf("Sublista Ordenada:");
    for (k=0; k<dados->inicio; k++){
        printf(" %d", dados->vetor[k]);
    }
    printf(" %d\n", dados->vetor[k]);


    printf("Sublista Desordenada:");
    for (k=dados->inicio+1; k<dados->final; k++){
        printf(" %d", dados->vetor[k]);
    }
    if (k>dados->final){
        printf("\n");
    }
    else{
        printf(" %d\n", dados->vetor[k]);
    }

}