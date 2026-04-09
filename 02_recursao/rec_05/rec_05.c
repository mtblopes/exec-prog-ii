#include <stdio.h>

int fatorial(int n){
    if(!n){
        return 1;
    }
    else {
        return n * fatorial(n-1);
    }
}

int main(){

    int n;

    scanf("%d", &n);
    n = fatorial(n);
    printf("%d", n);

    return 0;
}