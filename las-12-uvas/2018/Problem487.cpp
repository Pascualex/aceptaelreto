#include <stdio.h>

int main() {
    long long horas, extras, vueltas;   
    int nCasos;
    int i;

    scanf("%d", &nCasos);

    for (i = 0; i < nCasos; i++) {
        scanf("%lld", &horas);

        vueltas = horas;
        while (horas >= 3600) {
            extras = horas/3600;
            horas = horas%3600+extras;
            vueltas += extras;
        }

        printf("%lld\n", vueltas);
    }
    
    return 0;
}