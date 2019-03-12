#include <stdio.h>

int main() {
    int tablero[100];
    int C, N;
    int I, R, P;
    int alturaMax;
    int i;

    while (true) {
        scanf("%d %d", &C, &N);
        if (C == 0) return 0;

        for (i = 0; i < C; i++) {
            tablero[i] = 0;
        }

        for (i = 0; i < N; i++) {
            scanf("%d %d %d", &I, &R, &P);
            P--;

            alturaMax = 0;        
            if (I == 1) {                
                if (R == 0 || R == 180) {
                    if (tablero[P] > alturaMax) alturaMax = tablero[P];
                    if (tablero[P+1] > alturaMax) alturaMax = tablero[P+1];
                    if (tablero[P+2] > alturaMax) alturaMax = tablero[P+2];
                    if (tablero[P+3] > alturaMax) alturaMax = tablero[P+3];
                    
                    tablero[P] = alturaMax+1;
                    tablero[P+1] = alturaMax+1;
                    tablero[P+2] = alturaMax+1;
                    tablero[P+3] = alturaMax+1;                    
                } else {
                    tablero[P] += 4;
                }
            } else if (I == 2) {
                if (R == 0) {
                    if (tablero[P] > alturaMax) alturaMax = tablero[P];
                    if (tablero[P+1] > alturaMax) alturaMax = tablero[P+1];
                    if (tablero[P+2] > alturaMax) alturaMax = tablero[P+2];

                    tablero[P] = alturaMax+2;
                    tablero[P+1] = alturaMax+1;
                    tablero[P+2] = alturaMax+1;
                } else if (R == 90) {
                    if (tablero[P] > alturaMax) alturaMax = tablero[P];
                    if (tablero[P+1] > alturaMax) alturaMax = tablero[P+1];

                    tablero[P] = alturaMax+1;
                    tablero[P+1] = alturaMax+3;
                } else if (R == 180) {
                    if (tablero[P]-1 > alturaMax) alturaMax = tablero[P]-1;
                    if (tablero[P+1]-1 > alturaMax) alturaMax = tablero[P+1]-1;
                    if (tablero[P+2] > alturaMax) alturaMax = tablero[P+2];

                    tablero[P] = alturaMax+2;
                    tablero[P+1] = alturaMax+2;
                    tablero[P+2] = alturaMax+2;
                } else {
                    if (tablero[P] > alturaMax) alturaMax = tablero[P];
                    if (tablero[P+1]-2 > alturaMax) alturaMax = tablero[P+1]-2;

                    tablero[P] = alturaMax+3;
                    tablero[P+1] = alturaMax+3;
                }
            } else if (I == 3) {
                if (R == 0) {
                    if (tablero[P] > alturaMax) alturaMax = tablero[P];
                    if (tablero[P+1] > alturaMax) alturaMax = tablero[P+1];
                    if (tablero[P+2] > alturaMax) alturaMax = tablero[P+2];

                    tablero[P] = alturaMax+1;
                    tablero[P+1] = alturaMax+1;
                    tablero[P+2] = alturaMax+2;
                } else if (R == 90) {
                    if (tablero[P]-2 > alturaMax) alturaMax = tablero[P]-2;
                    if (tablero[P+1] > alturaMax) alturaMax = tablero[P+1];

                    tablero[P] = alturaMax+3;
                    tablero[P+1] = alturaMax+3;
                } else if (R == 180) {
                    if (tablero[P] > alturaMax) alturaMax = tablero[P];
                    if (tablero[P+1]-1 > alturaMax) alturaMax = tablero[P+1]-1;
                    if (tablero[P+2]-1 > alturaMax) alturaMax = tablero[P+2]-1;

                    tablero[P] = alturaMax+2;
                    tablero[P+1] = alturaMax+2;
                    tablero[P+2] = alturaMax+2;
                } else {
                    if (tablero[P] > alturaMax) alturaMax = tablero[P];
                    if (tablero[P+1] > alturaMax) alturaMax = tablero[P+1];

                    tablero[P] = alturaMax+3;
                    tablero[P+1] = alturaMax+1;
                }
            } else if (I == 4) {
                if (tablero[P] > alturaMax) alturaMax = tablero[P];
                if (tablero[P+1] > alturaMax) alturaMax = tablero[P+1];

                tablero[P] = alturaMax+2;
                tablero[P+1] = alturaMax+2;
            } else if (I == 5) {
                if (R == 0 || R == 180) {
                    if (tablero[P] > alturaMax) alturaMax = tablero[P];
                    if (tablero[P+1] > alturaMax) alturaMax = tablero[P+1];
                    if (tablero[P+2]-1 > alturaMax) alturaMax = tablero[P+2]-1;

                    tablero[P] = alturaMax+1;
                    tablero[P+1] = alturaMax+2;
                    tablero[P+2] = alturaMax+2;
                } else {
                    if (tablero[P]-1 > alturaMax) alturaMax = tablero[P]-1;
                    if (tablero[P+1] > alturaMax) alturaMax = tablero[P+1];

                    tablero[P] = alturaMax+3;
                    tablero[P+1] = alturaMax+2;
                }
            } else if (I == 6) {
                if (R == 0) {
                    if (tablero[P] > alturaMax) alturaMax = tablero[P];
                    if (tablero[P+1] > alturaMax) alturaMax = tablero[P+1];
                    if (tablero[P+2] > alturaMax) alturaMax = tablero[P+2];

                    tablero[P] = alturaMax+1;
                    tablero[P+1] = alturaMax+2;
                    tablero[P+2] = alturaMax+1;
                } else if (R == 90) {
                    if (tablero[P]-1 > alturaMax) alturaMax = tablero[P]-1;
                    if (tablero[P+1] > alturaMax) alturaMax = tablero[P+1];

                    tablero[P] = alturaMax+2;
                    tablero[P+1] = alturaMax+3;
                } else if (R == 180) {
                    if (tablero[P]-1 > alturaMax) alturaMax = tablero[P]-1;
                    if (tablero[P+1] > alturaMax) alturaMax = tablero[P+1];
                    if (tablero[P+2]-1 > alturaMax) alturaMax = tablero[P+2]-1;

                    tablero[P] = alturaMax+2;
                    tablero[P+1] = alturaMax+2;
                    tablero[P+2] = alturaMax+2;
                } else {
                    if (tablero[P] > alturaMax) alturaMax = tablero[P];
                    if (tablero[P+1]-1 > alturaMax) alturaMax = tablero[P+1]-1;

                    tablero[P] = alturaMax+3;
                    tablero[P+1] = alturaMax+2;
                }
            } else if (I == 7) {
                if (R == 0 || R == 180) {
                    if (tablero[P]-1 > alturaMax) alturaMax = tablero[P]-1;
                    if (tablero[P+1] > alturaMax) alturaMax = tablero[P+1];
                    if (tablero[P+2] > alturaMax) alturaMax = tablero[P+2];

                    tablero[P] = alturaMax+2;
                    tablero[P+1] = alturaMax+2;
                    tablero[P+2] = alturaMax+1;
                } else {
                    if (tablero[P] > alturaMax) alturaMax = tablero[P];
                    if (tablero[P+1]-1 > alturaMax) alturaMax = tablero[P+1]-1;

                    tablero[P] = alturaMax+2;
                    tablero[P+1] = alturaMax+3;
                }
            }
        }

        for (i = 0; i < C; i++) {
            if (i < C-1 ) printf("%d ", tablero[i]);
            else printf("%d\n", tablero[i]);
        }
    }
}