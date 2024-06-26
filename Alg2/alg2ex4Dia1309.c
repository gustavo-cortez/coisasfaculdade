#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    char nome[30];
    int idade;
} cidadao;

struct cel {
    cidadao chave;
    struct cel* prox;
};
typedef struct cel item;

typedef struct {
    item* ini;
    item* fim;
} Fila;

void lercidadao(cidadao* cidadaos, int n){
    
    int i;
    
    for(i = 0; i < n; i = i + 1){
        
        printf("Dê o nome da pessoa\n");
        scanf(" %[^\n]", cidadaos[i].nome);
        printf("Informe a idade da pessoa\n");
        scanf("%d", &cidadaos[i].idade);
        cidadaos[i].codigo = i + 1;
        
    }
}

// Função para enfileirar um elemento em uma fila
void enfileirar(Fila* fila, cidadao pessoa) {
    item* novoItem = (item*)malloc(sizeof(item));
    if (novoItem == NULL) {
        printf("Erro ao alocar memória para o novo item\n");
    }
    novoItem->chave = pessoa;
    novoItem->prox = NULL;

    if (fila->fim == NULL) {
        fila->ini = novoItem;
        fila->fim = novoItem;
    } else {
        fila->fim->prox = novoItem;
        fila->fim = novoItem;
    }
}

// Função para desenfileirar um elemento de uma fila
int desenfileirar(Fila* fila, cidadao* elemento) {
    if (fila->ini == NULL) {
        printf("A fila está vazia. Não é possível desenfileirar.\n");
        return 0;
    }

    item* itemRemovido = fila->ini;
    *elemento = itemRemovido->chave;
    
    fila->ini = fila->ini->prox;
    if (fila->ini == NULL) {
        fila->fim = NULL;
    }
    
    free(itemRemovido);
    return 1;
}

int main() {
    
    int i, n;
    Fila* minhaFila;
    cidadao *pessoas;
    // Inicializar nova fila vazia
    minhaFila = (Fila*)malloc(sizeof(Fila));
    minhaFila->ini = NULL;
    minhaFila->fim = NULL;
    
    printf("Dê a quantidade de pessoas\n");
    scanf("%d", &n);
    
    pessoas = (cidadao *) malloc(n * sizeof(cidadao));
    if(pessoas == NULL){
        
        printf("Erro ao alocar espaço\n");
        return 0;
        
    }
    // Exemplo de uso: enfileirar alguns elementos
    lercidadao(pessoas, n);

    for(i = 0; i < n; i++){
        
        enfileirar(minhaFila, pessoas[i]);
        
    }
    i = 0;
    cidadao elementoDesenfileirado;
    // Desenfileirar e imprimir os elementos
    while (desenfileirar(minhaFila, &elementoDesenfileirado)) {
        printf("Código: %d, Nome: %s, Idade: %d\n", elementoDesenfileirado.codigo, elementoDesenfileirado.nome, elementoDesenfileirado.idade);
    }

    // Liberar a memória da fila
    free(minhaFila);
    free(pessoas);

    return 0;
}