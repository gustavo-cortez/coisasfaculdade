#include <stdio.h>

struct Ponto {
    float x;
    float y;
};

float calcularDistanciaQuadrada(struct Ponto p1, struct Ponto p2) {
    
    float dx, dy;
    
    dx = p1.x - p2.x;
    dy = p1.y - p2.y;
    
    return dx * dx + dy * dy;
}

/* Função que devolve uma struct com o ponto mais próximo de forma recursiva*/
struct Ponto pontoMaisProximoRecursivo(struct Ponto p, struct Ponto conjunto[], int n, int iAux, float distanciaMinima, struct Ponto pontoProximo) {
    
    if (iAux == n) {
        return pontoProximo;
    }

    float distanciaAtualQuadrada = calcularDistanciaQuadrada(p, conjunto[iAux]);
    
    if (distanciaAtualQuadrada < distanciaMinima) {
        distanciaMinima = distanciaAtualQuadrada;
        pontoProximo = conjunto[iAux];
    }
    
    return pontoMaisProximoRecursivo(p, conjunto, n, iAux + 1, distanciaMinima, pontoProximo);
    
}

int main(void) {
    struct Ponto pontoP;
    int i, n;
    printf("Digite as coordenadas do ponto P (x y): ");
    scanf("%f %f", &pontoP.x, &pontoP.y);
    
    printf("Digite o número de pontos no conjunto: ");
    scanf("%d", &n);
    
    struct Ponto conjuntoPontos[n];
    for (i = 0; i < n; i = i + 1) {
        printf("Digite as coordenadas do ponto %d (x y): ", i + 1);
        scanf("%f %f", &conjuntoPontos[i].x, &conjuntoPontos[i].y);
    }
    
    float distanciaMinima = 1.0e20;
    
    struct Ponto pontoMaisProximo = pontoMaisProximoRecursivo(pontoP, conjuntoPontos, n, 0, distanciaMinima, conjuntoPontos[0]);
    
    printf("O ponto mais próximo de (%.2f, %.2f) é (%.2f, %.2f)\n", pontoP.x, pontoP.y, pontoMaisProximo.x, pontoMaisProximo.y);
    
    return 0;
}
