#include <stdio.h>
int main (void)
{
    int n, n2, bi, i, p, bin, bn;
    scanf ("%d", &n);
    while (n != -1){
      scanf ("%d", &n2);
      p = 1;
      bin = 0;
      for (i = n; i > 0; i = i / 2){
          bi = i % 2;
          bin = bin + bi * p;
          p = p * 10;
      }
      bn = bin;
      bin = 0;
      p = 1;
      for (i = n2; i > 0; i = i / 2){
          bi = i % 2;
          bin = bin + bi * p;
          p = p * 10;
      }
      printf ("%d %d\n", bn, bin);
      scanf ("%d", &n);

    }


    return 0;
}