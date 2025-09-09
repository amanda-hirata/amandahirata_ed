#include <stdio.h>

int main () {
    char caractere;
    int inteiro;
    float pontoFlutuante;
    double duplo;
    short int inteiroPequeno;
    long int intLongo;

    caractere = 'A'; 
    printf("\nO tamanho da variável caractere é %c", caractere);
    printf("\nO tamanho da variável inteiro é %d", caractere);
    printf("\n");

    printf("\nO tamanho da variável inteiro é \t%ld", sizeof(inteiro));
    printf("\nO tamanho da variável caractere é \t%ld", sizeof(caractere));
    printf("\n");
}