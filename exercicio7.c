#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    int tempoPreparoMinutos;
    int porcoes;
} Receita;

void preencheReceita(Receita *r) {
    printf("Digite o nome da receita: ");
    scanf(" %[^\n]", r->nome);

    printf("Digite o tempo de preparo (minutos): ");
    scanf("%d", &r->tempoPreparoMinutos);

    printf("Digite o numero de porcoes: ");
    scanf("%d", &r->porcoes);
}

void imprimeReceita(Receita r) {
    printf("\nReceita\n");
    printf("Nome: %s\n", r.nome);
    printf("Tempo: %d minutos\n", r.tempoPreparoMinutos);
    printf("Porcoes: %d\n", r.porcoes);
}

void ajustaPorcoes(Receita *r, int novoNumPorcoes) {
    r->porcoes = novoNumPorcoes;
}

int main() {
    Receita r;
    int novasPorcoes;

    preencheReceita(&r);

    printf("\nAntes da alteracao:\n");
    imprimeReceita(r);

    printf("\nDigite o novo numero de porcoes: ");
    scanf("%d", &novasPorcoes);

    ajustaPorcoes(&r, novasPorcoes);

    printf("\nDepois da alteracao:\n");
    imprimeReceita(r);

    return 0;
}