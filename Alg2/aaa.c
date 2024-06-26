#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Definição da estrutura do nó da lista
struct Node {
    char data;
    struct Node* next;
};

// Função para adicionar um novo nó no final da lista
void append(struct Node** head_ref, char new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Função para modificar a sequência da lista conforme descrito
void seqmodificada(struct Node** lista) {
    struct Node *puc, *pa, *pud, *aux, *atual;

    // Encontrar o último caractere (puc)
    puc = *lista;
    while (puc->next != NULL) {
        puc = puc->next;
    }

    atual = *lista;
    pa = NULL;

    while (atual != NULL && atual->next != puc){
        if (atual->data >= '0' && atual->data <= '9') {
            if (pa == NULL) {
                *lista = atual->next;
                aux = atual;
            }
                if (puc->next == NULL) {
                    aux = atual;
                    pa->next = atual->next;
                    puc->next = aux;
                    aux->next = NULL;
                    aux = atual;
                    
                } else {
                    aux = atual;
                    pud = aux;
                    pa->next = aux->next;
                    puc->next = aux;
                    aux->next = pud;
                    aux = atual;
                }
        }
        pa = atual;
        atual = atual->next;
    }
}

// Função para imprimir a lista
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Função principal
int main() {
    // Exemplo de lista encadeada: A 1 E 5 T 7 W 8 G
    struct Node* head = NULL;
    append(&head, 'A');
    append(&head, '1');
    append(&head, 'E');
    append(&head, '5');
    append(&head, 'T');
    append(&head, '7');
    append(&head, 'W');
    append(&head, '8');
    append(&head, 'G');

    printf("Lista original: ");
    printList(head);

    seqmodificada(&head);

    printf("Lista modificada: ");
    printList(head);

    return 0;
}
