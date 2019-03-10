#include <stdio.h>

int main() {
    int nCasos;
    int nPuntos, maxTiempo;
    int nSesiones;
    int tiempoAct, puntoAct, puntoAnt;
    int i, j;

    scanf("%d", &nCasos);
    for (i = 0; i < nCasos; i++) {
        scanf("%d %d", &nPuntos, &maxTiempo);
        nSesiones = 1;
        tiempoAct = 0;
        puntoAnt = 0;
        for (j = 0; j < nPuntos; j++) {
            scanf("%d", &puntoAct);
            tiempoAct += puntoAct-puntoAnt;
            if (tiempoAct > maxTiempo) {
                nSesiones++;
                tiempoAct = puntoAct-puntoAnt;
            }
            puntoAnt = puntoAct;
        }
        printf("%d\n", nSesiones);
    }

    return 0;
}