#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mat[10][3];
    int n_alunos1 = 0, n_alunos2 = 0, n_alunos3 = 0;

    for (int i = 0; i < 10; i++) {
        printf("Informe as notas do aluno %d: \n", i + 1);
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (mat[i][0] > mat[i][1] && mat[i][1] > mat[i][2]) {
            n_alunos1++;
        }
        if (mat[i][1] > mat[i][0] && mat[i][0] > mat[i][2]) {
            n_alunos2++;
        }
        if (mat[i][2] > mat[i][1] && mat[i][1] > mat[i][0]) {
            n_alunos3++;
        }
    }

    printf("A quantidade de alunos que tiveram a maior nota na prova 1 eh: %d\n", n_alunos1);
    printf("A quantidade de alunos que tiveram a maior nota na prova 2 eh: %d\n", n_alunos2);
    printf("A quantidade de alunos que tiveram a maior nota na prova 3 eh: %d\n", n_alunos3);

    return 0;
}