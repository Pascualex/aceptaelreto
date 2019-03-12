#include <stdio.h>
#include <algorithm>

int main() {
    int grupos[100000], aulas[100000];
    int nGrupos, nAulas, margen;
    int i;

    while (true) {
        scanf("%d %d", &nGrupos, &nAulas);
        if (feof(stdin)) return 0;

        for (i = 0; i < nGrupos; i++) {
            scanf("%d", &grupos[i]);
        }

        for (i = 0; i < nAulas; i++) {
            scanf("%d", &aulas[i]);
        }

        if (nGrupos > nAulas) {
            printf("NO\n");
            continue;
        }

        std::sort(grupos, grupos+nGrupos);
        std::sort(aulas, aulas+nAulas);

        margen = nAulas-nGrupos;

        for (i = 0; i < nGrupos; i++) {
            if (grupos[i] > aulas[margen+i]) {
                printf("NO\n");
                break;
            }
        }

        if (i == nGrupos) printf("SI\n");
    }
}