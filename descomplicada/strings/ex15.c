#include<stdio.h>
#include<string.h>

int main()
{
    char string[100];
    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    for(int i = 0; i < (int)strlen(string); i++){
        if(string[i] >= 65 && string[i] <= 96){
            string[i] += 32;
        }
    }
    printf("%s", string);
    return 0;
}
