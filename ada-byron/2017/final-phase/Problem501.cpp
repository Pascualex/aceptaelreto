#include <stdio.h>

int main() {
    int td, ta, dd, da, no;
    int drd, dra;
    int dadosActD[6], dadosActA[6];
    int balance;
    int i, j, aux;

    while (true) {
        scanf("%d %d %d %d %d", &td, &ta, &dd, &da, &no);
        if (feof(stdin)) return 0;

        for (i = 0; i < no; i++) {
            if (td == 0 || ta == 0) break;

            for (j = 0; j < 6; j++) {
                dadosActD[j] = 0;
                dadosActA[j] = 0;
            }

            if (dd <= td) drd = dd;
            else drd = td;

            for (j = 0; j < drd; j++) {
                scanf("%d", &aux);
                dadosActD[aux-1]++;
            }

            if (da <= ta) dra = da;
            else dra = ta;

            for (j = 0; j < dra; j++) {
                scanf("%d", &aux);
                dadosActA[aux-1]++;
            }

            balance = 0;
            for (j = 5; j >= 0; j--) {
                balance += dadosActD[j];
                if (balance > 0) {
                    if (dadosActA[j] >= balance) {
                        dadosActA[j] -= balance;
                        ta -= balance;
                        balance = 0;
                    } else {
                        balance -= dadosActA[j];
                        ta -= dadosActA[j];
                        dadosActA[j] = 0;
                    }
                }
                if (j > 0) {
                    balance -= dadosActA[j];
                    if (balance < 0) {
                        if (dadosActD[j-1] >= -balance) {
                            dadosActD[j-1] += balance;
                            td += balance;
                            balance = 0;
                        } else {
                            balance += dadosActD[j-1];
                            td -= dadosActD[j-1];
                            dadosActD[j-1] = 0;
                        }
                    }
                }                
            }            
        }

        printf("%d %d\n", td, ta);
    }
}