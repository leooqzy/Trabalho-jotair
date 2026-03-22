#include <stdio.h>
#include <string.h>

typedef struct {
    char marca[50];
    char modelo[50];
    int ano;
    float preco;
} Veiculo;

void preencheVeiculo(Veiculo *v) {
    printf("Digite a marca: ");
    scanf(" %[^\n]", v->marca);

    printf("Digite o modelo: ");
    scanf(" %[^\n]", v->modelo);

    printf("Digite o ano: ");
    scanf("%d", &v->ano);

    printf("Digite o preco: ");
    scanf("%f", &v->preco);
}

void atualizaPreco(Veiculo *v, float novoPreco) {
    v->preco = novoPreco;
}

void exibeVeiculo(Veiculo v) {
    printf("\n--- Veiculo ---\n");
    printf("Marca: %s\n", v.marca);
    printf("Modelo: %s\n", v.modelo);
    printf("Ano: %d\n", v.ano);
    printf("Preco: %.2f\n", v.preco);
}

int main() {
    Veiculo v;
    float novoPreco;

    preencheVeiculo(&v);

    printf("\nAntes da atualizacao:\n");
    exibeVeiculo(v);

    printf("\nDigite o novo preco: ");
    scanf("%f", &novoPreco);

    atualizaPreco(&v, novoPreco);

    printf("\nDepois da atualizacao:\n");
    exibeVeiculo(v);

    return 0;
}