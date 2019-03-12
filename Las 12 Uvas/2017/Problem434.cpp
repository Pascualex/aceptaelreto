#include <stdio.h>

int main() {
    int casos;
    int palomas, cajas;
    int i;

    scanf("%d", &casos);

    for (i = 0; i < casos; i++) {
        scanf("%d %d", &palomas, &cajas);

        if (palomas > cajas) {
            printf("PRINCIPIO\n");
        } else {
            printf("ROMANCE\n");
        }
    }
}