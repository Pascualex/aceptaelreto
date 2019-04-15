#include <stdio.h>
#include <string.h>

int main() {
    int tabla[1000000];
    int filas, columnas, nModificaciones;
    int columna, ini, fin, modificacion;
    int actual;
    int i, j;

    while (true) {
        scanf("%d %d %d", &filas, &columnas, &nModificaciones);
        if (filas == 0) return 0;

        memset(tabla, 0, filas*columnas*sizeof(int));

        for (i = 0; i < nModificaciones; i++) {
            scanf("%d %d %d %d", &columna, &ini, &fin, &modificacion);
            tabla[ini*columnas+columna] += modificacion;
            if (fin < filas-1) tabla[(fin+1)*columnas+columna] -= modificacion;    
        }

        for (j = 0; j < columnas; j++) {
            actual = 0;
            for (i = 0; i < filas; i++) {
                actual += tabla[i*columnas+j];
                tabla[i*columnas+j] = actual;
            }
        }

        for (i = 0; i < filas; i++) {
            for (j = 0; j < columnas; j++) {
                if (j < columnas-1) {
                    printf("%d ", tabla[i*columnas+j]);
                } else {
                    printf("%d\n", tabla[i*columnas+j]);
                }               
            }
        }
    }
}