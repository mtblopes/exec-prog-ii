#include <stdio.h>
#include <math.h>

typedef struct{
    float x;
    float y;
    float raio;
} tCoord;

tCoord leCoordenadas(){
    tCoord coord;
    scanf("%f %f %f", &coord.x, &coord.y, &coord.raio);
    return coord;
}

float calculaDistancia(tCoord alvo, tCoord tiro){
    return sqrt((alvo.x - tiro.x)*(alvo.x - tiro.x) + (alvo.y - tiro.y)*(alvo.y - tiro.y));
}

void acertouAlvo(tCoord alvo, tCoord tiro){
    float soma;
    soma = alvo.raio + tiro.raio;
    if(calculaDistancia(alvo, tiro) <= soma){
        printf("ACERTOU");
    } else {
        printf ("ERROU");
    }
}

int main () {
    tCoord alvo, tiro;

    alvo = leCoordenadas();
    tiro = leCoordenadas();

    calculaDistancia(alvo, tiro);
    acertouAlvo(alvo, tiro);

return 0;
}