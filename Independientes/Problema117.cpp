#include <stdio.h>

int main() {
    int nCasos;
    char nombre[101];

    scanf("%d", &nCasos);

    for (int i = 0; i < nCasos; i++) {
        scanf("%*s %s", nombre);
        printf("Hola, %s.\n", nombre);
    }
}