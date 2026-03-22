#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Ponto2D;

Ponto2D criaPonto(float x, float y) {
    Ponto2D p;
    p.x = x;
    p.y = y;
    return p;
}

void movePonto(Ponto2D *p, float dx, float dy) {
    p->x += dx;
    p->y += dy;
}

float distanciaEntrePontos(Ponto2D p1, Ponto2D p2) {
    float dx = p2.x - p1.x;
    float dy = p2.y - p1.y;

    return sqrt(dx * dx + dy * dy);
}

void exibePonto(Ponto2D p) {
    printf("(%.2f, %.2f)\n", p.x, p.y);
}

int main() {
    float x1, y1, x2, y2;
    float dx, dy;

    printf("Digite o ponto 1 (x y): ");
    scanf("%f %f", &x1, &y1);

    printf("Digite o ponto 2 (x y): ");
    scanf("%f %f", &x2, &y2);

    Ponto2D p1 = criaPonto(x1, y1);
    Ponto2D p2 = criaPonto(x2, y2);

    printf("\nPonto 1: ");
    exibePonto(p1);

    printf("Ponto 2: ");
    exibePonto(p2);

    float dist = distanciaEntrePontos(p1, p2);
    printf("\nDistancia entre os pontos: %.2f\n", dist);

    printf("\nDigite quanto mover o ponto 1 (dx dy): ");
    scanf("%f %f", &dx, &dy);

    movePonto(&p1, dx, dy);

    printf("\nPonto 1 depois de mover: ");
    exibePonto(p1);

    return 0;
}











