#include <stdio.h>
#include <stdlib.h>


int main(){
    int tamanho, valor;

    int i, j, contador, contador_inverso;

    while (scanf("%d", &tamanho)!= EOF){
        if (tamanho>0){

            //Vou definir o vetor aqui, pra ficar mais intuitivo de ler o que ta rolando;
            int vetor[tamanho];

            for (i=0; i<tamanho; i++){
                scanf("%d", &valor);
                vetor[i] = valor;

            }

            contador=0;
            contador_inverso=0;
            //Agora que ja leu o vetor todo, vamos ver se está ordenado:
            for(j=0; j<tamanho-1; j++){
                if(vetor[j]>vetor[j+1]){
                    contador++;
                }
                else if(vetor[j] < vetor[j+1]){
                    contador_inverso++;
                }
                else if(vetor[j] == vetor[j+1]){
                    contador++;
                    contador_inverso++;
                }
            }

            //Agora vamos ver se estava ordena crescente:
            if (contador == tamanho-1){
                printf("S\n");
            }
            else if(contador_inverso == tamanho-1){
                printf("S\n");
            }
            else{
                printf("N\n");
            }


        }

        else{
            printf("S\n");
        }


    }
}
