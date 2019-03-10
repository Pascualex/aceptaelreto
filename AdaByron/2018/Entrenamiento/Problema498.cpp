#include <stdio.h>
#include <math.h>

int main() {
    long long k, n;
    long long movimientoTotales;
    long long m1, m2;

    while (true) {
        scanf("%lld %lld", &k, &n);
        if (k == 0) return 0;

        movimientoTotales = pow(2, n)-1;

        m1 = pow(2, k-1)+(k-1)*pow(2, k);
        if (m1 > movimientoTotales) {
            m1 = -1;
            m2 = -1;
        } else {
            m2 = movimientoTotales+1-m1-pow(2, k);
            if (m2 <= 0) m2 = -1;
        }
        
        printf("%lld %lld %lld %lld\n", k, n, m1, m2);
    }
}