#include <stdio.h>

int F, C;
char plantacion[100][101];

int buscar(int x, int y) {
    int tam = 1;

    plantacion[y][x] = 'X';

    if (x > 0 && plantacion[y][x-1] == '#') tam += buscar(x-1, y);
    if (x < C-1 && plantacion[y][x+1] == '#') tam += buscar(x+1, y);
    if (y > 0 && plantacion[y-1][x] == '#') tam += buscar(x, y-1);
    if (y < F-1 && plantacion[y+1][x] == '#') tam += buscar(x, y+1);

    return tam;
}

int main() {
    int i, j;
    int act, max;

    while (true) {
        scanf("%d %d%*c", &F, &C);
        if (feof(stdin)) return 0;

        for (i = 0; i < F; i++) {
            scanf("%[^\n]%*c", plantacion[i]);
        }

        max = 0;
        for (i = 0; i < F; i++) {
            for (j = 0; j < C; j++) {
                if (plantacion[i][j] == '#') {
                    act = buscar(j, i);
                    if (act > max) max = act;
                }
            }
        }

        printf("%d\n", max);
    }
}