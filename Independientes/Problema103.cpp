#include <stdio.h>
#include <math.h>

int main() {
    int grado;
    int coeficientes[20];
    int nRectangulos;
    double tierraCain;
    double i, aux;
    int j;

    while (true) {
        scanf("%d", &grado);
        if (grado == 20) return 0;

        for (i = grado; i >= 0; i--) {
            scanf("%d", &coeficientes[(int) i]);
        }

        scanf("%d", &nRectangulos);

        tierraCain = 0;
        for (i = 0; i < nRectangulos; i++) {
            aux = 0;            
            for (j = 0; j <= grado; j++) {
                if (coeficientes[j] != 0) {
                    aux += coeficientes[j]*pow(i/nRectangulos, j);
                }
            }

            if (aux > 1) {
                tierraCain += 1;
            } else if (aux > 0) {
                tierraCain += aux;
            }
        }

        tierraCain /= nRectangulos;
        if (tierraCain > 0.501) {
            printf("CAIN\n");
        } else if (tierraCain < 0.499) {
            printf("ABEL\n");
        } else {
            printf("JUSTO\n");
        }
    }
}