#include <stdio.h>

int tamGX, tamGY;
int granero[50][50];

void recorridoPollito(int posX, int posY, char dir, int pasos) {
    int pasosRAct, pasosRMax, nDir;
    bool aumento = false;

    if (dir == 'N') nDir = 0;
    else if (dir == 'E') nDir = 1;
    else if (dir == 'S') nDir = 2;
    else if (dir == 'W') nDir = 3;

    pasosRAct = 0;
    pasosRMax = 1;
    while (true) {
        granero[posY][posX]++;
        if (pasos == 0) return;

        if (nDir == 0) {
            if (posY-1 < 0) return;
            posY--;
        } else if (nDir == 1) {
            if (posX+1 >= tamGX) return;
            posX++;
        } else if (nDir == 2) {
            if (posY+1 >= tamGY) return;
            posY++;
        } else {
            if (posX-1 < 0) return;
            posX--;
        }

        pasosRAct++;
        if (pasosRAct == pasosRMax) {
            nDir = (nDir+1)%4;
            pasosRAct = 0;
            if (aumento == true) {
                pasosRMax++;
                aumento = false;
            } else {
                aumento = true;
            }           
        }
        
        pasos--;
    }
}

int main() {
    int nCasos;    
    int nPollitos;
    int posX, posY, pasos;
    char dir;
    int i, j, k;

    scanf("%d", &nCasos);

    for (i = 0; i < nCasos; i++) {
        scanf("%d %d %d", &tamGY, &tamGX, &nPollitos);
    
        for (j = 0; j < tamGY; j++) {
            for (k = 0; k < tamGX; k++) {
                granero[j][k] = 0;
            }
        }

        for (j = 0; j < nPollitos; j++) {
            scanf("%d %d %c %d", &posY, &posX, &dir, &pasos);
            recorridoPollito(posX-1, posY-1, dir, pasos);
        }

        for (j = 0; j < tamGY; j++) {
            for (k = 0; k < tamGX; k++) {
                if (k == tamGX-1) {
                    printf("%d\n", granero[j][k]);
                } else {
                    printf("%d ", granero[j][k]);
                }
            }
        }
        printf("---\n");
    }

    return 0;
}