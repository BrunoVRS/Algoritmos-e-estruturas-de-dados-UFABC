#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
    struct Node *antecessor;
};


struct Arvore{
    struct Node *root;
};

void InOrder(struct Node* head);
void PreOrder(struct Node* head);
void PostOrder(struct Node* head);
struct Node *CriaNo(int valor);
void AlojaNo(struct Node *head, struct Node *No);
struct Node* abb_retira(struct Node* r, int v);
struct Node* abb_busca (struct Node* r, int v);

int main(){

    int valor;
    char comando[11];


    //Define quem é o head.
    struct Arvore *arvore = (struct Arvore*)malloc(sizeof(struct Arvore));
    struct Node *No;



    while(scanf("%s", comando) != EOF){
        if (strcmp(comando, "insert") == 0){

            scanf("%d", &valor);
            No = CriaNo(valor);

            if (arvore->root == NULL){
                arvore->root = No;
            }
            else{
                AlojaNo(arvore->root, No);
            }
        }

        else if (strcmp(comando, "in-order") == 0){
            InOrder(arvore->root);
            printf("\n");
        }

        else if (strcmp(comando, "pre-order") == 0){
            PreOrder(arvore->root);
            printf("\n");
        }

        else if (strcmp(comando, "post-order") == 0){
            PostOrder(arvore->root);
            printf("\n");
        }

        else if (strcmp(comando, "delete") == 0){
            scanf("%d", &valor);
            struct Node* no = abb_busca (arvore->root, valor);
            if (no != NULL){
                printf("%d\n", no->valor);
            }
            abb_retira(arvore->root, valor);
        }
    }
}

struct Node *CriaNo(int valor){
    //Cria um ponteiro de Node:
    struct Node *No = (struct Node*)malloc(sizeof(struct Node));
    No->valor = valor;
    No->esquerda = NULL;
    No->direita = NULL;
    return No;
}

void AlojaNo(struct Node *root, struct Node *No){
    struct Node *head = root;


    //Senao, se o novo valor for menor do que o valor do head, a gente ve se existe um No a esquerda. Caso exista, a gente chama novamente a função, usando agora este nó como pivo.
    if(head->valor > No->valor){

        //Caso não exista nó a esquerda, a gente coloca o novo valor lá
        if (head->esquerda == NULL){
            head->esquerda = No;
            head->esquerda->antecessor = head;

        }
        else{
            //Se não, a gente chama recursivamente a função, passando como pivo o nó a esquerda.
            AlojaNo(head->esquerda, No);
        }
    }

    else if(head->valor <= No->valor){

        //Caso não exista nó a direita, a gente coloca o novo valor lá
        if (head->direita == NULL){
            head->direita = No;
            head->direita->antecessor = head;
        }
        else{
            //Se não, a gente chama recursivamente a função, passando como pivo o nó a direita.
            AlojaNo(head->direita, No);
        }
    }

}



void InOrder(struct Node* head){

    if(head != NULL){
        InOrder(head->esquerda);
        printf("%d ",head->valor);
        InOrder(head->direita);
    }


}

void PreOrder(struct Node* head){
    if(head!= NULL){
        printf("%d ", head->valor);
        PreOrder(head->esquerda);
        PreOrder(head->direita);
    }

}

void PostOrder(struct Node* head){
    if(head!= NULL){
        PostOrder(head->esquerda);
        PostOrder(head->direita);
        printf("%d ", head->valor);
    }
}




struct Node* abb_retira(struct Node* r, int v){

    if (r == NULL){
        return NULL;
    }

    else if (r->valor > v){
        r->esquerda = abb_retira(r->esquerda, v);
    }

    else if (r->valor < v){
        r->direita = abb_retira(r->direita, v);
    }

    else { /* achou o nó a remover */
        /* nó sem filhos */
        if (r->esquerda == NULL && r->direita == NULL) {
        free (r);
        r = NULL;
        }

     /* nó só tem filho à direita */
        else if (r->esquerda == NULL) {
            struct Node* t = r;
            r = r->direita;
            free (t);
        }

        /* só tem filho à esquerda */
        else if (r->direita == NULL) {
            struct Node* t = r;
            r = r->esquerda;
            free (t);
        }
         /* nó tem os dois filhos */
        else {
            struct Node* f = r->direita;
            while (f->esquerda != NULL) {
                f = f->esquerda;
            }
            r->valor = f->valor; /* troca as informações */
            f->valor = v;
            r->direita = abb_retira(r->direita,v);
        }

    }

    return r;
}

struct Node* abb_busca (struct Node* r, int v){
    if (r == NULL){
        return NULL;
    }
    else if (r->valor > v){
        return abb_busca (r->esquerda, v);
    }
    else if (r->valor < v){
        return abb_busca (r->direita, v);
    }
    else{
        return r;
    }
}