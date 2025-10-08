#include <stdio.h>

int main()
{   
    int contador = 0;
    int idade[10];
    char nome[10][20];
    int indice_maior = 0;
    int indice_menor = 0;
    
    for(int i = 0; i < 10; i++){
    
        printf("Digite o nome:");
        fgets(nome[i], sizeof(nome[i]), stdin);
        printf("Digite a idade:");
        scanf("%d", &idade[i]);
        if(idade[i] < 0){
            break;
        }
        while (getchar() != '\n');
        contador++;
    }   
    
    int maior = idade[0];
    int menor = idade[0];

    for(int j = 0; j < contador; j++){
        if(maior < idade[j]){
            maior = idade[j];
            indice_maior = j;
        }
        if(menor > idade[j]){
            menor = idade[j];
            indice_menor = j;
        }
    }
    printf("\tMais velho \nNome: %sIdade:%d", nome[indice_maior], maior);
    printf("\n\tMais novo \nNome: %sIdade:%d", nome[indice_menor], menor);
    return 0;
}
