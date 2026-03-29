/*  Exercicio Revisao 04 
    Maria Teresa */

#include <stdio.h>

int transformaOctal (int num){
    int i = 1, divisor = 0;
    int resto = 0;
    int soma = 0;

    resto = num % 8;
    divisor = num/8;
    soma = resto;  

    while (divisor){
        i = i*10;
        resto = divisor % 8;
        divisor = divisor / 8;
        soma = soma + (resto * i);
    }

    return soma;
}

int main(){
    int n, octal;

    scanf("%d", &n);
    octal = transformaOctal(n);

    printf("%d", octal);

    return 0;
}