#include <stdio.h>

void trianguloFloyd(int n){
    int elementos = 1;
    int i, j;

    for(i = 0; i < n; i++){
        for(j = 0; j <= i; j++){
            printf("%d ", elementos);
            elementos++;
        }
        printf("\n");
    }
}

int main(){
    int n; 

    scanf("%d", &n);
    trianguloFloyd(n);

    return 0;
}