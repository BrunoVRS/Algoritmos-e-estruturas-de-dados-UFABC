#include <stdio.h>
#include <stdlib.h>

struct heap{
    int* vetor;
    int n;

};


int max_heapify(struct heap* heap);
struct heap* createheap(int n);
void mostra_vetor(int* vetor, int n);
void maxHeap(struct heap* heap);

int main(){

    int n, valor, i;

    scanf("%d", &n);

    while (n>0){
        struct heap* heap = createheap(n);
        heap->n = n;

        for(i=0; i<n; i++){
            scanf("%d", &valor);
            heap->vetor[i] = valor;
        }

        maxHeap(heap);
        mostra_vetor(heap->vetor, heap->n);

        free(heap->vetor);
        free(heap);

        scanf("%d", &n);
    }

}

struct heap* createheap(int n){
    struct heap* newheap = (struct heap*)malloc(sizeof(struct heap));
    newheap->vetor = (int*)malloc(n*sizeof(int));

    return newheap;
}
void maxHeap(struct heap* heap){
    int trocas;

    //Se houve alguma troca na heap:
    trocas = max_heapify(heap);
    if (trocas>0){
        maxHeap(heap);
    }


}


int max_heapify(struct heap* heap){

    int i, aux;
    int trocas = 0;
    int left, right;

    int n = heap->n;

    for(i=(n/2)-1; i>=0; i--){
        left = (2*i)+1;
        right = (2*i)+2;
        //printf("Right = %d\n", right);

        if(right < n){

            if (heap->vetor[left] < heap->vetor[right]){
                if(heap->vetor[i] > heap->vetor[left]){
                    aux = heap->vetor[i];
                    heap->vetor[i] = heap->vetor[left];
                    heap->vetor[left] = aux;
                    trocas++;
                }
            }

            else{
                if(heap->vetor[i] > heap->vetor[right]){
                    aux = heap->vetor[i];
                    heap->vetor[i] = heap->vetor[right];
                    heap->vetor[right] = aux;
                    trocas++;
                }
            }
        }
        else{
            if(heap->vetor[i] > heap->vetor[left]){
                    aux = heap->vetor[i];
                    heap->vetor[i] = heap->vetor[left];
                    heap->vetor[left] = aux;
                    trocas++;
            }

        }
    }
    return trocas;
}


void mostra_vetor(int* vetor, int n){
    int i;


    for(i=0; i<n-1; i++){
        printf("%d ", vetor[i]);
    }
    printf("%d\n", vetor[n-1]);

}