#include <stdio.h>
int main (void)
{
    int n, a, b, c, d, c1, c2, c3, d1;
    scanf ("%d", &n );
    
    d1 = (n - 10) % 3;
    
    c = n - 5 - 3;
    
    if (n % 5 == 0)
    {
        a = n / 5;
        printf ("0 %d", a);
    }
        
    else{  
        if (c % 5 == 0) {
            c2 = c / 5 + 1 ;
            c1 = (n - c2 * 5) / 3;
            printf("%d %d",c1, c2);
        }
        else{
            if (n % 3 == 0){
                b = n / 3;
                printf ("%d 0", b);
            } 
        
            else{
                if (c % 3 == 0) {
                c2 = c / 3 + 1 ;
                c1 = (n - c2 * 3) / 5;
                printf("%d %d",c2, c1);
                } 
                
                else{
                    if (n % 5 != 0 && n % 3 != 0 && d1 == 0){ 
                        c1 = (n - 10) / 3;
                        printf("%d 2",c1);
                    }

    
                    }
                }
            }
        }
    return 0;
}