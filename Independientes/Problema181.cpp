#include <stdio.h>

char tablero[15][15];
int nRutas[15][15];

int calcularNRutas(int x, int y, int ladoTablero) {
    if (nRutas[y][x] != -1) return nRutas[y][x];

    if (x+1 < ladoTablero && tablero[y][x+1] == '.') {
        if (y-1 >= 0 && tablero[y-1][x] == '.') {
            nRutas[y][x] = calcularNRutas(x+1, y, ladoTablero)+calcularNRutas(x, y-1, ladoTablero);            
        } else {
            nRutas[y][x] = calcularNRutas(x+1, y, ladoTablero);
        }
    } else {
        if (y-1 >= 0 && tablero[y-1][x] == '.') {
            nRutas[y][x] = calcularNRutas(x, y-1, ladoTablero);            
        } else {
            nRutas[y][x] = 0;
        }
    }

    return nRutas[y][x];
}

int main() {
    int ladoTablero;
    int i, j;

    while (true) {
        scanf("%d", &ladoTablero);
        if (ladoTablero == 0) return 0;

        for (i = 0; i < ladoTablero; i++) {
            scanf("%s", tablero[i]);
            for (j = 0; j < ladoTablero; j++) {                
                nRutas[i][j] = -1;
            }
        }
        nRutas[0][ladoTablero-1] = 1;        

        printf("%d\n", calcularNRutas(0, ladoTablero-1, ladoTablero));
    }
}