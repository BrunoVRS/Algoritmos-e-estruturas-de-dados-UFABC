#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    int *anterior;
    int *proximo;
};

void mostra_lista(struct No* head, struct No* tail);
void insere(struct No* head, struct No* tail, struct No* novo_no);

int main(){
    int valor;
    char key;

    struct No* novo;


    struct No* head = (struct No*)malloc(sizeof(struct No));
    struct No* tail = (struct No*)malloc(sizeof(struct No));



    while (scanf("%c\n", &key) != EOF){
        if (key == 'I'){
            scanf("%d", valor;)
            novo = cria_no(head, tail, valor);
            insere(head, tail, novo);
        }

    }
    mostra_lista(head, tail);
}

struct No* cria_no(struct No* head, struct No* tail, int valor){
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    novo->valor = valor;

    return novo;
}

void insere(struct No* head, struct No* tail, struct No* novo_no){
    struct No *atual;
    struct No *sucessor;

    if (head->proximo == NULL){
        //entao a gente aponta para o novo no
        head->proximo = novo_no;
        novo_no->proximo = tail;
        //e a gente aponta de volta:
        novo_no->anterior = head;
        tail->anterior = novo_no;

    }

    //Caso ja exista algum no no sistema:
    else{
        //entao a gente vai definir dois nois, para podermos depois, colocar o no no meio destes:
        atual = head;
        sucessor = head->proximo;

        while(sucessor != tail){
            if(sucessor->valor > novo_no->valor){
                novo_no->proximo = sucessor;
                sucessor->anterior = novo_no;
                atual->proximo = novo_no;
                novo_no->anterior = atual;

                //precisei do return para parar assim que o no for adicionado a lista
                return 0;
            }
            //'else' a gente atualiza as variaveis para uma nova iteração
            atual=sucessor;
            sucessor = sucessor->proximo;

        }
        //caso tenha chego até aqui, é porque sucessor = tail e novo no > sucessor. logo:
        atual->proximo = novo_no;
        novo_no->anterior = atual;
        novo_no->proximo = tail;
        tail->anterior = novo_no

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