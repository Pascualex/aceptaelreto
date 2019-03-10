#include <stdio.h>
#include <algorithm>

int movimientos[100];
bool comprobados[100];

int recorrerBucle(int actual, int original) {
    comprobados[actual] = true;

    if (movimientos[actual] == original) return 1;

    return recorrerBucle(movimientos[actual], original)+1;
}

int main() {
    int nMoleculas;
    int nMovimientos;
    int aux, i;

    while (true) {
        scanf("%d", &nMoleculas);
        if (nMoleculas == 0) return 0;

        for (i = 0; i < nMoleculas; i++) {
            scanf("%d", &movimientos[i]);
            movimientos[i]--;
            comprobados[i] = false;
        }

        nMovimientos = 1;
        for (i = 0; i < nMoleculas; i++) {
            if (comprobados[i] == true) continue;

            aux = recorrerBucle(i, i);
            nMovimientos = (nMovimientos*aux)/std::__gcd(nMovimientos, aux);
        }

        printf("%d\n", nMovimientos);
    }
}