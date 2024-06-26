#include <stdio.h>
#include <string.h>

// Definição da estrutura da pilha
struct PilhaFrases {
    char palavras[5000];
    int topo;
};

typedef struct PilhaFrases PilhaFrase;

// Função para verificar se a pilha está vazia
int vazio(PilhaFrase *PilhaFrase) {
    return (PilhaFrase->topo == -1);
}

// Função para empilhar um caractere na pilha
void push(PilhaFrase *PilhaFrase, char c) {
    if (PilhaFrase->topo < 5000 - 1) {
        PilhaFrase->palavras[++PilhaFrase->topo] = c;
    }
}

// Função para desempilhar um caractere da pilha
char pop(PilhaFrase *PilhaFrase) {
    if (!vazio(PilhaFrase)) {
        return PilhaFrase->palavras[PilhaFrase->topo--];
    }
    return '\0';
}

// Função principal para verificar a sintaxe do texto
int verificaSintaxe(char texto[], int tam) {
    
    char c, topo;
    int i;
    
    PilhaFrase PilhaFrase;
    PilhaFrase.topo = -1;
    
    for (i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '*' || texto[i] == '/' || texto[i] == '_') {
            if (vazio(&PilhaFrase) || PilhaFrase.palavras[PilhaFrase.topo] != texto[i]) {
                push(&PilhaFrase, texto[i]);
            } else {
                c = pop(&PilhaFrase);
                if ((c == '*' && texto[i] != '*') ||
                    (c == '/' && texto[i] != '/') ||
                    (c == '_' && texto[i] != '_')) {
                    return 0; // Sintaxe incorreta
                }
            }
        }
    }

    // Verifica se a pilha está vazia no final (todas as formatações foram fechadas corretamente)
    return vazio(&PilhaFrase);
}

int main(void) {
    char frase[5000];
    int tam, i;
    printf("Digite uma frase: ");
    scanf(" %[^\n]", frase);

    tam = strlen(frase);
    
    if (verificaSintaxe(frase, tam)) {
        printf("Sintaxe correta\n");
    } else {
        printf("Sintaxe incorreta\n");
    }

    printf("\n");
    return 0;
}