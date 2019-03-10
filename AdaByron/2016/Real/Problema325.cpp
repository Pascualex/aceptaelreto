#include <stdio.h>

void ponerBolas(char helado[16], int nBolasC, int nBolasV, int pos, bool ultimo) {

    if (nBolasC > 0) {        
        if (nBolasV > 0) {
            helado[pos] = 'C';
            ponerBolas(helado, nBolasC-1, nBolasV, pos+1, false);
            helado[pos] = 'V';
            ponerBolas(helado, nBolasC, nBolasV-1, pos+1, ultimo);
        } else {
            helado[pos] = 'C';
            ponerBolas(helado, nBolasC-1, nBolasV, pos+1, ultimo);
        }
    } else {
        if (nBolasV > 0) {
            helado[pos] = 'V';
            ponerBolas(helado, nBolasC, nBolasV-1, pos+1, ultimo);
        } else {
            if (ultimo == true) printf("%s\n", helado);
            else printf("%s ", helado);
        }
    }
}

int main() {
    int nCasos;
    int nBolasC, nBolasV;
    char helado[16];
    int i;

    scanf("%d", &nCasos);

    for (i = 0; i < nCasos; i++) {
        scanf("%d %d", &nBolasC, &nBolasV);

        helado[nBolasC+nBolasV] = '\0';

        ponerBolas(helado, nBolasC, nBolasV, 0, true);
    }

    return 0;
}