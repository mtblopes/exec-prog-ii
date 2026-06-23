#include <stdio.h>
#include <stdlib.h>
#include "banco.h"
#include "agencia.h"
#include "vector.h"

/**
 * @brief Estrutura para representar um banco.
 */
struct Banco
{
    char *nome;
    Vector *agencias;
};

/**
 * @brief Função para criar um novo banco.
 * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tBanco *CriaBanco()
{
    tBanco *banco = (tBanco *) malloc (sizeof(tBanco));
    banco->nome = (char *) malloc (sizeof(char)*100);
    banco->agencias = VectorConstruct();

    return banco;
}

/**
 * @brief Função para destruir um banco.
 * @param banco O banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{
    free(banco->nome);
    VectorDestroy(banco->agencias, DestroiAgencia);
    free(banco);
}


/**
 * @brief Função para ler o nome de um banco.
 * @param banco O banco a ser lido.
 */
void LeBanco(tBanco *banco)
{
    scanf(" %[^\n]\n", banco->nome);
}

/**
 * @brief Função para adicionar uma agência a um banco.
 * @param banco O banco.
 * @param agencia A agência a ser adicionada.
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia)
{
    VectorPushBack(banco->agencias, agencia);
}


/**
 * @brief Função para inserir uma conta em uma agência pertencente ao banco.
 * @param banco O banco.
 * @param numAgencia O número da agência.
 * @param cliente A conta a ser inserida.
 * @pre A agência deve pertencer ao banco.
*/
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente)
{
    int qtdAgencias = VectorSize(banco->agencias);

    for(int i = 0; i < qtdAgencias; i++)
    {
        tAgencia *atual = (tAgencia *) VectorGet(banco->agencias, i);
        if(ComparaAgencia(numAgencia, atual))
        {
            AdicionaConta(atual, cliente);
            break;
        }
    }

}

/**
 * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
 * @param banco O banco.
 */
void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");
    int qtdAgencias = VectorSize(banco->agencias);

    for(int i = 0; i < qtdAgencias; i++)
    {
        tAgencia *agencia = VectorGet(banco->agencias, i);
        ImprimeDadosAgencia(agencia);
    }

}

