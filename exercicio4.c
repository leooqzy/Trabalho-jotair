#include <stdio.h>

typedef struct {
    float x;
    float y;
    float z;
} Vetor3D;

Vetor3D somaVetores(Vetor3D a, Vetor3D b) {
    Vetor3D resultado;

    resultado.x = a.x + b.x;
    resultado.y = a.y + b.y;
    resultado.z = a.z + b.z;

    return resultado;
}

void acumulaNoPrimeiro(Vetor3D *a, Vetor3D b) {
    a->x = a->x + b.x;
    a->y = a->y + b.y;
    a->z = a->z + b.z;
}

void exibeVetor(Vetor3D v) {
    printf("(%.2f, %.2f, %.2f)\n", v.x, v.y, v.z);
}

int main() {
    Vetor3D v1, v2, soma;

    printf("Digite os valores do vetor 1 (x y z): ");
    scanf("%f %f %f", &v1.x, &v1.y, &v1.z);

    printf("Digite os valores do vetor 2 (x y z): ");
    scanf("%f %f %f", &v2.x, &v2.y, &v2.z);

    printf("\nVetor 1: ");
    exibeVetor(v1);

    printf("Vetor 2: ");
    exibeVetor(v2);

    soma = somaVetores(v1, v2);

    printf("\nResultado da somaVetores: ");
    exibeVetor(soma);

    printf("\nVetor 1 antes de acumular: ");
    exibeVetor(v1);

    acumulaNoPrimeiro(&v1, v2);

    printf("Vetor 1 depois de acumular vetor 2: ");
    exibeVetor(v1);

    return 0;
}