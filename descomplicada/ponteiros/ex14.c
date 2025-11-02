#include <stdio.h>
#include <stdlib.h>
void trocar( int *p, int num){
    for( int i = 0; i < 5; i++){
        *(p + i) = num;
    }
}
int main()
{   
    int array [5];
    int *p = array;
    int num = 5;

    trocar(array, num);
    for( int i = 0; i < 5; i++){
        printf("%d\n", *(p + i));
    }

    return 0;
}
