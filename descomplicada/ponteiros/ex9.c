#include <stdio.h>
#include <stdlib.h>
int main()
{
    float matriz[3][3];
    for( int i = 0; i < 3; i++ ){
        for( int j = 0; j < 3; j++ ){
            matriz[i][j]= i;
            printf("\nEndereço do da matriz [%d][%d]%.2f - %p", i, j, matriz[i][j], (void*)&matriz[i][j]);
        }
    }    
    return 0;
}
