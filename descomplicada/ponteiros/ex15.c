#include <stdio.h>
#include <stdlib.h>

void imprimir( int *p, int tamanho){
    for( int i = 0; i < tamanho; i++){
        printf("%d\n", *(p + i));
    }
    
}
int main()
{   
    int array [5] = {0, 1, 2, 3, 4};
 
    imprimir(array, 5);

    return 0;
}