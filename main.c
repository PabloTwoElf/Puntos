#include <stdio.h>
#include <math.h>
#include "funciones.h"

int main(int argc, char *argv[]) {
    float puntos[4][3] = {{0, 0, 0}, {3, 0, 0}, {0, 0, 3}, {1, 7, 1}};
    float a, b, c, d, e, f;

    float perimetro = calcularPerimetro(puntos, &a, &b, &c, &d, &e, &f);
    float area1 = calcularArea(a, b, c);
    float area2 = calcularArea(b, d, e);
    float area3 = calcularArea(a, e, f);
    float area4 = calcularArea(e, f, a);
    float areasuperficial = area1 + area2 + area3 + area4;

    float volumen = calcularVolumen(puntos);

    printf("El perimetro es: %.2f\n", perimetro);
    printf("El area superficial es: %.2f\n", areasuperficial);
    printf("El volumen es: %.2f\n", volumen);

    float areas[4] = {area1, area2, area3, area4};
    for (int i = 0; i < 4; i++) {
        printf("El área %d es: %.2f\n", i+1, areas[i]);
    }

    return 0;
}

float calcularPerimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f);
float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2);
float calcularArea(float a, float b, float c);
float calcularVolumen(float puntos[4][3]);



#include "funciones.h"
#include <math.h>

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2) {
    float distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
    return distancia;
}

float calcularPerimetro(float puntos[4][3], float *a, float *b, float *c, float *d, float *e, float *f) {
    *a = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *b = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *c = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *d = calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *e = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *f = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);

    float perimetro_total = *a + *b + *c + *d + *e + *f;
    return perimetro_total;
}

float calcularArea(float a, float b, float c) {
    float s = (a + b + c) / 2;
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}
float calcularVolumen(float puntos[4][3]) {
    float a, b, c, d, e, f;
    calcularPerimetro(puntos, &a, &b, &c, &d, &e, &f);

    float volumen = fabs((1.0 / 6.0) * (
        puntos[3][0] * (
            puntos[0][1] * puntos[1][2] - puntos[1][1] * puntos[0][2] -
            puntos[0][1] * puntos[2][2] + puntos[2][1] * puntos[0][2] +
            puntos[1][1] * puntos[2][2] - puntos[2][1] * puntos[1][2]
        ) + puntos[3][1] * (
            puntos[0][2] * puntos[1][0] - puntos[1][2] * puntos[0][0] -
            puntos[0][2] * puntos[2][0] + puntos[2][2] * puntos[0][0] +
            puntos[1][2] * puntos[2][0] - puntos[2][2] * puntos[1][0]
        ) + puntos[3][2] * (
            puntos[0][0] * puntos[1][1] - puntos[1][0] * puntos[0][1] -
            puntos[0][0] * puntos[2][1] + puntos[2][0] * puntos[0][1] +
            puntos[1][0] * puntos[2][1] - puntos[2][0] * puntos[1][1]
        )
    ));
    
    return volumen;
}

