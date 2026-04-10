#include <stdio.h>
#include "esfera_utils.h"

int main (){

    float raio, area, volume;

    scanf("%f", &raio);
    area = calcula_area(raio);
    volume = calcula_volume(raio);

    printf("Area: %.2f\n", area);
    printf("Volume: %.2f", volume);

    return 0;
}