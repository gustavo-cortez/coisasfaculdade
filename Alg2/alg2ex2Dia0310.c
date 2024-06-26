#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da lista encadeada
struct sequen {
    int num;
    struct sequen* prox;
};

typedef struct sequen seq;

// Função para inserir um elemento no final de uma lista encadeada
void insere(seq** lista, int item) {
    seq* p, * q, * nova;
    p = *lista;
    q = NULL;
    nova = (seq*)malloc(sizeof(seq));
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
// Função para inserir um elemento em ordem não decrescente em uma lista encadeada
void insereNaoDecrescente(seq** lista, int item) {
    seq* nova = (seq*)malloc(sizeof(seq));
    nova->num = item;
    nova->prox = NULL;

    seq* atual = *lista;
    seq* anterior = NULL;

    while (atual != NULL && atual->num <= item) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        nova->prox = *lista;
        *lista = nova;
    } else {
        anterior->prox = nova;
        nova->prox = atual;
    }
}

// Função para inserir um elemento em ordem não crescente em uma lista encadeada
void insereNaoCrescente(seq** lista, int item) {
    seq* nova = (seq*)malloc(sizeof(seq));
    nova->num = item;
    nova->prox = NULL;

    seq* atual = *lista;
    seq* anterior = NULL;

    while (atual != NULL && atual->num >= item) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        nova->prox = *lista;
        *lista = nova;
    } else {
        anterior->prox = nova;
        nova->prox = atual;
    }
}


// Função para imprimir os elementos de uma lista encadeada
void mostra(seq* lista) {
    seq* p;
    while (lista != NULL) {
        p = lista;
        printf("%d ", p->num);
        lista = lista->prox;
    }
}

// Função para separar os números pares e ímpares em listas diferentes
void separa(seq** lista, seq** pares, seq** impares) {
    seq* p = *lista;
    seq* q = NULL;
    while (p != NULL) {
        if (p->num % 2 == 0) {
            insereNaoDecrescente(pares, p->num);
        } else {
            insereNaoCrescente(impares, p->num);
        }
        q = p;
        p = q->prox;
    }
}

// Função recursiva para encontrar o elemento com o maior valor em uma lista
int encontrarMaiorRec(seq* lista, int max) {
    if (lista == NULL) {
        return max;
    } else {
        int valor_atual = lista->num;
        if (valor_atual > max) {
            return encontrarMaiorRec(lista->prox, valor_atual);
        } else {
            return encontrarMaiorRec(lista->prox, max);
        }
    }
}

int encontrarMaior(seq* lista) {
    if (lista == NULL) {
        return INT_MIN;
    } else {
        return encontrarMaiorRec(lista->prox, lista->num);
    }
}

// Função recursiva para encontrar o elemento com o menor valor em uma lista
int encontrarMenorRec(seq* lista, int min) {
    if (lista == NULL) {
        return min;
    } else {
        int valor_atual = lista->num;
        if (valor_atual < min) {
            return encontrarMenorRec(lista->prox, valor_atual);
        } else {
            return encontrarMenorRec(lista->prox, min);
        }
    }
}

int encontrarMenor(seq* lista) {
    if (lista == NULL) {
        return INT_MAX;
    } else {
        return encontrarMenorRec(lista->prox, lista->num);
    }
}

// Função recursiva para contar quantos números iguais a x existem em uma lista
int contarIguais(seq* lista, int x) {
    if (lista == NULL) {
        return 0;
    } else {
        int ocorrencias_resto = contarIguais(lista->prox, x);
        if (lista->num == x) {
            return 1 + ocorrencias_resto;
        } else {
            return ocorrencias_resto;
        }
    }
}

// Função recursiva para calcular o tamanho de uma lista
int calcularTamanho(seq* lista) {
    if (lista == NULL) {
        return 0;
    } else {
        return 1 + calcularTamanho(lista->prox);
    }
}

int main() {
    seq* lista = NULL;
    seq* pares = NULL;
    seq* impares = NULL;

    int n, num, maior, menor, x, cont_x, tamanho_lista;

    printf("Quantos números deseja inserir? ");
    scanf("%d", &n);

    printf("Digite os números:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insere(&lista, num);
    }

    separa(&lista, &pares, &impares);

    printf("Lista com todos os elementos: ");
    mostra(lista);
    printf("\n");

    printf("Lista com números pares ordenados não decrescentemente: ");
    mostra(pares);
    printf("\n");

    printf("Lista com números ímpares ordenados não crescentemente: ");
    mostra(impares);
    printf("\n");

    maior = encontrarMaior(lista);
    menor = encontrarMenor(lista);

    printf("Dê o número a ser procurado.\n");
    scanf("%d",&x);
    cont_x = contarIguais(lista, x);
    tamanho_lista = calcularTamanho(lista);

    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
    printf("Quantidade de %d na lista: %d\n", x, cont_x);
    printf("Tamanho da lista: %d\n", tamanho_lista);

    // Libera a memória alocada para os nós das listas
    while (lista != NULL) {
        seq* temp = lista;
        lista = lista->prox;
        free(temp);
    }
    while (pares != NULL) {
        seq* temp = pares;
        pares = pares->prox;
        free(temp);
    }
    while (impares != NULL) {
        seq* temp = impares;
        impares = impares->prox;
        free(temp);
    }

    return 0;
}
