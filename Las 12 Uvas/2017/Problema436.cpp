#include <stdio.h>

int main() {
    long long grosorP, grosorE;
    int dobleces;

    while (true) {
        scanf("%lld %lld", &grosorP, &grosorE);
        if (feof(stdin)) return 0;

        grosorE *= 1000000;

        dobleces = 0;
        while (grosorP < grosorE) {
            grosorP *= 2;
            dobleces++;
        }

        printf("%d\n", dobleces);
    }
}