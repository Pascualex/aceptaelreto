#include <stdio.h>

int main() {
    int cartas[100000];
    int nCartas, nSwaps;
    int min, minS;
    int i, j;

    while (true) {
        scanf("%d", &nCartas);
        if (nCartas == 0) break;

        for (i = 0; i < nCartas; i++) {
            scanf("%d", &cartas[i]);
        }

        min = cartas[nCartas-1];
        minS = 999999999;
        for (i = nCartas-2; i >= 0; i--) {
            if (cartas[i] <= min) min = cartas[i];
            else if (cartas[i] <= minS) minS = cartas[i]; 
        }

        nSwaps = 0;
        if (minS != 999999999) {
            for (i = nCartas-1; i >= 0; i--) {
                if (cartas[i] >= minS) nSwaps++; 
            }
        }

        printf("%d\n", nSwaps);
    }

    return 0;
}