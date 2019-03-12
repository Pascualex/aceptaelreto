#include <stdio.h>

int main() {
    long long envoltoriosOf, chiclesOf, chiclesIni, envoltoriosAct, chiclesT, i;

    while (true) {
        scanf("%lld %lld %lld", &envoltoriosOf, &chiclesOf, &chiclesIni);
        if (envoltoriosOf == 0) return 0;

        if (chiclesOf == 0) {
            printf("%lld %lld\n", chiclesIni, chiclesIni);
            continue;
        }

        if (chiclesOf >= envoltoriosOf && chiclesIni >= envoltoriosOf) {
            printf("RUINA\n");
        } else {
            chiclesT = chiclesIni;
            envoltoriosAct = chiclesIni;
            while (envoltoriosAct >= envoltoriosOf) {
                i = envoltoriosAct/envoltoriosOf;
                chiclesT += chiclesOf*i;
                envoltoriosAct = envoltoriosAct%envoltoriosOf+chiclesOf*i;
            }
            printf("%lld %lld\n", chiclesT, envoltoriosAct);
        }
    }
}