#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"

#define MAX_FILMES 100

struct Locadora{
    tFilme **filme;
    int lucro;
    int numFilmes;
};

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora ()
{
    tLocadora *loc = malloc (sizeof(tLocadora));
    loc->filme = NULL;
    loc->numFilmes = 0;
    loc->lucro = 0;

    return loc;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora)
{
    int n = locadora->numFilmes;
    for(int i=0; i<n ; i++ )
    {
        DestruirFilme(locadora->filme[i]);
    }
    free(locadora->filme);
    free(locadora);
}


/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado (tLocadora* locadora, int codigo)
{
    for(int i = 0; i < locadora->numFilmes; i++)
    {
        if(EhMesmoCodigoFilme(locadora->filme[i], codigo))
        return 1;
    }
    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme)
{
    int codigo = ObterCodigoFilme(filme);
    if(VerificarFilmeCadastrado(locadora, codigo))
    {
        printf("Filme ja cadastrado no estoque\n");
        DestruirFilme(filme);
        return;
    }

    if(locadora->numFilmes >= MAX_FILMES)
    {
        printf("Estoque cheio\n");
        DestruirFilme(filme);
        return;
    }

    tFilme **novoVetor = realloc(locadora->filme, (locadora->numFilmes + 1) * sizeof(tFilme *));

    locadora->filme = novoVetor;

    locadora->filme[locadora->numFilmes] = filme;
    locadora->numFilmes++;
    printf("Filme cadastrado %d - ", codigo);
    ImprimirNomeFilme(filme);
    printf("\n");
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* Locadora)
{
    int codigo;

    while(scanf(" %d,", &codigo) == 1)
    {
        tFilme *filme = CriarFilme();

        LeFilme(filme, codigo);

        CadastrarFilmeLocadora(Locadora, filme);
    }
    
    char fim;
    scanf(" %c", &fim);
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos)
{    

    int totalAlugados =0;
    int custoTotal = 0;

    for(int i = 0; i < quantidadeCodigos; i++)
    {
    int codigo = codigos[i];
        if(VerificarFilmeCadastrado(locadora, codigos[i]) == 0)
        {
            printf("Filme nao cadastrado no estoque\n");
        }
        else
        {
            for(int j = 0; j < locadora->numFilmes; j++)
            {
                if(EhMesmoCodigoFilme(locadora->filme[j], codigo))
                {
                    if(ObterQtdEstoqueFilme(locadora->filme[j]) > 0)
                    {
                        AlugarFilme(locadora->filme[j]);

                        totalAlugados++;
                        custoTotal += ObterValorFilme(locadora->filme[j]);
                    }
                    break;
                }
            }
        }
    }
    printf("Total de filmes alugados %d com custo de R$%d\n", totalAlugados, custoTotal);
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora)
{
    int codigos[MAX_FILMES];
    int quantidadeCodigos = 0;
    int codigo;

    while(scanf("%d\n", &codigo) == 1)
    {
        codigos[quantidadeCodigos] = codigo;
        quantidadeCodigos++;
    }
    char fim;
    scanf("%c\n", &fim);

    AlugarFilmesLocadora(locadora, codigos, quantidadeCodigos);
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos)
{
    for(int i = 0; i < quantidadeCodigos; i++)
    {
        int codigo = codigos[i];

        if(VerificarFilmeCadastrado(locadora, codigo) == 0)
        {
            printf("Filme nao cadastrado no estoque\n");
        }
        else
        {
            for( int j = 0; j < locadora->numFilmes; j++)
            {
                if(EhMesmoCodigoFilme(locadora->filme[j], codigo))
                {
                    if(ObterQtdAlugadaFilme(locadora->filme[j]) > 0)
                    {
                        DevolverFilme(locadora->filme[j]);

                        locadora->lucro += ObterValorFilme(locadora->filme[j]);

                        printf("Filme %d - ", codigo);
                        ImprimirNomeFilme(locadora->filme[j]);
                        printf(" Devolvido!\n");
                    }
                    break;
                }
            }
        }
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora)
{
    int codigos[MAX_FILMES];
    int quantidadeCodigos = 0;
    int codigo;

    while(scanf("%d\n", &codigo) == 1)
    {
        codigos[quantidadeCodigos] = codigo;
        quantidadeCodigos++;
    }
    char fim;
    scanf("%c\n", &fim);

    DevolverFilmesLocadora(locadora, codigos, quantidadeCodigos);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora)
{
     for (int i = 0; i < locadora->numFilmes - 1; i++)
    {
        for (int j = 0; j < locadora->numFilmes - 1 - i; j++)
        {
            if (CompararNomesFilmes(locadora->filme[j], locadora->filme[j + 1]) > 0)
            {
                tFilme *aux = locadora->filme[j];
                locadora->filme[j] = locadora->filme[j + 1];
                locadora->filme[j + 1] = aux;
            }
        }
    }
}


/**
 * @brief Consulta o estoque de filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora (tLocadora* locadora)
{
    OrdenarFilmesLocadora(locadora);

    printf("~ESTOQUE~\n");

    for (int i = 0; i < locadora->numFilmes; i++)
    {
        printf("%d - ", ObterCodigoFilme(locadora->filme[i]));
        ImprimirNomeFilme(locadora->filme[i]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filme[i]));
    }
}
/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora)
{
    printf("Lucro: %d\n", locadora->lucro);
}

