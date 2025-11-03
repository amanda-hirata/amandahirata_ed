#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Ordena o vetor em ordem crescente
void ordenar(float v[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                float temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

// Calcula a média
float calcularMedia(float v[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma / n;
}

// Calcula a mediana (com vetor já ordenado)
float calcularMediana(float v[], int n) {
    if (n % 2 == 0) {
        return (v[n/2 - 1] + v[n/2]) / 2.0;
    } else {
        return v[n/2];
    }
}

// Calcula o desvio padrão populacional
float calcularDP(float v[], int n, float media) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += (v[i] - media) * (v[i] - media);
    }
    return sqrt(soma / n);
}

int main() {
    int n;
    float *valores;

    printf("Quantos numeros na sua serie (N): ");
    scanf("%d", &n);

    valores = malloc(n * sizeof(float));
    if (valores == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }

    printf("Entre com os numeros:\n");
    for (int i = 0; i < n; i++) {
        printf("> ");
        scanf("%f", &valores[i]);
    }

    ordenar(valores, n);

    float media = calcularMedia(valores, n);
    float mediana = calcularMediana(valores, n);
    float minimo = valores[0];
    float maximo = valores[n-1];
    float dp = calcularDP(valores, n, media);

    printf("Valor minimo: %.2f\n", minimo);
    printf("Valor maximo: %.2f\n", maximo);
    printf("Media: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Desvio padrao: %.13f\n", dp);

    free(valores);
    return 0;
}

