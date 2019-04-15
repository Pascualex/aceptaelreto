#include <stdio.h>

char sala[100][100];

int main() {
    int filas, columnas;
    int consultas;
    int x, y;
    char palabra[10];
    int distancia;
    int i, j;

    while (true) {
        scanf("%d %d", &filas, &columnas);
        if (filas == 0) return 0;

        for (i = 0; i < filas; i++) {
            scanf("%s", sala[i]);
        }

        scanf("%d", &consultas);
        for (i = 0; i < consultas; i++) {
            scanf("%d %d %s", &y, &x, palabra);

            x--;
            y--;

            distancia = -1;
            j = 1;
            if (palabra[1] == 'R') {
                while (y-j >= 0) {
                    if (sala[y-j][x] == 'X') {
                        distancia = j;
                        break;
                    }
                    j++;
                }
            } else if (palabra[1] == 'E') {
                while (x+j < columnas) {
                    if (sala[y][x+j] == 'X') {
                        distancia = j;
                        break;
                    }
                    j++;
                }
            } else if (palabra[1] == 'B') {
                while (y+j < filas) {
                    if (sala[y+j][x] == 'X') {
                        distancia = j;
                        break;
                    }
                    j++;
                }
            } else {
                while (x-j >= 0) {
                    if (sala[y][x-j] == 'X') {
                        distancia = j;
                        break;
                    }
                    j++;
                }
            }

            if (distancia == -1) {
                printf("NINGUNO\n");
            } else {
                printf("%d\n", distancia);
            }
        }

        printf("---\n");
    }
}