#include <stdio.h>

int main() {
    int tamPiscina, tamCubo, perdida, viajes;
    int tamPiscinaVec, tamCuboVec, perdidaVec, viajesVec;

    while (true) {
        scanf("%d %d %d %d %d %d", &tamPiscina, &tamCubo, &perdida, &tamPiscinaVec, &tamCuboVec, &perdidaVec);
        if (tamPiscina == 0 || tamPiscinaVec == 0) return 0;

        if (tamCubo < tamPiscina) {
            if (tamCubo <= perdida) {
                viajes = __INT_MAX__;
            } else {
                viajes = (tamPiscina-perdida)/(tamCubo-perdida);
                if ((tamPiscina-perdida)%(tamCubo-perdida) > 0) viajes++;
            }
        } else {
            viajes = 1;
        }

        if (tamCuboVec < tamPiscinaVec) {
            if (tamCuboVec <= perdidaVec) {
                viajesVec = __INT_MAX__;
            } else {
                viajesVec = (tamPiscinaVec-perdidaVec)/(tamCuboVec-perdidaVec);
                if ((tamPiscinaVec-perdidaVec)%(tamCuboVec-perdidaVec) > 0) viajesVec++;
            }
        } else {
            viajesVec = 1;
        }

        if (viajes == viajesVec) {
            printf("EMPATE %d\n", viajes);
        } else if (viajes < viajesVec) {
            printf("YO %d\n", viajes);
        } else {
            printf("VECINO %d\n", viajesVec);
        }
    }
}