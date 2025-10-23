#include <stdio.h>
void troca( int *a, int *b ){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{   
    int a, b;
    printf("Digite o valor a: ");
    scanf("%d", &a);
    printf("Digite o valor b: ");
    scanf("%d", &b);
    troca( &a, &b );
    printf("Valor de a é %d \nValor de b é %d", a, b);
    return 0;
}
