#include <stdlib.h>
#include <stdio.h>
#include "pacote.h"
#include "gerenciadorpacotes.h"

void ImprimeMenu(){
    printf("\nEscolha uma opcao:\n");
    printf("\t(1) Cadastrar um novo pacote\n");
    printf("\t(2) Imprimir um pacote especifico\n");
    printf("\t(3) Imprimir todos os pacotes e sair\n");
}

int main()
{
    tGerenciador *g = CriaGerenciador();

    int op = 0;
    int tipo, nElem, idx;

    while (op != 3)
    {
        ImprimeMenu();
        scanf("%d\n", &op);

        if(op == 1)
        {
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos: ");
            scanf("%d %d", &tipo, &nElem);

            if(tipo == CHAR || tipo == INT)
            {
                tPacote *pac = CriaPacote(tipo, nElem);
                LePacote(pac);
                AdicionaPacoteNoGerenciador(g, pac);
            }
            else
            {
                printf("Erro: Digite um tipo valido!\n");
            }
        }
        else
        {
            if(op == 2) 
            {
                printf("Digite o indice do pacote: ");
                scanf("%d\n", &idx);
                ImprimirPacoteNoIndice(g, idx);
            }
            else
            {
                if (op == 3)
                {
                    ImprimirTodosPacotes(g);
                }
                else
                printf("Escolha uma opcao valida para o menu!\n");
            }
        }
    }

    DestroiGerenciador(g);

return 0;
}