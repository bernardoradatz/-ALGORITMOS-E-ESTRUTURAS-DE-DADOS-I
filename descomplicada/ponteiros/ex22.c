#include <stdio.h>
#include <stdlib.h>
int teste(int *v1, int *v2, int *v3, int n1, int n2){
    if(n1 != n2){
        return 0;
    }
    for(int i = 0; i < n1; i++){
        *(v3 + i) = *(v1 + i) + *(v2 + i);
    }
    return 1;
}
int main()
{
    int tam1, tam2;
    int array1 [3] = {0, 1, 3};
    tam1 = sizeof(array1) / sizeof(array1[0]);
    int array2 [3] = {10, 9, 7};
    tam2 = sizeof(array2) / sizeof(array2[0]);
    int array3 [3];

    int resultado = teste(array1, array2, array3, tam1, tam2);
    if(resultado == 0){
        printf("Tamanho das arrays diferentes.\n");
    }else{
        for(int i = 0; i < 3; i++){
            printf(" %d ", *(array3 + i));
        }
        printf("\n");
    }
    return 0;
}
