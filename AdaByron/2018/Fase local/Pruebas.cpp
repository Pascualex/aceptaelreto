#include <stdio.h>
#include <algorithm>

#define ELEMENTO 5

int main() {
    int array[] = {1, 3, 3, 3, 5};
    int tam = 5;
    int *ptr;

    for (int i = 0; i < tam; i++) {
        if (i != tam-1) {
            printf("%d - ", array[i]);
        } else {
            printf("%d\n", array[i]);
        }
    }

    ptr = std::lower_bound(&array[3], &array[5], ELEMENTO);
    printf("%d (Posicion %d)\n", *ptr, ptr-array);

    ptr = std::upper_bound(&array[3], &array[5], ELEMENTO);
    printf("%d (Posicion %d)\n", *ptr, ptr-array);

    return 0;
}