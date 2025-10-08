#include <stdio.h>
#include <string.h> 

int main() {
    char palavra[50];

    printf("Digite uma palavra (maximo de 50 letras): ");
    
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0';

    for (int i = 0; i < (int)strlen(palavra); i++) {
        palavra[i] = palavra[i] + 1;
    }

    printf("\nPalavra resultante: %s\n", palavra);

    return 0;
}