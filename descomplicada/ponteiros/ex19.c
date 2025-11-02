#include <stdio.h>
#include <stdlib.h>

void teste( int *p, int tamanho, int *maior, int *ocorrencias){
    *maior = p[0];
    *ocorrencias = 1;
    
    for( int i = 1; i < tamanho; i++){
        if(*maior < p[i]){
            *maior = p[i];
            *ocorrencias = 1;
        }else if(*maior == p[i]){
            (*ocorrencias)++;
        }
    }

}
int main()
{   
    int array [10] = {0, 0, 5, 5, 5, 5, 2, 3, 4, 1};
    int maior, ocorrencias;

    teste(array, 10, &maior, &ocorrencias);

    printf("Maior número: %d", maior);
    printf("\nNumero de ocorrencias: %d", ocorrencias);
    
    return 0;
}
