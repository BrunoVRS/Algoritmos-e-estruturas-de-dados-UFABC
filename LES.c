#include <stdio.h>
#include <stdlib.h>

struct Lista{
    int *vetor;
    int tamanho;
    int quantidade_alocada;
};

int busca(struct Lista lista, int valor);
void insere(struct Lista* lista, int valor);
void remover(struct Lista* lista, int valor);
void mostrar(struct Lista lista);


int main(){
    int tamanho;
    int valor;
    char chave;

    scanf("%d", &tamanho);

    //inicializando a lista:
    struct Lista lista;
    lista.tamanho = tamanho;
    lista.quantidade_alocada = 0;
    lista.vetor = (int*)malloc(tamanho*sizeof(int));

    int i;
    //iniciando todos os valores deste malloc a ser = 0;
    for(i=0; i<tamanho; i++){
        lista.vetor[i] = 0;
    }


    while(scanf("\n%c", &chave) != EOF){
        if (chave == 'I'){
            scanf("%d", &valor);
            //Se o valor não existir na lista:
            if (busca(lista, valor) == 0){
                //adiciona o valor a lista
                insere(&lista, valor);
            }

            //Caso contrario, nao faz nada
        }
        else if (chave == 'E'){
            scanf("%d", &valor);
            //se o valor EXISTIR na lista:
            if (busca(lista, valor) == 1){
                remover(&lista, valor);
            }
        }
    }

    mostrar(lista);
    free(lista.vetor);

}

int busca(struct Lista lista, int valor){
    int i=0;
    for(i=0; i<lista.quantidade_alocada; i++){
        //Se existir:
        if(lista.vetor[i]==valor){
            return 1;
        }
    }

    //se não der return 1, é porque não achou.
    return 0;
}


void insere(struct Lista* lista, int valor){
    int i;
    int deslocador = lista->quantidade_alocada;

    if (lista->quantidade_alocada < lista->tamanho){

        if (lista->quantidade_alocada == 0){
            lista->vetor[0] = valor;
            lista->quantidade_alocada++;

        }


        else{

            for(i=0; i <= lista->quantidade_alocada; i++){
                if(lista->vetor[i]==0){
                    lista->vetor[i] = valor;
                    lista->quantidade_alocada++;

                    break;
                }

                else if(valor <= lista->vetor[i]){
                    //desloca o povo
                    while(deslocador>i){
                        lista->vetor[deslocador] = lista->vetor[deslocador-1];
                        deslocador--;
                    }
                    lista->vetor[i] = valor;
                    lista->quantidade_alocada++;
                    break;
                }
            }
        }

    }
}


void remover(struct Lista* lista, int valor){
    int j;

    int i=0;
    for(i=0; i<lista->quantidade_alocada; i++){
        //Ao encontrar o elemento:
        if(lista->vetor[i]==valor){
            //A gente começa a deslocar a partir do ponto atual de i, ponto este sendo o inicio de j.
            for (j=i; j<lista->quantidade_alocada; j++){
                //Pega o elemento da frente, e coloca no atual.
                lista->vetor[j] = lista->vetor[j+1];
            }
            lista->quantidade_alocada--;
        }
    }

}




void mostrar(struct Lista lista){

    int i;
    for(i=0; i<lista.quantidade_alocada; i++)
    {
        printf("%d\n", lista.vetor[i]);
    }
}