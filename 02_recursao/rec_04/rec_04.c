#include <stdio.h>
#include <string.h>

int palindromo(char *string, int tamanho){
    if(tamanho == 0 || tamanho == 1){
        return 1;
    }

    if(string[0] != string [tamanho -1]){
        return 0;
    }
    return palindromo(string + 1, tamanho - 2);
}

int main (){
    char palavra[1001];
    int tamanho;

    while(scanf("%s", palavra) != EOF){
        tamanho = strlen(palavra);

        if(palindromo(palavra, tamanho)){
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}