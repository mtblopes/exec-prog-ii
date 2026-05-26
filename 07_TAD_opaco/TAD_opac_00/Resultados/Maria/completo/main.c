#include <stdio.h>
#include "circulo.h"
#include "ponto.h"

int main () 
{
    float x, y, r, x2, y2;
    scanf("%f %f %f %f %f", &x, &y, &r, &x2, &y2);
    
    tCirculo c = Circulo_Cria(x, y, r);
    tPonto np = Pto_Cria(x2, y2);

    printf("%d", Circulo_Interior(c, np));

    Pto_Apaga(np);
    Circulo_Apaga(c);

return 0;
}