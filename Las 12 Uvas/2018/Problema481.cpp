#include <stdio.h>

int main() {
    int fila, columna;

    while (true) {
        scanf("%d %d", &fila, &columna);
        if (fila == 0) return 0;

        printf("%c%d\n", 105-fila, columna);
    }
}