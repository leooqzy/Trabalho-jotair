#include <stdio.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[50];
    float n1, n2, n3;
    float media;
} AlunoNota;

void preencherAluno(AlunoNota *a) {
    printf("\nMatricula: ");
    scanf("%d", &a->matricula);

    printf("Nome: ");
    scanf(" %[^\n]", a->nome);

    printf("Nota 1: ");
    scanf("%f", &a->n1);

    printf("Nota 2: ");
    scanf("%f", &a->n2);

    printf("Nota 3: ");
    scanf("%f", &a->n3);
}

void mediaGeral(AlunoNota *a) {
    a->media = (a->n1 + a->n2 + a->n3) / 3;
}

int aprovado(AlunoNota a) {
    return a.media >= 6;
}

AlunoNota maiorPrimeiraProva(AlunoNota a[], int tam) {
    AlunoNota maior = a[0];

    for (int i = 1; i < tam; i++) {
        if (a[i].n1 > maior.n1) {
            maior = a[i];
        }
    }

    return maior;
}

void exibirAluno(AlunoNota a) {
    printf("\n--- Aluno ---\n");
    printf("Matricula: %d\n", a.matricula);
    printf("Nome: %s\n", a.nome);
    printf("Notas: %.2f, %.2f, %.2f\n", a.n1, a.n2, a.n3);
    printf("Media: %.2f\n", a.media);

    if (aprovado(a)) {
        printf("Status: Aprovado\n");
    } else {
        printf("Status: Reprovado\n");
    }
}

int main() {
    AlunoNota alunos[3];

    for (int i = 0; i < 3; i++) {
        printf("\nAluno %d:\n", i + 1);
        preencherAluno(&alunos[i]);
        mediaGeral(&alunos[i]);
    }

    printf("\nLista de Alunos\n");
    for (int i = 0; i < 3; i++) {
        exibirAluno(alunos[i]);
    }

    AlunoNota melhor = maiorPrimeiraProva(alunos, 3);

    printf("\n=== Maior Nota na N1 ===\n");
    printf("Aluno: %s\n", melhor.nome);
    printf("Nota 1: %.2f\n", melhor.n1);

    return 0;
}