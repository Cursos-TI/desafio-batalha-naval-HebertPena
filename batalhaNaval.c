#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
// declaração do tabuleiro 10x10
int tabuleiro[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,3,3,3,0,0,0,0,0,0},
    {0,0,0,0,0,0,3,0,0,0},
    {0,0,0,0,0,0,0,3,0,0},
    {0,0,0,0,0,0,0,0,3,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,3,0,0,0,0,0,3,0,0},
    {0,3,0,0,0,0,3,0,0,0},
    {0,3,0,0,0,3,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

// Loop aninhado para printar o tabuleiro no terminal com a posiçlão correta dos navios.
for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
        printf("%d", tabuleiro[i][j]);
    }  
    printf("\n");
}
printf("\n");

    return 0;
}
