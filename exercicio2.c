#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    char endereco[100];
} Pessoa;

void preenchePessoa(Pessoa *p) {
    printf("\nDigite o nome: ");
    scanf(" %[^\n]", p->nome);

    printf("Digite a idade: ");
    scanf("%d", &p->idade);

    printf("Digite o endereco: ");
    scanf(" %[^\n]", p->endereco);
}

void exibePessoa(Pessoa p) {
    printf("\n--- Pessoa ---\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Endereco: %s\n", p.endereco);
}

int main() {
    Pessoa pessoas[5];

    for (int i = 0; i < 5; i++) {
        printf("\nPessoa %d:\n", i + 1);
        preenchePessoa(&pessoas[i]);
    }

    printf("\n=== Lista de Pessoas ===\n");
    for (int i = 0; i < 5; i++) {
        exibePessoa(pessoas[i]);
    }

    return 0;
}