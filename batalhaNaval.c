#include <stdio.h>
#include <stdlib.h> // Biblioteca para o uso do abd(retorna sempre o positivo de um número)

#define BOARD_SIZE 10 // constante do tabuleiro

// declaração das funções
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]);
void placeHorizontalShip(int board[BOARD_SIZE][BOARD_SIZE], int x, int y, int lenght);
void placeVerticalShip(int board[BOARD_SIZE][BOARD_SIZE], int x, int y, int lenght);
void placeDiagonalShip(int board[BOARD_SIZE][BOARD_SIZE], int x, int y, int lenght, int direction);
void placeShips(void);
void coneAbility(int board[BOARD_SIZE][BOARD_SIZE], int x, int y);
void crossAbility(int board[BOARD_SIZE][BOARD_SIZE], int x, int y);
void octahedroAbility(int board[BOARD_SIZE][BOARD_SIZE], int x, int y);



int main() {

    // Criação de um tabuleiro vazio e colocação dos navios
    // 3 outros tabuleiros vazios para apresentação das 3 habilidades
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int boardCone[BOARD_SIZE][BOARD_SIZE] = {0};
    int boardCross[BOARD_SIZE][BOARD_SIZE] = {0};
    int boardOctahedro[BOARD_SIZE][BOARD_SIZE] = {0};

    int menu;

    printf("Tabuleiro Limpo\n");
    printBoard(board);

    placeShips(); 

    coneAbility(boardCone, 0, 4);
    printf("\n");
    printf("Cone\n");
    printBoard(boardCone);

    crossAbility(boardCross, 5, 5);
    printf("\n");
    printf("Cruz\n");
    printBoard(boardCross);

    octahedroAbility(boardOctahedro, 4, 4);
    printf("\n");
    printf("Octaedro\n");
    printBoard(boardOctahedro);


}

// print do tabuleiro
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++){  
        for (int j = 0; j < BOARD_SIZE; j++){
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
}

// posiciona um navio horizontalmente no tabuleiro, os argumentos são o tamanho do navio, cordenadas e tamanho.
void placeHorizontalShip(int board[BOARD_SIZE][BOARD_SIZE], int x, int y, int lenght) {
    for (int i =0; i < lenght; i++){
        if (y + i < BOARD_SIZE) {
            board[x][y + i] = 3;
        }
    }
}

// posiciona um navio verticalmente no tabuleiro, os argumentos são o tamanho do navio, cordenadas e tamanho.
void placeVerticalShip(int board[BOARD_SIZE][BOARD_SIZE], int x, int y, int lenght) {
    for (int i =0; i < lenght; i++){
        if (y + i < BOARD_SIZE) {
            board[x + i][y] = 3;
        }
    }
}

// posiciona um navio na diagonal no tabuleiro, os argumentos são o tamanho do navio, cordenadas, tamanho e direção, sendo +1 crescente \ e -1 decrescente.
void placeDiagonalShip(int board[BOARD_SIZE][BOARD_SIZE], int x, int y, int lenght, int direction) {
    for (int i = 0; i < lenght; i++){
        if (x + i < BOARD_SIZE && y + direction * i >= 0 && y + direction * i < BOARD_SIZE){
            board[x + i][y + direction * i] = 3;
        }
    }
}

// Chama todas as funções para posicionar os navios, deixando o codigo no main() mais limpo.
void placeShips(void){

    int board[BOARD_SIZE][BOARD_SIZE] = {0};

    placeHorizontalShip(board, 1, 1, 5);
    placeVerticalShip(board, 7, 7, 3);
    placeDiagonalShip(board, 3, 3, 3, 1);
    placeDiagonalShip(board, 6, 6, 3, -1);

    printf("\n Tabuleiro com os navios posicionados. \n");

    printBoard(board);
}

// Verifica se uma posição no tabuleiro é valida para aplicar uma habilidade
int validatePosition(int x, int y){
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

// Habilidade de cone. X representa as colunas e Y as linhas. As linhas começam negativas para que possa imprimir para os dois lados da linha e o cone crescer
// X começa no 0, pois se começar negativo ele acaba formando uma ampulheta.
void coneAbility(int board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    for (int i = 0; i <= 4; i++) {
        for (int j = -4; j <= 4; j++){
            if (abs(i) >= abs(j) && validatePosition(x + i, y + j)) {
                board[x + i][y + j] = 1;
            }
        }
    }
}

// Habilidade da cruz. O i representa tanto a linha quanto coluna, o X e Y do argumento é onde a cruz se inicia e se extende verticalmente e horizontalmente.
void crossAbility(int board[BOARD_SIZE][BOARD_SIZE], int x, int y){
    for (int i = -3; i <= 3; i++){
        if(validatePosition(x + i, y)){
            board[x + i][y] = 1;
        }
        if (validatePosition(x, y + i)){
            board[x][y + i] = 1;
        }
    }
}

// Habilidade em octaedro. É similar a função do cone mas inverso e com o X também começando negativo.
void octahedroAbility(int board[BOARD_SIZE][BOARD_SIZE], int x, int y){
    for (int i = -3; i <= 3; i++){
        for (int j = -3; j <= 3; j++){
            if (abs(i) + abs(j) <= 3 && validatePosition(x + i, y + j)){
                board[x + i][y + j] = 1;
            }
        }
    }
}
