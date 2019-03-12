#include <stdio.h>
#include <algorithm>

int nMejillones;
int mejAct;
int montones[500000], nMontones;
int montonMax;
int i, j;

int main() {    
    while (true) {
        scanf("%d", &nMejillones);
        if (feof(stdin)) return 0;
    
        nMontones = 0;
        for (i = 0; i < nMejillones; i++) {
            scanf("%d", &mejAct);

            montonMax = -1;
            for (j = nMontones-1; j >= 0; j--) {
                if (montones[j] > mejAct) {
                    montonMax = j;
                    break;
                }
            }

            if (montonMax == -1) {
                montones[nMontones] = mejAct;
                nMontones++;
            } else {                
                montones[montonMax] = mejAct;
                std::sort(montones, montones+nMontones);
            }
        }

        printf("%d\n", nMontones);
    }
}