#include <stdio.h>

int objetivo;

int nRemontes;
int inicios[25];
int finales[25];
int tiempos[25];

int distanciaMax;

void movimiento(int posicion, int tiempo, int distancia) {
    int i;

    if (posicion >= objetivo && posicion-objetivo <= tiempo) {
        if (distancia+(posicion-objetivo) >= distanciaMax) distanciaMax = distancia+(posicion-objetivo);
    }

    for (i = 0; i < nRemontes; i++) {        
        if (inicios[i] <= posicion && (posicion-inicios[i])+tiempos[i] <= tiempo) {
            movimiento(finales[i], tiempo-(posicion-inicios[i])-tiempos[i], distancia+(posicion-inicios[i]));
        }
    }
}

int main() {    
    int inicio, tiempoMax;
    int i;

    while (true) {
        scanf("%d", &nRemontes);
        if (nRemontes == 0) return 0;

        for (i = 0; i < nRemontes; i++) {
            scanf("%d %d %d", &inicios[i], &finales[i], &tiempos[i]);
        }

        scanf("%d %d %d", &inicio, &objetivo, &tiempoMax);

        distanciaMax = -1;
        movimiento(inicio, tiempoMax, 0);

        if (distanciaMax == -1) {
            printf("IMPOSIBLE\n");
        } else {
            printf("%d\n", distanciaMax);
        }
    }
}