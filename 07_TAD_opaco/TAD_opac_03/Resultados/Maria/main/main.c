#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

int main()
{
    tLocadora *locadora = CriarLocadora();

    char operacao[30];

    while (scanf(" %29s", operacao) == 1)
    {
        if (strcmp(operacao, "Cadastrar") == 0)
        {
            LerCadastroLocadora(locadora);
            printf("\n");
        }
        else if (strcmp(operacao, "Alugar") == 0)
        {
            LerAluguelLocadora(locadora);
            printf("\n");
        }
        else if (strcmp(operacao, "Devolver") == 0)
        {
            LerDevolucaoLocadora(locadora);
            printf("\n");
        }
        else if (strcmp(operacao, "Estoque") == 0)
        {
            ConsultarEstoqueLocadora(locadora);

            char fim;
            scanf(" %c", &fim); // consome o '#'

            printf("\n");
        }
    }

    ConsultarLucroLocadora(locadora);

    DestruirLocadora(locadora);

    return 0;
}