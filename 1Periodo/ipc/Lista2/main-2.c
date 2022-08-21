// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int mat[10][3];
    int n_alunos1 = 0;
    int n_alunos2 = 0;
    int n_alunos3 = 0;
    int qntmaior = 0;
    int maior;

    printf("Informe as notas dos 10 alunos em cada uma das 3 provas: \n");
    for (int i = 0; i < 10; i++) {
        printf("Aluno: %d\n", i + 1);
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (mat[i][0] > mat[i][1] && mat[i][1] > mat[i][2]) {
            n_alunos1++;
        } else if (mat[i][1] > mat[i][0] && mat[i][0] > mat[i][2]) {
            n_alunos2++;
        } else if (mat [i][2] > mat[i][1] && mat[i][1] > mat[i][0]) {
            n_alunos3++;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            if (i && j == 0) {
                maior = mat[i][j];
            }
            if (mat[i][j] > maior) {
                maior = mat[i][j];
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            if (mat[i][j] == maior) {
                qntmaior++;
            }
        }
    }

    printf("A quantidade de alunos que tiveram a maior nota na prova 1 é: %d\n", n_alunos1);
    printf("A quantidade de alunos que tiveram a maior nota na prova 2 eh: %d\n", n_alunos2);
    printf("A quantidade de alunos que tiveram a maior nota na prova 3 eh: %d\n", n_alunos3);
    printf("A maior nota entre as tres provas entre os alunos foi: %d\n", maior);
    printf("A quantidade de alunos que tiraram a maior nota foi: %d\n", qntmaior);

    return 0;
}