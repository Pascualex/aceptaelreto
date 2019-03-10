#include <stdio.h>

int ordenCorte[1001][1001];
int descubiertos[1001][1001];
int n, m, salto;

int elegirSiguiente(int &xActual, int &yActual) {
    int ultimoCorte;
    int i, j;

    xActual = -1;
    yActual = -1;

    ultimoCorte = 0;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (descubiertos[i][j] != 1) continue;

            if (ordenCorte[i][j] > ultimoCorte) {
                ultimoCorte = ordenCorte[i][j];
                xActual = j;
                yActual = i;
            }
        }
    }

    if (xActual == -1) return -1;

    descubiertos[i][j] = 2;



    return 0;
}

int main() {
    int nCortados;
    int x, y;
    int xActual, yActual;
    int i, j;

    while (true) {
        scanf("%d %d %d %d", &n, &m, &salto, &nCortados);
        if (feof(stdin)) return 0;

        for (i = 0; i <= m; i++) {
            for (j = 0; j <= n; j++) {
                ordenCorte[i][j] = -1;
                descubiertos[i][j] = 0;
            }
        }
        
        descubiertos[0][0] = 1;
        ordenCorte[0][0] = nCortados+1;        
        ordenCorte[m][n] = nCortados+1;
        
        for (i = 0; i < nCortados; i++) {
            scanf("%d %d", &x, &y);
            ordenCorte[y][x] = i+1;
        }

        xActual = 0;
        yActual = 0;
    }    
}