/*Autor: Gustavo Cortez de Paula*/

#include <stdio.h>
#include <stdlib.h>

/*Verificando as somas das linhas*/
int somamatriz_linha(int m[], int tam){
    
    if(tam == 1){
        
        return m[0];
        
    }
    else{
        
        return somamatriz_linha(m, tam - 1) + m[tam - 1];
        
    }
    
}
/*Verificando as somas das colunas*/
int somamatriz_coluna(int **m, int tam, int coluna, int linha){
    
    if (linha == tam) {
        
        return 0;
        
    } 
    else{
        
        return m[linha][coluna] + somamatriz_coluna(m, tam, coluna, linha + 1);
        
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
/*Função para verificar se a matriz é um quadrado mágico*/
int quadradomagico(int **m, int tam, int *soma){
    
    int i;
    
    for (i = 1; i < tam; i++){
      
        if (*soma != somamatriz_linha(m[i], tam)){
          
            return 1;
           
        }
    }
    
    for (i = 0; i < tam; i++){
        
        if (*soma != somamatriz_coluna(m, tam, i, 0)){
          
            return 1;
          
        }
    }
    
    if (*soma != somadiagonal_principal(m, tam, 0)){
     
        return 1;
      
    }
    
    if (*soma != somadiagonal_secundaria(m, tam, 0)){
        
        return 1;
        
    }

    
    return 0;
}

int main(void){
    
    int i, j, n, **matriz, soma, **pt;
    
    printf("Dê o tamanho da matriz\n");
    scanf("%d", &n);
    
    if(n > 0 && n <= 100){
        
        matriz = (int **) malloc(n * sizeof(int *));
        if(matriz == NULL){
            
            printf("Erro ao alocar espaço\n");
            return 0;
            
        }
        for(pt = matriz, i = 0; i < n; i++, pt++){
            *pt = (int *) malloc(n * sizeof(int));
            if(*pt == NULL){
                
                printf("Erro ao alocar espaço\n");
                return 0;
                
            } 
        }
       
        for(i = 0; i < n; i ++){
            
            for(j = 0; j < n; j ++){
                
                scanf("%d", &matriz[i][j]);
                
            }
        }
        
        printf("\n");
        
        soma = somamatriz_linha(matriz[0], n);
        
        
        if(quadradomagico(matriz, n, &soma) == 0){
          
            printf("A matriz é um quadrado mágico pois a soma das direções é %d\n", soma);
           
        }
        else{
            
            printf("A matriz não é um quadrado mágico.\n\n");
            
        }
    }
    else{
        
        printf("Tamanho inválido.\n");
        
    }

    
    return 0;
    
}