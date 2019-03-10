#include <stdio.h>

int main() {
    int nEtapas;
    int etapas[100];
    int distancia;
    int i;

    while (true) {
        scanf("%d", &nEtapas);
        if (nEtapas == 0) return 0;

        for (i = 0; i < nEtapas; i++) {
            scanf("%d", &etapas[i]);
        }

        distancia = etapas[nEtapas-1];
        for (i = nEtapas-2; i >= 0; i--) {
            distancia += etapas[i];
            etapas[i] = distancia;
        }

        for (i = 0; i < nEtapas-1; i++) {            
            printf("%d ", etapas[i]);
        }
        printf("%d\n", etapas[nEtapas-1]);
    }
}