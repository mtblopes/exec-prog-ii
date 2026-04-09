#include <stdio.h>

int somaDigitos(int n){
    if(!n){
        return 0;
    }
    int soma = n%10;

    return soma + somaDigitos(n/10);
}

int main(){
    int n;
    scanf("%d", &n);

    n = somaDigitos(n);
    printf("%d", n);
return 0;
}

