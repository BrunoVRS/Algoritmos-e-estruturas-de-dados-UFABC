#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *proximo;
};

struct No *cria_no(int valor);
int insere(struct No *head, struct No *tail, struct No *novo_no);
void mostra_lista(struct No* head, struct No* tail);
int busca(struct No *head, struct No *tail, int valor);
void remover(struct No* head, struct No* tail, int valor);


int main(){
    struct No *head = (struct No*) malloc(sizeof(struct No));
    struct No *tail = (struct No*) malloc(sizeof(struct No));

    struct No* novo_no, *atual, *sucessor;

    int qtd_pares, qtd_elementos, valor;


    int i, k;


    scanf("%d", &qtd_pares);

    //Para cada par, a gente ja esta salvando diretamente em uma unica lista.
    for (i=0; i<qtd_pares; i++){
        scanf("%d", &qtd_elementos);

        // SE A LISTA NÃO ESTIVER VAZIA:
        if (qtd_elementos != 0){
            //a gente le a primeira lista:
            for (k=0; k<qtd_elementos; k++){
                scanf("%d", &valor);
                novo_no = cria_no(valor);
                insere(head, tail, novo_no);

            }
        }


        scanf("%d", &qtd_elementos);
        // SE A LISTA NÃO ESTIVER VAZIA:
        if (qtd_elementos != 0){
            //a gente le a segunda lista

            for (k=0; k<qtd_elementos; k++){
                scanf("%d", &valor);
                novo_no = cria_no(valor);
                insere(head, tail, novo_no);
            }
        }
        //agora a gente printa a lista, se ela não estiver vazia:
        if (head->proximo != NULL){

            mostra_lista(head, tail);

            //agora a gente limpa a lista:
            atual = head->proximo;
            sucessor = atual->proximo;
            head->proximo = NULL;
            while(sucessor!=tail){
                free(atual);
                atual = sucessor;
                sucessor = sucessor->proximo;
            }
            free(atual);
        }
    }
}




//funçao que retorna um nó
struct No *cria_no(int valor){

    struct No* novo_no = (struct No*) malloc(sizeof(struct No));
    novo_no->valor = valor;

    return novo_no;

}


//Vamos passar por referencia, pois os elementos dessa lista serão manipulados
int insere(struct No *head, struct No *tail, struct No *novo_no){
    struct No *atual;
    struct No *sucessor;

    if (head->proximo == NULL){
        //entao a gente aponta para o novo no
        head->proximo = novo_no;
        novo_no->proximo = tail;
    }

    //Caso ja exista algum no no sistema:
    else{
        //entao a gente vai definir dois nois, para podermos depois, colocar o no no meio destes:
        atual = head;
        sucessor = head->proximo;

        while(sucessor != tail){
            if(sucessor->valor > novo_no->valor){
                novo_no->proximo = sucessor;
                atual->proximo = novo_no;
                //precisei do return para parar assim que o no for adicionado a lista
                return 0;
            }
            //'else' a gente atualiza as variaveis para uma nova iteração
            atual=sucessor;
            sucessor = sucessor->proximo;

        }
        //caso tenha chego até aqui, é porque sucessor = tail e novo no > sucessor. logo:
        atual->proximo = novo_no;
        novo_no->proximo = tail;

    }

}



void mostra_lista(struct No* head, struct No* tail){
    //Se a lista não estiver vazia:
    if (head->proximo != NULL){
        struct No* atual = head->proximo;

        while(atual != tail){
            //tirando o espaço do ultimo elemento na hora de printar:
            if (atual->proximo == tail){
                printf("%d\n", atual->valor);
            }
            //caso contrario, printa com um espaço:
            else{
                printf("%d ", atual->valor);
            }
            atual = atual->proximo;
        }

    }

}


int busca(struct No *head, struct No *tail, int valor){
    struct No* atual;

    //Caso a lista não seja vazia:
    if (head->proximo != NULL){

        atual = head->proximo;
        while (atual!=tail){
            if (atual->valor == valor){
                return 1;
            }
            //caso contrario:
            atual = atual->proximo;
        }
        //se chegou até aqui, é pq nao encontrou o valor;
        return 0;
    }
    else{
        return 0;
    }
}

void remover(struct No* head, struct No* tail, int valor){
    struct No* atual;
    struct No* sucessor;

    atual = head;
    sucessor = atual->proximo;

    while (sucessor!=tail){
        //se o 'sucessor' for quem estamos procurando:
        if (sucessor->valor == valor){
            //A gente simplesmente faz um jump sobre o 'sucessor'
            atual->proximo = sucessor->proximo;
            break;
        }
        //caso contrario:
        atual = sucessor;
        sucessor = sucessor->proximo;
    }

}
