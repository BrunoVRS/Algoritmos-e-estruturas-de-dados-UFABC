#include <stdio.h>
#include <stdlib.h>

//ficou lindo. pqp.


//Creation of struct fila:
struct Obj_fila{
    //vetor de inteiro
    int *vetor;
    int inicio;
    int final;
};

//Prototipo
void remover(struct Obj_fila *fila1);
void mostrar_fila(struct Obj_fila *fila1);


int main(){
    int n, valor;
    char operacao;

    scanf("%d", &n);

    //Instanciando uma variavel do tipo Obj_fila
    struct Obj_fila *fila1;
    fila1->vetor = (int*) malloc(n*sizeof(int));

    fila1->final = 0;
    fila1->inicio = 0;

    while (scanf("%c %d", &operacao, &valor)!= EOF){
        if (operacao == 'E'){
            //Verifica se a fila tem espaço
            if (fila1->final != n){
                //Se tiver espaço, poem o valor no primeiro slot vazio
                fila1->vetor[fila1->final] = valor;
                //muda a posição do final.
                fila1->final = fila1->final+1;

                //Vamos ver como ta a fila:
                mostrar_fila(fila1);
            }
            //caso contrario, ignora
        }
        else if(operacao == 'D'){
            //Se a fila não estiver vazia. FILA1->VETOR PEGA O PRIMEIRO ELEMENTO DA LISTA.
            if ((fila1->vetor) != NULL){
                remover(fila1);
                fila1->final= fila1->final-1;
            }
            //caso contrario, ignora
        }
        //Caso contrário (else), ignora.
    }

    //mostrar(fila1);
}

void remover(struct Obj_fila *fila1){
    int i;
    for(i=0; i<fila1->final; i++){
        fila1->vetor[i] = fila1->vetor[i+1];
    }
}

void mostrar_fila(struct Obj_fila *fila1){
    int i;
    for(i=0; i<=fila1->final; i++){
        //Fazendo aritmética de ponteiro
        if(fila1->vetor[i] != 0L){
            printf("%d ", fila1->vetor[i]);

        }
    }
    printf("\n");

}