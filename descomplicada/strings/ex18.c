#include <stdio.h>
#include <string.h>
int main()
{
    char string[100];
    printf("Digite a string: ");
    fgets(string, sizeof(string), stdin);
    char l1, l2;

    printf("Digite a letra L1: ");
    scanf("%c", &l1);
    while (getchar() != '\n');
    printf("Digite a letra L2: ");
    scanf("%c", &l2);

    for(int i = 0; i < (int)strlen(string); i++){
        if (string[i] == l1){

            string[i] = l2;
        }
    }
    printf("%s", string);
    return 0;
}
