#include <stdio.h>
#include <stdlib.h>


void intercala(int* , int* , int* , int , int );
void mostra_vetor(int* , int , int );


int main(){

    int q1, q2;

    int i, j, valor;

    //Vamos ler q1 e q2:
    scanf("%d", &q1);
    scanf("%d", &q2);



    int* vetor1 = (int*)malloc(q1*sizeof(int));
    int* vetor2 = (int*)malloc(q2*sizeof(int));
    int* vetor3 = (int*)malloc((q1+q2)*sizeof(int));


    for(i=0; i<q1; i++){
        scanf("%d", &valor);

        vetor1[i] = valor;

    }

    //Ao terminar de ler os valores do vetor 1, vamos ao vetor 2:
    for(j=0; j<q2; j++){
        scanf("%d", &valor);

        vetor2[j] = valor;

    }


    intercala(vetor1, vetor2, vetor3, q1, q2);
    mostra_vetor(vetor3, q1, q2);

}


void intercala(int* vetor1, int* vetor2, int* vetor3, int q1, int q2){

    int i = 0;
    int j = 0;
    int k = 0;


    while (k<q1+q2){
        if (i<q1 && j<q2){
            if (vetor1[i] < vetor2[j]){
                vetor3[k] = vetor1[i];
                i=i+1;

            }
            else{
                vetor3[k] = vetor2[j];
                j=j+1;

            }
        }

        else if(j>=q2 && i<q1){
            vetor3[k] = vetor1[i];
            i=i+1;

        }

        else if(i>=q1 && j<q2){
            vetor3[k] = vetor2[j];
            j=j+1;

        }
    k=k+1;
    }
}


void mostra_vetor(int* vetor3, int q1, int q2){
    int k;

    for(k=0; k<(q1+q2); k++){
        printf("%d\n", vetor3[k]);
    }

}