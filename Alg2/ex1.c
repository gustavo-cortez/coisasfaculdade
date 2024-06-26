#include <stdio.h>

float calcularmodulo(float numero) {
    if (numero < 0)
        return numero * -1.0;
    else
        return numero;
}

int main(void){
    float numero;
    float valormodulo;
    
    printf("Digite um número real: ");
    scanf("%f", &numero);
    
    valormodulo = calcularmodulo(numero);
    
    printf("O módulo de %.2f é %.2f\n", numero, valormodulo);
    
    return 0;
}
