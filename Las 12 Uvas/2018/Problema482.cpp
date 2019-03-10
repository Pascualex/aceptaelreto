#include <stdio.h>

int main() {
    char color;
    int nNegros, nGrises;

    nNegros = 0;
    nGrises = 0;

    while (true) {
        scanf(" %c", &color);
        if (color == '.') {
            if (nNegros == 0 && nGrises == 0) return 0;

            nNegros = nNegros%2;
            nGrises = nGrises%2;

            if (nNegros == 0) {
                if (nGrises == 0) {
                    printf("EMPAREJADOS\n");
                } else {
                    printf("GRIS SOLITARIO\n");
                }
            } else {
                if (nGrises == 0) {
                    printf("NEGRO SOLITARIO\n");
                } else {
                    printf("PAREJA MIXTA\n");
                }
            }

            nNegros = 0;
            nGrises = 0;
        } else if (color == 'N') nNegros++;
        else nGrises++;
    }
}