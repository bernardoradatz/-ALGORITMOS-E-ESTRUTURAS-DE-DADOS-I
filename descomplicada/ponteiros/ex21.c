#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = array;
    for ( int i = 0; i < 10; i++ ) {
        *(p + i) = *(p + i) + 1;
    }

    for (int i = 0; i < 10; i++) {
        printf(" %d ", *(p + i));
    }
    printf("\n");
    return 0;
}
