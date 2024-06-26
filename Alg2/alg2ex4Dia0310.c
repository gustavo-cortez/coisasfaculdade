#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da lista encadeada
struct listaCircular {
    int num;
    struct listaCircular* prox;
    struct listaCircular* ant;
};

typedef struct listaCircular listaCir;

// Função para inserir um elemento no final de uma lista encadeada
void insere(listaCir** lista, int item) {
    listaCir* p, * q, * nova;
    p = *lista;
    q = NULL;
    nova = (listaCir*)malloc(sizeof(listaCir));
    if (nova != NULL) {
        nova->num = item;
        nova->prox = NULL;
        if (*lista != NULL) {
            p = *lista;
            while (p != NULL) {
                q = p;
                p = q->prox;
            }
            q->prox = nova;
        } else {
            *lista = nova;
        }
    }
}

// Função para imprimir os elementos de uma lista encadeada
void mostra(listaCir* lista) {
    listaCir* p;
    while(lista != NULL){
        p = lista;
        printf("%d ", p->num);
        lista = lista->prox;
    }
}

// Função para concatenar duas listas circulares
listaCir* concatenar(listaCir* lista1, listaCir* lista2) {
    if (lista1 == NULL){
         return lista2;
    }
    if (lista2 == NULL){
         return lista1;
    }
    listaCir* lista1Fim = lista1->ant;
    listaCir* lista2Fim = lista2->ant;

    lista1Fim->prox = lista2;
    lista2Fim->prox = lista1;

    return lista1;
}

// Função para intercalar duas listas circulares
listaCir* intercalar(listaCir* lista1, listaCir* lista2) {
    if (lista1 == NULL) return lista2;
    if (lista2 == NULL) return lista1;

    listaCir* lista1Fim = lista1->ant;
    listaCir* lista2Fim = lista2->ant;

    lista1Fim->prox = lista2;
    lista2Fim->prox = lista1;

    return lista1;
}

// Função principal
int main() {
    listaCir* lista1 = NULL;
    listaCir* lista2 = NULL;

    int n, num;

    printf("Quantos números deseja inserir? ");
    scanf("%d", &n);

    printf("Digite os números da lista 1:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insere(&lista1, num);
    }
    printf("Digite os números da lista 2:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insere(&lista2, num);
    }
    printf("Lista 1: \n");
    mostra(lista1);
    printf("\n");
    printf("Lista 2: \n");
    printf("\n");
    mostra(lista2);

    listaCir* ListaConcatenada = concatenar(lista1, lista2);
    printf("Lista concatenada: \n");
    mostra(ListaConcatenada);
    printf("\n");
    listaCir* ListaIntercalada = intercalar(lista1, lista2);
    printf("Lista intercalada: \n");
    mostra(ListaIntercalada);

    return 0;
}
