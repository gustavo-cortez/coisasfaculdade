#include <stdio.h>

/*Definição da estrutura de Ponto*/
struct Ponto {
    float x;
    float y;
    int quadrante;
};

void leituraponto(struct Ponto *ponto){    
    scanf("%f", &ponto->x);
    scanf("%f", &ponto->y);    
}

/*Função para calcular o módulo*/
float calcularModulo(float numero) {
    if (numero < 0)
        return numero * -1.0;
    else
        return numero;
}

/* Função para calcular a distância quadrada entre dois pontos*/
float calcularDistanciaQuadrada(struct Ponto p1, struct Ponto p2) {
    float dx = calcularModulo(p1.x) - calcularModulo(p2.x);
    float dy = calcularModulo(p1.y) - calcularModulo(p2.y);
    return dx * dx + dy * dy;
}

/*Função para encontrar o ponto mais próximo de forma recursiva*/
struct Ponto pontoMaisProximoRecursivo(struct Ponto p, struct Ponto conjunto[], int n, int currentIndex, float distanciaMinima, struct Ponto pontoProximo) {
    if (currentIndex == n) {
        return pontoProximo;
    }

    float distanciaAtualQuadrada = calcularDistanciaQuadrada(p, conjunto[currentIndex]);
    
    if (distanciaAtualQuadrada < distanciaMinima) {
        distanciaMinima = distanciaAtualQuadrada;
        pontoProximo = conjunto[currentIndex];
    }
    
    return pontoMaisProximoRecursivo(p, conjunto, n, currentIndex + 1, distanciaMinima, pontoProximo);
}

/*Função para identificar a posição do ponto*/
void identificarPosicao(struct Ponto *ponto) {
    if (ponto->x == 0 && ponto->y == 0) {
        printf("Coordenadas do ponto: (%.2f, %.2f) na origem.\n", ponto->x, ponto->y);
        ponto->quadrante = 0;
    } else if (ponto->x == 0) {
        printf("Coordenadas do ponto: (%.2f, %.2f) X está na origem.\n", ponto->x, ponto->y);
        ponto->quadrante = 0;
    } else if (ponto->y == 0) {
        printf("Coordenadas do ponto: (%.2f, %.2f) Y está na origem.\n", ponto->x, ponto->y);
        ponto->quadrante = 0;
    } else if (ponto->x > 0 && ponto->y > 0) {
        ponto->quadrante = 1;
    } else if (ponto->x < 0 && ponto->y > 0) {
        ponto->quadrante = 2;
    } else if (ponto->x < 0 && ponto->y < 0) {
        ponto->quadrante = 3;
    } else if (ponto->x > 0 && ponto->y < 0) {
        ponto->quadrante = 4;
    }
}

int main(void) {
    struct Ponto pontoP;
    int i, n;
    
    printf("Digite as coordenadas do ponto P (x y): ");
    leituraponto(&pontoP);
    
    printf("Digite o número de pontos no conjunto: ");
    scanf("%d", &n);
    
    struct Ponto conjuntoPontos[n];
    for (i = 0; i < n; i = i + 1) {
        printf("Digite as coordenadas do ponto %d (x y): ", i + 1);
        leituraponto(&conjuntoPontos[i]);
    }
    
    float distanciaMinima = 1.0e20;
    
    struct Ponto pontoMaisProximo = pontoMaisProximoRecursivo(pontoP, conjuntoPontos, n, 0, distanciaMinima, conjuntoPontos[0]);
    
    printf("O ponto mais próximo de (%.2f, %.2f) é (%.2f, %.2f)\n", pontoP.x, pontoP.y, pontoMaisProximo.x, pontoMaisProximo.y);
    
    identificarPosicao(&pontoMaisProximo);
    
    if(pontoMaisProximo.quadrante != 0){
        
        printf("Coordenadas do ponto: (%.2f, %.2f) no %d° quadrante.\n", pontoMaisProximo.x, pontoMaisProximo.y, pontoMaisProximo.quadrante);
        
    }

    return 0;
}
