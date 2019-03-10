#include <stdio.h>

int main() {
    long long uvas[24];
    long long max, act;
    int nUvas, i, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12;
    int nCombinaciones;

    while (true) {
        scanf("%lld %d", &max, &nUvas);
        if (nUvas == 0) return 0;

        for (i = 0; i < nUvas; i++) {
            scanf("%lld", &uvas[i]);
        }

        nCombinaciones = 0;
        for (i1 = 0; i1 < nUvas-11; i1++) {
            for (i2 = i1+1; i2 < nUvas-10; i2++) {
                for (i3 = i2+1; i3 < nUvas-9; i3++) {
                    for (i4 = i3+1; i4 < nUvas-8; i4++) {
                        for (i5 = i4+1; i5 < nUvas-7; i5++) {
                            for (i6 = i5+1; i6 < nUvas-6; i6++) {
                                for (i7 = i6+1; i7 < nUvas-5; i7++) {
                                    for (i8 = i7+1; i8 < nUvas-4; i8++) {
                                        for (i9 = i8+1; i9 < nUvas-3; i9++) {
                                            for (i10 = i9+1; i10 < nUvas-2; i10++) {
                                                for (i11 = i10+1; i11 < nUvas-1; i11++) {
                                                    for (i12 = i11+1; i12 < nUvas; i12++) {                                                        
                                                        act = uvas[i1]+uvas[i2]+uvas[i3]+uvas[i4]+uvas[i5]+uvas[i6]+uvas[i7]+uvas[i8]+uvas[i9]+uvas[i10]+uvas[i11]+uvas[i12];
                                                        if (act <= max) nCombinaciones++;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }  
                    }
                }
            }
        }

        printf("%d\n", nCombinaciones);
    }
}