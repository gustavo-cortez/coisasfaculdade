#include <stdio.h>

int main(void){
    
    int valorcorre, quantselo3, quantselo5, selo3, selo5, resto;
    #define selo3 3
    #define selo5 5
    
    scanf("%d", &valorcorre);
    
    quantselo3 = 0;
    quantselo5 = 0;
    if(valorcorre < 8){
        printf("%d %d", quantselo3, quantselo5);
    }
    else{
        if(valorcorre % selo3 != 0 || valorcorre % selo5 == 0){
        
            quantselo5 = valorcorre % selo5;
            quantselo3 = valorcorre % selo3;
            if(quantselo5 * selo5 + quantselo3 * selo3 != valorcorre){
                quantselo5 = valorcorre / selo5;
                quantselo3 = (valorcorre % selo5) / selo3;
                if(quantselo5 * selo5 + quantselo3 * selo3 != valorcorre){
                    quantselo5 = (valorcorre * selo5) % selo3;
                    quantselo3 = (valorcorre % selo3) * 2;
                    if(quantselo5 * selo5 + quantselo3 * selo3 != valorcorre){
                        quantselo5 = (valorcorre * selo5) % selo3;
                        quantselo3 = (valorcorre * 2)% 5;
                    }
                }
            }
            
        }
        else{
            quantselo3 = valorcorre / selo3;
            if(quantselo3 > ((valorcorre * selo3) % selo5)% selo3){
                quantselo3 = ((valorcorre * selo3) % selo5)% selo3;
                quantselo5 = valorcorre % 5;
                if(quantselo5 * selo5 + quantselo3 * selo3 != valorcorre){
                     quantselo3 = valorcorre / selo3;
                     quantselo5 = 0;
                }
            }
            
        }
            printf("%d %d", quantselo3, quantselo5);
    }
    return 0;
}