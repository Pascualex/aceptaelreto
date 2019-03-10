#include <stdio.h>

int main() {
    int nPosibilidades;
    int alturas[1001];
    int costes[1001];
    int costesAcum[1001];
    bool comprobados[1001];
    int diferenciaMax;
    int posCosteMin, costeMin;
    int i;

    while (true) {
        scanf("%d", &nPosibilidades);
        if (feof(stdin)) return 0;

        for (i = 1; i <= nPosibilidades; i++) {
            scanf("%d", &alturas[i]);
            comprobados[i] = false;
        }

        for (i = 1; i <= nPosibilidades; i++) {
            scanf("%d", &costes[i]);
            costesAcum[i] = __INT_MAX__;
        }

        scanf("%d", &diferenciaMax);

        alturas[0] = 0;
        comprobados[0] = false;
        costes[0] = 0;
        costesAcum[0] = 0;

        while (true) {
            costeMin = __INT_MAX__;
            for (i = 0; i <= nPosibilidades; i++) {
                if (costesAcum[i] < costeMin && comprobados[i] == false) {
                    posCosteMin = i;
                    costeMin = costesAcum[i];
                }
            }
            comprobados[posCosteMin] = true;

            if (posCosteMin == nPosibilidades) break;

            i = posCosteMin+1;
            while (true) {
                if (i > nPosibilidades || alturas[i]-alturas[posCosteMin] > diferenciaMax) break;

                if (costesAcum[posCosteMin]+costes[i] < costesAcum[i]) costesAcum[i] = costesAcum[posCosteMin]+costes[i];
                i++;
            }
        }

        printf("%d\n", costesAcum[nPosibilidades]);
    }
}