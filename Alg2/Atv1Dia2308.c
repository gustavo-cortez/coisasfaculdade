/*Autor: Gustavo Cortez de Paula*/

#include <stdio.h>
#include <stdlib.h>

void lervetor(int v[], int tam){
    
    int i;
    for(i = 0; i < tam; i ++){
        
        scanf("%d", &v[i]);
        
    }
    
}
int somavetor(int v[], int tam){
    
    if(tam == 1){
        
        return v[0];
        
    }
    else{
        
        return somavetor(v, tam - 1) + v[tam - 1];
        
    }
    
}

int main(void){
    
    int i, n, *vetor, soma;
    
    printf("Dê o tamanho do vetor\n");
    scanf("%d", &n);
    
    vetor = (int *) malloc(n * sizeof(int));
    if(vetor == NULL){
        
        printf("Erro ao alocar espaço\n");
        return 0;
        
    }
    printf("\n");
    
    lervetor(vetor, n);
    
    soma = somavetor(vetor, n);
    
    printf("%d", soma);
    
    return 0;
    
}