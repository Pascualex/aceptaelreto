#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int nEdificios;
    vector<pair<int, int>> edificios;
    int inicio, fin;
    int nTuneles, ultimoTunel;
    int i;

    while (true) {
        scanf("%d", &nEdificios);
        if (nEdificios == 0) return 0;

        edificios.clear();

        for (i = 0; i < nEdificios; i++) {
            scanf("%d %d", &inicio, &fin);
            edificios.push_back(make_pair(fin-1, inicio));
        }

        sort(edificios.begin(), edificios.end());

        nTuneles = 0;
        ultimoTunel = -1;
        for (i = 0; i < nEdificios; i++) {
            if (edificios[i].second > ultimoTunel) {
                nTuneles++;
                ultimoTunel = edificios[i].first;
            }
        }

        printf("%d\n", nTuneles);
    }
}