#include <stdio.h>

int main() {
    int numGrupos, numEscaladores;
    int velAux, velLider;
    int grupoMin, grupoMax;
    int tamanioGrupo;

    while (true) {
        scanf("%d", &numEscaladores);
        if (numEscaladores == 0) break;

        numGrupos = 0;        
        velLider = 1000000001;
        grupoMin = 10000;
        grupoMax = 0;         
        tamanioGrupo = 0;
        
        for (int i = 0; i < numEscaladores; i++) {
            scanf("%d", &velAux);
            if (velAux >= velLider) {
                tamanioGrupo++;
            } else {
                if (velLider <= 1000000000) {
                    if (tamanioGrupo > grupoMax) grupoMax = tamanioGrupo;
                    if (tamanioGrupo < grupoMin) grupoMin = tamanioGrupo;
                }
                numGrupos++;
                velLider = velAux;
                tamanioGrupo = 1;
            }
        }

        if (tamanioGrupo > grupoMax) grupoMax = tamanioGrupo;
        if (tamanioGrupo < grupoMin) grupoMin = tamanioGrupo;
        
        printf("%d %d %d\n", numGrupos, grupoMin, grupoMax);
    }
}