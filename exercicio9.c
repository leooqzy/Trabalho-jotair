#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[100];
    char autor[50];
    int ano;
    int exemplares;
} Livro;

Livro criaLivro(char titulo[], char autor[], int ano, int exemplares) {
    Livro l;
    strcpy(l.titulo, titulo);
    strcpy(l.autor, autor);
    l.ano = ano;
    l.exemplares = exemplares;
    return l;
}

int emprestaLivro(Livro *l) {
    if (l->exemplares > 0) {
        l->exemplares--;
        return 1;
    }
    return 0;
}

void devolveLivro(Livro *l) {
    l->exemplares++;
}

void exibeLivro(Livro l) {
    printf("\nTitulo: %s", l.titulo);
    printf("\nAutor: %s", l.autor);
    printf("\nAno: %d", l.ano);
    printf("\nExemplares: %d\n", l.exemplares);
}

int main() {
    char titulo[100], autor[50];
    int ano, exemplares;

    printf("Titulo: ");
    scanf(" %[^\n]", titulo);

    printf("Autor: ");
    scanf(" %[^\n]", autor);

    printf("Ano: ");
    scanf("%d", &ano);

    printf("Quantidade de exemplares: ");
    scanf("%d", &exemplares);

    Livro l = criaLivro(titulo, autor, ano, exemplares);

    printf("\nAntes:\n");
    exibeLivro(l);

    if (emprestaLivro(&l))
        printf("\nLivro emprestado!\n");
    else
        printf("\nNao ha exemplares disponiveis!\n");

    exibeLivro(l);

    devolveLivro(&l);
    printf("\nDepois de devolver:\n");
    exibeLivro(l);

    return 0;
}