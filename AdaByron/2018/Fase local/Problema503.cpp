#include <stdio.h>

int main() {
    int nCasos;
    int dado1, dado2;
    int i, j;

    scanf("%d", &nCasos);
    for (i = 0; i < nCasos; i++) {
        scanf("%d %d", &dado1, &dado2);

        if (dado1 == dado2) {
            printf("%d\n", dado1+1);
        } else if (dado1 > dado2) {
            for (j = 0; j < dado1-dado2+1; j++) {
                if (j < dado1-dado2) {
                    printf("%d ", dado2+j+1);
                } else {
                    printf("%d\n", dado2+j+1);
                }
            }
        } else {
            for (j = 0; j < dado2-dado1+1; j++) {
                if (j < dado2-dado1) {
                    printf("%d ", dado1+j+1);
                } else {
                    printf("%d\n", dado1+j+1);
                }
            }
        }
    }
}