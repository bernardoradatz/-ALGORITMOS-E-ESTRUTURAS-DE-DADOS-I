#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//--------------- canPlaceFlower ----------------
// Testa se o canteiro pode receber mais flores, com a condição de não ter flores adjacentes
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    for(int i = 0; i < flowerbedSize; i++){
        
        if(flowerbed[i] == 0){
            
            int left = 0;
            if( i == 0 || flowerbed[i - 1] == 0 ){
                left = 1;
            }else{
                left = 0;
            }
        
            int right = 0;
            if( i == flowerbedSize - 1|| flowerbed[i + 1] == 0 ){
                right = 1;
            }else{
                right = 0;
            }

            if(left == 1 && right == 1){
                flowerbed[i] = 1;
                n--;
            }
        }
    }
    if(n <= 0){
        return true;
    }else {
        return false;
    }
}
int main()
{
    int vetor [6] = {0, 0, 0, 0, 0, 0};
    int tamanho = 6;
    int n = 4;

    bool resultado = canPlaceFlowers(vetor, tamanho, n);
    
    if(resultado){
        printf( "Você conseguiu plantar todas flores. \n" );
    } else{
        printf( "Impossivel plantar %d flores nesse canteiro. \n", n );
    }
    return 0;
}
