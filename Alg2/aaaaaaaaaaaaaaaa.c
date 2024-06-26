#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista encadeada
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Função para imprimir a lista encadeada
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Função para adicionar um novo nó ao final da lista
void append(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
}

// Função para rotacionar a lista à direita k vezes
void rotateRight(Node** head_ref, int k) {
    Node* current = *head_ref;

    Node* previous = NULL;

    // Move para o nó que se tornará o novo final
    for (int i = 0; i < k; i++) {
        current = *head_ref;
        while(current->next != NULL){

            previous = current;
            current = current->next;

        }
        // Ajusta os ponteiros para realizar a rotação
        previous->next = NULL;
        current->next = *head_ref;
        *head_ref = current;
    }

}


// Função principal
int main() {
    // Exemplo de uso
    Node* L = NULL;
    int k = 1;

    // Adiciona elementos à lista
    append(&L, 1);
    append(&L, 7);
    append(&L, 4);
    append(&L, 9);
    append(&L, 8);
    append(&L, 3);
    append(&L, 2);
    append(&L, 6);

    printf("Lista original: ");
    printList(L);

    // Realiza a rotação à direita
    rotateRight(&L, k);

    printf("Lista rotacionada %d vezes à direita: ", k);
    printList(L);

    return 0;
}