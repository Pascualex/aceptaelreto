#include <stdio.h>

int main() {
    int nCasos;
    int palmerasSeguras[100002];
    int nieve, tolerancia, nPalmeras, nPalmerasSeguras, maxZonaRiesgo;
    int i, j;

    scanf("%d", &nCasos);

    for (i = 0; i < nCasos; i++) {
        scanf("%d", &nieve);
        scanf("%d", &nPalmeras);

        palmerasSeguras[0] = 0;
        nPalmerasSeguras = 1;
        for (j = 0; j < nPalmeras; j++) {
            scanf("%d", &tolerancia);

            if (tolerancia >= nieve) {
                palmerasSeguras[nPalmerasSeguras] = j+1;
                nPalmerasSeguras++;
            }
        }

        if (nPalmerasSeguras-1 <= 5) {
            printf("%d\n", nPalmeras);
            continue;
        }

        palmerasSeguras[nPalmerasSeguras] = nPalmeras+1;
        nPalmerasSeguras++;

        maxZonaRiesgo = 0;
        for (j = 0; j < nPalmerasSeguras-6; j++) {
            if (palmerasSeguras[j+6]-palmerasSeguras[j]-1 > maxZonaRiesgo) maxZonaRiesgo = palmerasSeguras[j+6]-palmerasSeguras[j]-1;
        }

        printf("%d\n", maxZonaRiesgo);
    }

    return 0;
}