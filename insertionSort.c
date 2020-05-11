#include <stdio.h>
int vetor[10] = {8,7,9,6,4,5,2,3,1,10};
n = 10;
int main(void) {
   int i, j, aux;

   for (i = 1; i <= n - 1; i++){

      aux = vetor[i];
      j = i - 1;
      while (j >= 0 && aux < vetor[j]) {


         vetor[j+1] = vetor[j];
         j--;
      }

      vetor[j+1] = aux;
   }

   for(i = 0; i < 10;i++){
     printf("[ ");
     printf("%d", vetor[i]);
     printf(" ]");
   }
}
