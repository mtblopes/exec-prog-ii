#include <stdio.h>
#include <string.h>

void imprimeInvertido(char *string){
    if(*string == '\0'){
        return;
    }

    imprimeInvertido(string + 1);

    printf("%c", *string);
}

int main (){
    char palavra[1001];

    while (scanf("%s", palavra) != EOF){

        imprimeInvertido(palavra);

        printf(" ");
    }

    return 0;
}