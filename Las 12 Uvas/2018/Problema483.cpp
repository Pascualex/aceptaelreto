#include <stdio.h>

int main() {
    int nCasos;
    long long horaIni, minutoIni, segundoIni;
    long long horaFin, minutoFin, segundoFin;
    int nCampanadas, campanada;
    long long horaD, minutoD, segundoD;
    int i;

    scanf("%d", &nCasos);
    for (i = 0; i < nCasos; i++) {
        scanf("%lld:%lld:%lld", &horaIni, &minutoIni, &segundoIni);
        scanf("%lld:%lld:%lld", &horaFin, &minutoFin, &segundoFin);
        scanf("%d %d", &nCampanadas, &campanada);

        if (horaFin < horaIni || horaFin == horaIni && minutoFin < minutoIni || horaFin == horaIni && minutoFin == minutoIni && segundoFin < segundoIni) horaFin += 24;
    
        segundoD = (horaFin-horaIni)*3600+(minutoFin-minutoIni)*60+(segundoFin-segundoIni);
        segundoD = segundoD/(nCampanadas-1)*(campanada-1);

        segundoD += horaIni*3600+minutoIni*60+segundoIni;

        minutoD = segundoD/60;
        segundoD = segundoD%60;
        horaD = minutoD/60;
        minutoD = minutoD%60;

        if (horaD > 23) horaD -= 24;

        printf("%02lld:%02lld:%02lld\n", horaD, minutoD, segundoD);
    }
    
    return 0;
}