#include <stdio.h>

int main() {
    int v[5];
    int *p = v;

    for (int i = 0; i < 5; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", (p + i)); 
    }

    for (int i = 0; i < 5; i++) {
        printf("Dobro do elemento %d = %d\n", i + 1, *(p + i) * 2);
    }

    return 0;
}
