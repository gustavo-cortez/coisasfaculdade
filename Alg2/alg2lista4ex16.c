#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um elemento da pilha
struct Pilha{
    char c;
    struct Pilha* prox;
};
typedef struct Pilha PilhaNotacao;
// Função para criar um novo nó da pilha
PilhaNotacao* criaPilha(char item) {
    PilhaNotacao* novaPilha = (PilhaNotacao*)malloc(sizeof(PilhaNotacao));
    novaPilha->c = item;
    novaPilha->prox = NULL;
    return novaPilha;
}

// Função para verificar se a pilha está vazia
int vazio(PilhaNotacao* topo) {
    return (topo == NULL);
}

// Função para empilhar um elemento na pilha
void push(PilhaNotacao** topo, char item) {
    PilhaNotacao* novaPilha = criaPilha(item);
    novaPilha->prox = *topo;
    *topo = novaPilha;
}

// Função para desempilhar um elemento da pilha
char pop(PilhaNotacao** topo) {
    char desempilhado;
    if (vazio(*topo)) {
        printf("Erro: A pilha está vazia!\n");
        return '\0';
    }
    PilhaNotacao* aux = *topo;
    *topo = (*topo)->prox;
    desempilhado = aux->c;
    free(aux);
    return desempilhado;
}

// Função para verificar a precedência dos operadores
int precedencia(char item) {
    if (item == '+' || item == '-') {
        return 1;
    } 
    else 
        if (item == '*' || item == '/') {
            return 2;
        }else 
            if (item == '(') {
                return 3;
            }
                  
    return 0;
}

// Função para converter a notação infixa em notação posfixa
void infixoPosfixo(char *infixo, char *posfixo) {
    PilhaNotacao* Pilha = NULL;
    int i, j;
    char simb;

    j = 0;

    for (i = 0; infixo[i]; i++) {
        simb = infixo[i];
        if (simb >= 'A' && simb <= 'Z') {
            posfixo[j++] = simb;
        }else if (simb == ')') {
            while (!vazio(Pilha) && Pilha->c != '(') {
                posfixo[j++] = pop(&Pilha);
            }
            pop(&Pilha);
        } else {
            while (!vazio(Pilha) && precedencia(simb) <= precedencia(Pilha->c) && Pilha->c != '(') {
                posfixo[j++] = pop(&Pilha);
            }
            push(&Pilha, simb);
        }
    }

    while (!vazio(Pilha)) {
        posfixo[j++] = pop(&Pilha);
    }

    posfixo[j] = '\0';
}


int main(void) {
    char infixo[150];
    char posfixo[150];

    printf("Digite uma expressão infixa envolvida por parênteses: ");
    scanf(" %[^\n]", infixo);

    infixoPosfixo(infixo, posfixo);

    printf("Expressão em notação posfixa: %s\n", posfixo);

    return 0;
}
