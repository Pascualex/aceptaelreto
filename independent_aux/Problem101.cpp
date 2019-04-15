#include <stdio.h>

int main() {
    int n = 1;
    int cuadrado[1000][1000];
    int cifras[1000*1000];

    while (n != 0) {
        scanf("%d", &n);
        if (n == 0) continue;
        
        // Resetear cifras
        for (int i = 0; i < n*n; i++) cifras[i] = false;

        // Leer el cuadrado y marcar las cifras presentes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &cuadrado[i][j]);
                cifras[cuadrado[i][j]-1] = true;
            }
        }

        // Calcular las cm de las diagonales
        int cm = 0;
        int cmAux1 = 0;
        for (int i = 0; i < n; i++) {
            cm += cuadrado[i][i];
            cmAux1 += cuadrado[i][n-i-1];
        }            
        if (cm != cmAux1) {
            printf("NO\n");
            continue;
        }            

        // Calcular las cm de las columnas y filas
        int cmAux2 = 0;
        int i = 0;
        for (i = 0; i < n; i++) {
            cmAux1 = 0;
            cmAux2 = 0;
            for (int j = 0; j < n; j++) {
                cmAux1 += cuadrado[i][j];
                cmAux2 += cuadrado[j][i];
            }
            if (cmAux1 != cm || cmAux2 != cm) {
                printf("NO\n");
                break;
            }
        }
        if (i != n) continue;

        // Comprobar que están todas las cifras
        for (i = 0; i < n*n; i++) {
            if (cifras[i] == false) {
                printf("DIABOLICO\n");
                break;
            }
        }
        if (i != n*n) continue;

        // Comprobar la cm2
        int cm2 = cuadrado[0][0];
        cm2 += cuadrado[0][n-1];
        cm2 += cuadrado[n-1][0];
        cm2 += cuadrado[n-1][n-1];
        if (cm2 != 4*cm/n) {
            printf("DIABOLICO\n");
            continue;
        }

        // Comprobar si n es par o impar
        if (n%2 == 0) {
            // n par
            // Comprobar que las 4 casillas centrales suman la cm2
            int cm2Aux = cuadrado[n/2-1][n/2-1];
            cm2Aux += cuadrado[n/2-1][n/2];
            cm2Aux += cuadrado[n/2][n/2-1];
            cm2Aux += cuadrado[n/2][n/2];
            if (cm2Aux != cm2) {
                printf("DIABOLICO\n");
                continue;
            }

            // Comprobar que los centros de los laterales suman la cm2x2
            cm2Aux = cuadrado[0][n/2-1];
            cm2Aux += cuadrado[0][n/2];
            cm2Aux += cuadrado[n/2-1][0];
            cm2Aux += cuadrado[n/2][0];
            cm2Aux += cuadrado[n/2-1][n-1];
            cm2Aux += cuadrado[n/2][n-1];
            cm2Aux += cuadrado[n-1][n/2-1];
            cm2Aux += cuadrado[n-1][n/2];
            if (cm2Aux != cm2*2) {
                printf("DIABOLICO\n");
            } else {
                printf("ESOTERICO\n");
            }
        } else {
            // n impar
            // Comprobar que el centro por 4 es la cm2
            if (cuadrado[n/2][n/2]*4 != cm2) {
                printf("DIABOLICO\n");
                continue;
            }
            
            // Comprobar que los centros de los laterales suman la cm2
            int cm2Aux = cuadrado[0][n/2];
            cm2Aux += cuadrado[n/2][0];
            cm2Aux += cuadrado[n/2][n-1];
            cm2Aux += cuadrado[n-1][n/2];
            if (cm2Aux != cm2) {
                printf("DIABOLICO\n");
            } else {
                printf("ESOTERICO\n");
            }
        }
    }
}