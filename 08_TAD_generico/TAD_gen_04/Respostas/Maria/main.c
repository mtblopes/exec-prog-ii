#include <stdio.h>
#include<stdlib.h>
#include "banco.h"
#include "agencia.h"
#include "conta.h"
#include "vector.h"

int main ()
{
    char caractere;

    tBanco* banco = CriaBanco();
    LeBanco(banco);

    scanf("%c\n", &caractere);
    while(caractere != 'F'){

        if(caractere == 'A')     //agencia
        {
            tAgencia *agencia = CriaAgencia();
            LeAgencia(agencia);
            AdicionaAgencia(banco, agencia);
            
        } 
        else
        {
            if(caractere == 'C')
            {
                tConta *conta = CriaConta();
                LeConta(conta);
                int numAgencia;
                scanf("%d\n", &numAgencia);
                InsereContaBanco(banco, numAgencia, conta);
               
            }
        }
        scanf("%c\n", &caractere);
    }
    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);


    return 0;
}