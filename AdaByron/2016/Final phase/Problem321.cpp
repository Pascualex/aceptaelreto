#include <stdio.h>

int main() {
    int nCasos;
    int superior, inferior;
    int rango;
    int i, j;

    scanf("%d", &nCasos);
    for (i = 0; i < nCasos; i++) {
        scanf("%d %d", &superior, &inferior);

        rango = 1;
        for (j = 1; j <= inferior; j++) rango += j;
        for (j = 1; j <= superior; j++) rango += inferior+1+j;

        printf("%d\n", rango);
    }

    return 0;
}