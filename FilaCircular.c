#include <stdio.h>
#include <stdlib.h>

struct FilaCircular{
    int *vetor;
    int inicio, fim, tamanho;
};

void inclusao(struct FilaCircular* fila, int valor);
void remover(struct FilaCircular* fila);

int main(){

    //Settando as variaveis.
    int tamanho, valor;
    char key;
    struct FilaCircular *fila1 = (struct FilaCircular*)malloc(sizeof(struct FilaCircular));

    //Vamos pegar o tamanho da lista:
    scanf("%d", &tamanho);


    //Agora a gente inicializa as variaveis da lista
    fila1->vetor = (int *)malloc(tamanho * sizeof(int));
    fila1->inicio = 0;
    fila1->fim = 0;
    fila1->tamanho = tamanho;


    while(scanf("%c\n", &key) != EOF){
        if (key == 'E'){
            scanf("%d", &valor);
            inclusao(fila1, valor);
        }

        else if(key == 'D'){
            remover(fila1);
        }
    }
    free(fila1->vetor);
}

void inclusao(struct FilaCircular* fila, int valor){
    //Vou seguir a descrição do site
    int novo_fim = (fila->fim + 1) % fila->tamanho;
    if (novo_fim != fila->inicio){
        fila->vetor[fila->fim] = valor;
        fila->fim = novo_fim;
    }

}

void remover(struct FilaCircular* fila){
    if (fila->inicio != fila->fim){
        printf("%d\n", fila->vetor[fila->inicio]);
        fila->vetor[fila->inicio] = 0;

        fila->inicio = (fila->inicio+1) % fila->tamanho;
    }

}
