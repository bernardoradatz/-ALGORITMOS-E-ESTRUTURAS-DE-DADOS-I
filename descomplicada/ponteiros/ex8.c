#include <stdio.h>

int main()
{
    float array [10];

    for( int i = 0; i < 10; i++ ){
        array[i] = i;
        printf("\nEndereço do array %.2f - %p", array[i], (void*)&array[i]);
    }    
    
    return 0;
}
