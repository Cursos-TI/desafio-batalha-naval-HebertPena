#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
int tabuleiro[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,3,3,3,0,0,0,0,0,0},
    {0,0,0,0,3,0,0,0,0,0},
    {0,0,0,0,3,0,0,0,0,0},
    {0,0,0,0,3,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
        printf("%d", tabuleiro[i][j]);
    }  
    printf("\n");
}

printf("\n");

    return 0;
}
