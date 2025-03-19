#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int verificaSobreposicao(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    for (int i = 0; i < NAVIO; i++) {
        if (direcao == 'H' && tabuleiro[linha][coluna + i] != 0) return 0;
        if (direcao == 'V' && tabuleiro[linha + i][coluna] != 0) return 0;
        if (direcao == 'D' && tabuleiro[linha + i][coluna + i] != 0) return 0;
        if (direcao == 'A' && tabuleiro[linha + i][coluna - i] != 0) return 0;
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    if (direcao == 'H') { // Horizontal
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (direcao == 'V') { // Vertical
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    } else if (direcao == 'D') { // Diagonal principal
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha + i][coluna + i] = NAVIO;
        }
    } else if (direcao == 'A') { // Diagonal secundária
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha + i][coluna - i] = NAVIO;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas e direções pré-definidas para os navios
    int linhaH = 2, colunaH = 3;
    int linhaV = 5, colunaV = 6;
    int linhaD = 1, colunaD = 1;
    int linhaA = 7, colunaA = 8;

    // Posicionar os navios se não houver sobreposição
    if (verificaSobreposicao(tabuleiro, linhaH, colunaH, 'H'))
        posicionarNavio(tabuleiro, linhaH, colunaH, 'H');
    
    if (verificaSobreposicao(tabuleiro, linhaV, colunaV, 'V'))
        posicionarNavio(tabuleiro, linhaV, colunaV, 'V');
    
    if (verificaSobreposicao(tabuleiro, linhaD, colunaD, 'D'))
        posicionarNavio(tabuleiro, linhaD, colunaD, 'D');
    
    if (verificaSobreposicao(tabuleiro, linhaA, colunaA, 'A'))
        posicionarNavio(tabuleiro, linhaA, colunaA, 'A');

    // Exibir tabuleiro com navios
    exibirTabuleiro(tabuleiro);

    return 0;
}
