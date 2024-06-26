/*Autor: Gustavo Cortez de Paula*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50;

struct nomeregistro{
    
    char nome[50];/*Cadeia de caracter*/
    float preco;/*Variável do tipo real*/
    struct produtos *prox;/*Ponteiro que aponta para a proxima struct*/
    
};

typedef struct nomeregistro nomedotipodoregistro;

void lerprods(nomedotipodoregistro *nomerefregistro, int n){
    
    int i;
    
    for(i = 0; i < n; i = i + 1){
        
        nomerefregistro[i].prox = NULL;
        printf("Dê o nome do produto\n");
        scanf(" %[^\n]", nomerefregistro[i].nome);
        printf("Dê o valor do produto\n");
        scanf("%f", &nomerefregistro[i].preco);
        
    }
}

int funcaorecursivainteiro(int *m, int tam){
    
    if (tam < 1) {
        
        return m[0];
        
    } 
    else{
        
        return m[tam] + funcaorecursivainteiro(m, tam - 1);
        
    }
}

void lervetor(int *m, int tam){
    
    int i;
    for(i = 0; i < tam; i++){

        scanf("%d", &m[i]);

    }
}

/*Verificando a soma da diagonal principal*/
int somadiagonal_principal(int **m, int tam, int pos){
    
    if (pos == tam) {
        
        return 0;
        
    } 
    else{
        
        return m[pos][pos] + somadiagonal_principal(m, tam, pos + 1);
        
    }
}
/*Verificando a soma da diagonal secundária*/
int somadiagonal_secundaria(int **m, int tam, int pos){
    
    if (pos == tam) {
        
        return 0;
        
    } 
    else{
       
        return m[pos][tam - pos - 1] + somadiagonal_secundaria(m, tam, pos + 1);
      
    }
}

// Função para verificar se a pilha está vazia
int vazio(int *t) {
    return (*t == -1);
}

// Função para empilhar um caractere na pilha
int pop(int *t, int P[MAX]){
    int r;  // Variável para armazenar o elemento removido

    if (!vazio(t)) {
        r = P[*t];  // Atribui o valor do topo da pilha 'P' a 'r'
        (*t)--;      // Decrementa o valor apontado por 't'
    } else {
        r = INT_MIN;  // Define 'r' como o valor mínimo de um inteiro, indicando que a pilha está vazia
        printf("Pilha vazia!\n");
    }

    return r;  // Retorna o elemento removido ou INT_MIN se a pilha estiver vazia
}

// Função para desempilhar um caractere da pilha
void push(int *t, int P[MAX], int y) {
    if (*t != MAX - 1) {
        (*t)++;          // Incrementa o valor apontado por 't' para indicar o novo topo
        P[*t] = y;       // Armazena o valor 'y' no topo da pilha 'P'
    } else {
        printf("Pilha cheia!\n");
    }
}

int main(void){
    
    int *v, n, **matriz, **pt, i, j, tam;
    nomedotipodoregistro nomerefregistro[3];
    /*Vetor*/
    printf("Informe o tamanho de vetores\n");
    scanf("%d", &n);
    
    /*Alocar memória de um vetor*/
    v = (int *) malloc(n * sizeof(int));
    if(v == NULL){
        
        printf("Erro ao alocar espaço\n");
        return 0;
        
    }

    lervetor(v, n);

    printf("A soma é: %d", funcaorecursivainteiro(v, n - 1));
    
    /*Matriz quadrada*/
    printf("\nDê o tamanho da matriz\n");
    scanf("%d", &tam);
    
    matriz = (int **) malloc(tam * sizeof(int *));
    if(matriz == NULL){
            
        printf("Erro ao alocar espaço\n");
        return 0;
            
    }
    /*PT é um ponteiro que aponta para matriz*/
    for(pt = matriz, i = 0; i < tam; i++, pt++){
        *pt = (int *) malloc(tam * sizeof(int));
        if(*pt == NULL){
                
            printf("Erro ao alocar espaço\n");
            return 0;
                
        } 
    }
       
    for(i = 0; i < tam; i ++){
            
        for(j = 0; j < tam; j ++){
                
            scanf("%d", &matriz[i][j]);
                
        }
    }
    printf("Soma da diagonal principal: %d\n", somadiagonal_principal(matriz, tam, 0));
    printf("Soma da diagonal principal: %d\n", somadiagonal_secundaria(matriz, tam, 0));
    lerprods(&nomerefregistro, 3);
    
    free(v);
    free(matriz);
    return 0;

}