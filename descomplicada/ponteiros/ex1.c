#include <stdio.h>
int main()
{
    int inteiro;
    char letra;
    float real;

    int *pInt;
    char *pChar;
    float *pReal;
    
    inteiro = 10;
    real = 12.5;
    letra = 'c';

    pInt = &inteiro;
    pChar = &letra;
    pReal = &real;

    *pInt = 20;
    *pChar = 'b';
    *pReal = 1.2;

    printf("%d, %c, %f", inteiro, letra, real);
    return 0;
}
