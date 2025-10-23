#include <stdio.h>
void ordena( int *a, int *b ){
    if(*b > *a){
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
} 
int main()
{
     int a, b;
    printf("Digite o valor a: ");
    scanf("%d", &a);
    printf("Digite o valor b: ");
    scanf("%d", &b);
    ordena(&a, &b);
    printf("Valor de a (maior) é %d \nValor de b (menor) é %d", a, b);
    return 0;
}
