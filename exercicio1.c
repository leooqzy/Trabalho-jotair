#include <stdio.h>
#include <string.h>

typedef struct {
    int hora;
    int minuto;
    int segundo;
} Horario;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    Data data;
    Horario horario;
    char descricao[100];
} Compromisso;

Compromisso criaCompromisso(Data data, Horario horario, char descricao[]) {
    Compromisso c;
    c.data = data;
    c.horario = horario;
    strcpy(c.descricao, descricao);
    return c;
}

void imprimeCompromisso(Compromisso *c) {
    printf("\nCompromisso\n");
    printf("Descricao: %s\n", c->descricao);
    printf("Data: %02d/%02d/%04d\n", c->data.dia, c->data.mes, c->data.ano);
    printf("Horario: %02d:%02d:%02d\n", c->horario.hora, c->horario.minuto, c->horario.segundo);
}

void avancarSegundo(Compromisso *c) {
    c->horario.segundo++;

    if (c->horario.segundo >= 60) {
        c->horario.segundo = 0;
        c->horario.minuto++;
    }

    if (c->horario.minuto >= 60) {
        c->horario.minuto = 0;
        c->horario.hora++;
    }

    if (c->horario.hora >= 24) {
        c->horario.hora = 0;
        c->data.dia++;
    }
}

int main() {
    Data d;
    Horario h;
    char descricao[100];

    printf("Digite a descricao: ");
    scanf(" %[^\n]", descricao);

    printf("Digite a data (dia mes ano): ");
    scanf("%d %d %d", &d.dia, &d.mes, &d.ano);

    printf("Digite o horario (hora minuto segundo): ");
    scanf("%d %d %d", &h.hora, &h.minuto, &h.segundo);

    Compromisso c = criaCompromisso(d, h, descricao);

    printf("\nAntes da virada:\n");
    imprimeCompromisso(&c);

    avancarSegundo(&c);

    printf("\nDepois da virada:\n");
    imprimeCompromisso(&c);

    return 0;
}