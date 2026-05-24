#include <stdio.h>
#include "tDepartamento.h"

int main()
{
    int n;
    scanf("%d\n", &n);

    tDepartamento depto[n];
    char nome[STRING_MAX];
    char curso1[STRING_MAX];
    char curso2[STRING_MAX];
    char curso3[STRING_MAX];
    char diretor[STRING_MAX];
    int m1,m2,m3;

    for(int i=0; i <n ; i++)
    {
        scanf(" %[^\n]",nome);
        scanf(" %[^\n]",diretor);
        scanf(" %[^\n]",curso1);
        scanf(" %[^\n]",curso2);
        scanf(" %[^\n]",curso3);
        scanf("%d %d %d",&m1,&m2,&m3);

        depto[i] = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
    }

     OrdenaDepartamentosPorMedia(depto,n);

    for(int i = 0;i<n;i++)
    {
        ImprimeAtributosDepartamento(depto[i]);
    }


    return 0;
}