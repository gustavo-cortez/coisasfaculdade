#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node* next;
};

void append(struct Node** head_ref, char new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

void seqmodificada(struct Node** lista) {
    struct Node *puc, *pa, *pud, *aux, *atual;

    puc = *lista;
    while (puc != NULL && puc->next != NULL) {
        puc = puc->next;
    }

    atual = *lista;
    pa = NULL;
    pud = NULL;
    aux = NULL;

    while (atual != NULL && atual != puc) {
        if (isdigit(atual->data)) {
            if (pa == NULL) {
                *lista = atual->next;
                atual->next = NULL;
                aux = atual;
            } else {
                pa->next = atual->next;
                if (puc != NULL && puc->next == NULL) {
                    pa->next = atual->next;
                    puc->next = atual;
                    atual->next = NULL;
                    pud = aux;
                    aux = atual;
                } else {
                    pa->next = atual->next;
                    if (pud != NULL) {
                        pud->next = atual;
                    }
                    atual->next = pud;
                    aux = atual;
                    pud = aux;
                }
            }
        } else {
            pa = atual;
        }
        atual = atual->next;
    }
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
}

void freeList(struct Node* node) {
    while (node != NULL) {
        struct Node* temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
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

    // Liberar a memória alocada
    freeList(head);

    return 0;
}
