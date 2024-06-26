#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura da pilha
struct PilhaFrases{
    char palavras[20];
    int topo;
};

typedef struct PilhaFrases PilhaFrase;

// Função para verificar se a pilha está vazia
int vazio(PilhaFrase *PilhaFrase) {
    return (PilhaFrase->topo == -1);
}

// Função para empilhar um caractere na pilha
void push(PilhaFrase *PilhaFrase, char c) {
    if (PilhaFrase->topo < 20 - 1) {
        PilhaFrase->palavras[++PilhaFrase->topo] = c;
    }
}

// Função para desempilhar um caractere da pilha
char pop(PilhaFrase *PilhaFrase) {
    if (!vazio(PilhaFrase)) {
        PilhaFrase->topo--;
        return PilhaFrase->palavras[PilhaFrase->topo];
    }
    return '\0';
}

int main(void) {
    char frase[100];
    int tam, i;
    printf("Digite uma frase: ");
    scanf(" %[^\n]", frase);

    tam = strlen(frase);
    PilhaFrase PilhaFrase;
    PilhaFrase.topo = -1;

    for (i = 0; i <= tam; i++) {
        if (frase[i] != ' ' && frase[i] != '\0' && frase[i] != '\n') {
            // Empilha caracteres da palavra
            push(&PilhaFrase, frase[i]);
        } else {
            // Desempilha e imprime caracteres da palavra
            while (!vazio(&PilhaFrase)) {
                printf("%c", pop(&PilhaFrase));
            }
            // Imprime espaço ou quebra de linha
            printf("%c", frase[i]);
        }
    }

    printf("\n");
    return 0;
}   