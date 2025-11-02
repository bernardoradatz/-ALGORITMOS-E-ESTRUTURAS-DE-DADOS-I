#include <stdio.h>
#include <stdlib.h>

int negativos(float *vet, int N){
    int qtdNegativos = 0;
    for(int i = 0; i < N; i++){
        if(vet[i] < 0){
            qtdNegativos++;
        }
    }
    return qtdNegativos;
}
int main()
{
   float vet[5] = { -3.2 , 2.0 , 3.1 , 0.0, 2.3 };
   int tamanho = 5;
   int resultado;

   resultado = negativos(vet, tamanho);
   
   printf("Quantidade de números negativos : %d\n", resultado);
    return 0;
}
