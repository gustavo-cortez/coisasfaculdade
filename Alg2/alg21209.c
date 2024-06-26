/*Autor: Gustavo Cortez de Paula*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produtos{
    
    char nome[50];
    float preco;
    struct produtos *prox;
    
};

typedef struct produtos produtos;

void lerprods(produtos* prod, int n){
    
    int i;
    
    for(i = 0; i < n; i = i + 1){
        
        prod[i].prox = NULL;
        printf("Dê o nome do produto\n");
        scanf(" %[^\n]", prod[i].nome);
        printf("Dê o valor do produto\n");
        scanf("%f", &prod[i].preco);
        
    }
}


float procuraprod(produtos* prod, int n, char nomeinfo[]){
    
    int i;
    float precoaux;
    produtos* prodaux;
    produtos* atual;
    i = 0;
    atual = &prod[0];
    prodaux = NULL;
    while(i < n && atual != NULL){
        
        if(strcmp(atual->nome, nomeinfo) == 0){
            
            precoaux = atual->preco;
            
            if(prodaux != NULL){
                
                prodaux->prox = atual->prox;
                atual->prox = &prod[i];
                prod = atual;
                
            }
            return precoaux;
            
        }
        
        
        i = i + 1;
        prodaux = atual;
        atual = &prod[i];
    }
    
    return -1.0;
    
}

int main(void){
    
    int n;
    char nome[50];
    float preco;
    produtos *prods;
    printf("Dê a quantidade de produtos\n");
    scanf("%d", &n);
    
    prods = (produtos *) malloc(n * sizeof(produtos));
    if(prods == NULL){
        
        printf("Erro ao alocar espaço\n");
        return 0;
        
    }
    
    lerprods(prods, n);
    
    printf("Dê o nome do produto à pesquisar\n");
    scanf(" %[^\n]", nome);
    
    preco = procuraprod(prods, n, nome);
    if(preco != -1.0){
        printf("O preço do produto é %f\n", preco);
    }
    else{
        printf("Não foi possível achar o produto\n");
    }
    free(prods);
    
    return 0;
}
