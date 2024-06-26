#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da pilha
typedef struct {
    int *itens;
    int topo;
    int capacidade;
} Pilha;

// Funções para manipulação da pilha
void inicializarPilha(Pilha *pilha, int capacidade) {
    pilha->itens = (int *)malloc(capacidade * sizeof(int));
    pilha->topo = -1;
    pilha->capacidade = capacidade;
}

int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int pilhaCheia(Pilha *pilha) {
    return pilha->topo == pilha->capacidade - 1;
}

void empilhar(Pilha *pilha, int valor) {
    if (!pilhaCheia(pilha)) {
        pilha->topo++;
        pilha->itens[pilha->topo] = valor;
    } else {
        printf("Erro: pilha cheia.\n");
    }
}

int desempilhar(Pilha *pilha) {
    if (!pilhaVazia(pilha)) {
        int valor = pilha->itens[pilha->topo];
        pilha->topo--;
        return valor;
    } else {
        printf("Erro: pilha vazia.\n");
        return -1;
    }
}

// Função para conversão de decimal para binário, octal ou hexadecimal
void converterBase(int decimal, int base) {
    Pilha pilha;
    inicializarPilha(&pilha, 100);

    while (decimal > 0) {
        int resto = decimal % base;
        empilhar(&pilha, resto);
        decimal /= base;
    }

    printf("Resultado da conversao: ");
    while (!pilhaVazia(&pilha)) {
        int valor = desempilhar(&pilha);

        // Imprime o valor no formato adequado para binário, octal ou hexadecimal
        if (base == 2) {
            printf("%d", valor);
        } else if (base == 8) {
            printf("%d", valor);
        } else if (base == 16) {
            printf("%X", valor);
        }
    }

    printf("\n");
}

int main() {
    int decimal, opcao[10];

    printf("Digite um numero decimal: ");
    scanf("%d", &decimal);

    printf("Escolha a base para conversao:\n");
    printf("(a) Decimal para Binario\n");
    printf("(b) Decimal para Octal\n");
    printf("(c) Decimal para Hexadecimal\n");
    printf("Opcao: ");
    scanf("%s", opcao);

    if (strcmp(opcao, "a") == 0)
    {
       converterBase(decimal, 2);
    }
    if (strcmp(opcao, "b") == 0)
    {
       converterBase(decimal, 8);
    }
    if (strcmp(opcao, "c") == 0)
    {
       converterBase(decimal, 16);
    }

    return 0;
}
