#include <stdio.h>
#include <math.h>

struct ponto {
    double x, y;
};

int main(void) {
    struct ponto p1, p2;
    double dx, dy, resultado;

    scanf("%lf %lf", &p1.x, &p1.y);
    scanf("%lf %lf", &p2.x, &p2.y);

    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    resultado = sqrt(dx * dx + dy * dy);

    printf("Distancia = %.2f\n", resultado);
    return 0;
}
