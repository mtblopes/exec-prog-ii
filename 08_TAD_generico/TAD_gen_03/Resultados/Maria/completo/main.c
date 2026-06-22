#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "vector.h"
#include "relatorio.h"

int main ()
{
    int n;
    scanf("%d\n", &n);

    Vector *v = VectorConstruct();
    
    for(int i = 0; i < n; i++)
    {
        tAluno *aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(v, aluno);
    }

    ImprimeRelatorio(v);
    VectorDestroy(v, DestroiAluno);

    return 0;
}