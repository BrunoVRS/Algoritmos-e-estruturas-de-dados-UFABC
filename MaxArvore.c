#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct Node {
    int valor;
    struct Node *esquerda;
    struct Node *direita;
    struct Node *antecessor;
    int altura;
};


struct Arvore{
    struct Node *root;
    int maxValue;
};

void InOrder(struct Node* head);
void PreOrder(struct Node* head);
void PostOrder(struct Node* head);
struct Node *CriaNo(int valor);
void AlojaNo(struct Node *head, struct Node *No);
struct Node* abb_retira(struct Node* r, int v);
struct Node* abb_busca (struct Node* r, int v);
int MaxValue(struct Node* atual, struct Arvore* arvore);

int main(){

    int valor;
    int qtd;
    int i;

    //Define quem é o head.
    struct Arvore *arvore = (struct Arvore*)malloc(sizeof(struct Arvore));
    struct Node *No;

    scanf("%d", &qtd);

    i=0;
    while(i<qtd){
        scanf("%d", &valor);
        No = CriaNo(valor);

        if (arvore->root == NULL){
            //Altura da raiz = 0;
            No->altura = 0;
            arvore->root = No;
        }
        else{
            //Se o valor não existir na arvore
            if (abb_busca(arvore->root, valor) == NULL){
                AlojaNo(arvore->root, No);
            }
        }
        i++;
    }


    //Agora que ja leu todo mundo e alojou, vamos medir a altura.
    arvore->maxValue = 0;
    printf("%d\n", MaxValue(arvore->root, arvore));
}


int MaxValue(struct Node* atual, struct Arvore* arvore){
    if(atual != NULL){
        //Primeiro a gente corre tudo a esquerda, depois aos caminhos a direita:
        MaxValue(atual->esquerda, arvore);
        MaxValue(atual->direita, arvore);

    //    printf("Valor: %d Altura: %d\n", atual->valor, atual->altura);

        if (atual->valor > arvore->maxValue){
            arvore->maxValue = atual->valor;
        }

    }
    return arvore->maxValue;

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
            //A ALTURA DO NOVO NÓ É A ALTURA DO ANTECESSOR +1
            head->esquerda->altura = head->esquerda->antecessor->altura +1;


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
            //A ALTURA DO NOVO NÓ É A ALTURA DO ANTECESSOR +1
            head->direita->altura = head->direita->antecessor->altura +1;

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