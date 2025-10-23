#include <stdio.h>
int maior(int vetor[10]){
    int maiorValor = vetor[0];
    for( int i = 0; i < 10; i++ ){
        if(maiorValor < vetor[i] ){
            maiorValor = vetor[i];
        }
    }
    return maiorValor;
}
int main()
{
    int vetor[10];
    for( int i = 0; i < 10; i++ ){
        printf( "Digite o valor %d: ", i );
        scanf( "%d", &vetor[i] );
    }
    int maior_total = maior(vetor);
    printf("Maior valor: %d", maior_total);
    return 0;
}
