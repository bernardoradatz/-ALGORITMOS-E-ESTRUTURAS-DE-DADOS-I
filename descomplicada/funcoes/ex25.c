#include <stdio.h>
/*
====================
serie

  Calcula a soma da série:
  S = 2/4 + 5/5 + 10/6 + ... + (N^2 + 1)/(N + 3)
====================
*/
float serie( int n ){
    float resultado = 0.0;
    for( int i = 1; i <= n; i++){
        resultado += ( ( i * i ) + 1 ) / ( i + 3 );
    }
    return resultado;
}
int main()
{
    float total;
    int num;
    printf("Digite o valor n: ");
    scanf( "%d", &num );

    total = serie( num );
    printf( "Valor total: %.2f", total );
    return 0;
}
