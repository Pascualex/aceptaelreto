#include <stdio.h>

#define NO_APARECIDA -1
#define IMPORTANTE -2

int estaciones[10000], nEstaciones;
int lineas[100][100], tamLineas[100], nLineas;    
int matrizImportantes[200][200], estacionesImportantes[200], nEstacionesImportantes;

int posEstacionImportante(int estacionImportante) {
    int i;

    for (i = 0; i < nEstacionesImportantes; i++) {
        if (estacionesImportantes[i] == estacionImportante) return i;
    }

    return -1;
}

/*void imprimir() {
    int i, j;

    for (i = 0; i < nEstacionesImportantes; i++) printf("%d = %d\n", i+1, estacionesImportantes[i]+1);

    for (i = 0; i < nEstacionesImportantes; i++) {
        for (j = 0; j < nEstacionesImportantes; j++) {
            if (j < nEstacionesImportantes-1) {
                if (matrizImportantes[i][j] == __INT_MAX__) printf("X ");
                else printf("%d ", matrizImportantes[i][j]);     
            } else {
                if (matrizImportantes[i][j] == __INT_MAX__) printf("X\n");
                else printf("%d\n", matrizImportantes[i][j]);
            }
        }
    }
}*/

int main() {    
    int estacionAux, posEstacionAux1, posEstacionAux2, distancia;
    int estacionCentral, costeMin, costeAct;
    int i, j, k;

    while (true) {
        scanf("%d %d", &nEstaciones, &nLineas);
        if (nEstaciones == 0) return 0;

        for (i = 0; i < nEstaciones; i++) estaciones[i] = NO_APARECIDA;

        // Leer datos y localizar estaciones importantes
        nEstacionesImportantes = 0;
        for (i = 0; i < nLineas; i++) {
            j = 0;
            while (true) {
                scanf("%d", &estacionAux);
                if (estacionAux == 0) {
                    tamLineas[i] = j;
                    break;
                } else {
                    estacionAux--;
                    lineas[i][j] = estacionAux;
                    if (estaciones[estacionAux] == NO_APARECIDA) estaciones[estacionAux] = i;
                    else if (estaciones[estacionAux] != i && estaciones[estacionAux] != IMPORTANTE) {
                        estaciones[estacionAux] = IMPORTANTE;
                        estacionesImportantes[nEstacionesImportantes] = estacionAux;
                        nEstacionesImportantes++;
                    }
                }
                j++;
            }
        }

        for (i = 0; i < nEstacionesImportantes; i++) {
            for (j = 0; j < nEstacionesImportantes; j++) matrizImportantes[i][j] = __INT_MAX__;
        }

        for (i = 0; i < nEstacionesImportantes; i++) matrizImportantes[i][i] = 0;

        // Construir matriz de adyacencia de las estaciones importantes
        for (i = 0; i < nLineas; i++) {
            posEstacionAux2 = -1;
            distancia = 0;
            for (j = 0; j < tamLineas[i]; j++) {
                distancia++;
                posEstacionAux1 = posEstacionImportante(lineas[i][j]);          
                if (posEstacionAux1 != -1) {
                    if (posEstacionAux2 != -1) {
                        if (distancia < matrizImportantes[posEstacionAux1][posEstacionAux2]) {
                            matrizImportantes[posEstacionAux1][posEstacionAux2] = distancia;
                            matrizImportantes[posEstacionAux2][posEstacionAux1] = distancia;
                        }
                    }

                    posEstacionAux2 = posEstacionAux1;
                    distancia = 0;
                }
            }
        }

        // Aplicar Warshall
        for (i = 0; i < nEstacionesImportantes; i++) {
            for (j = 0; j < nEstacionesImportantes; j++) {
                if (j == i) continue;
                for (k = 0; k < nEstacionesImportantes; k++) {
                    if (k == i || k >= j) continue;
                    if (matrizImportantes[i][k] == __INT_MAX__ || matrizImportantes[j][i] == __INT_MAX__) continue;

                    if (matrizImportantes[i][k]+matrizImportantes[j][i] < matrizImportantes[j][k]) {
                        matrizImportantes[j][k] = matrizImportantes[i][k]+matrizImportantes[j][i];
                        matrizImportantes[k][j] = matrizImportantes[j][k];
                    }
                }
            }
        }
    
        // Encontrar es tacion central
        costeMin = __INT_MAX__;
        for (i = 0; i < nEstacionesImportantes; i++) {
            costeAct = 0;
            
            for (j = 0; j < nEstacionesImportantes; j++) {
                if (j != i) costeAct += matrizImportantes[i][j];
            }

            if (costeAct < costeMin) {
                costeMin = costeAct;
                estacionCentral = estacionesImportantes[i];
            } else if (costeAct == costeMin) {
                if (estacionesImportantes[i] < estacionCentral) estacionCentral = estacionesImportantes[i];
            }
        }

        printf("%d\n", estacionCentral+1);
    }
}