#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE 5

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
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int verificaSobreposicao(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    for (int i = 0; i < NAVIO; i++) {
        if (direcao == 'H' && (coluna + i >= TAMANHO || tabuleiro[linha][coluna + i] != 0)) return 0;
        if (direcao == 'V' && (linha + i >= TAMANHO || tabuleiro[linha + i][coluna] != 0)) return 0;
        if (direcao == 'D' && (linha + i >= TAMANHO || coluna + i >= TAMANHO || tabuleiro[linha + i][coluna + i] != 0)) return 0;
        if (direcao == 'A' && (linha + i >= TAMANHO || coluna - i < 0 || tabuleiro[linha + i][coluna - i] != 0)) return 0;
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char direcao) {
    if (direcao == 'H') {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else if (direcao == 'V') {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    } else if (direcao == 'D') {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha + i][coluna + i] = NAVIO;
        }
    } else if (direcao == 'A') {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha + i][coluna - i] = NAVIO;
        }
    }
}

void aplicarHabilidade(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, char tipo) {
    if (tipo == 'C') {
        for (int i = -2; i <= 2; i++) {
            if (linha + i >= 0 && linha + i < TAMANHO) tabuleiro[linha + i][coluna] = HABILIDADE;
            if (coluna + i >= 0 && coluna + i < TAMANHO) tabuleiro[linha][coluna + i] = HABILIDADE;
        }
    } else if (tipo == 'O') {
        for (int i = -2; i <= 2; i++) {
            for (int j = -2 + abs(i); j <= 2 - abs(i); j++) {
                if (linha + i >= 0 && linha + i < TAMANHO && coluna + j >= 0 && coluna + j < TAMANHO)
                    tabuleiro[linha + i][coluna + j] = HABILIDADE;
            }
        }
    } else if (tipo == 'N') {
        for (int i = 0; i < 3; i++) {
            for (int j = -i; j <= i; j++) {
                if (linha + i < TAMANHO && coluna + j >= 0 && coluna + j < TAMANHO)
                    tabuleiro[linha + i][coluna + j] = HABILIDADE;
            }
        }
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    int linhaH = 2, colunaH = 3;
    int linhaV = 5, colunaV = 6;
    int linhaD = 1, colunaD = 1;
    int linhaA = 7, colunaA = 8;

    if (verificaSobreposicao(tabuleiro, linhaH, colunaH, 'H'))
        posicionarNavio(tabuleiro, linhaH, colunaH, 'H');
    
    if (verificaSobreposicao(tabuleiro, linhaV, colunaV, 'V'))
        posicionarNavio(tabuleiro, linhaV, colunaV, 'V');
    
    if (verificaSobreposicao(tabuleiro, linhaD, colunaD, 'D'))
        posicionarNavio(tabuleiro, linhaD, colunaD, 'D');
    
    if (verificaSobreposicao(tabuleiro, linhaA, colunaA, 'A'))
        posicionarNavio(tabuleiro, linhaA, colunaA, 'A');

    aplicarHabilidade(tabuleiro, 4, 4, 'C');
    aplicarHabilidade(tabuleiro, 6, 6, 'O');
    aplicarHabilidade(tabuleiro, 1, 5, 'N');

    exibirTabuleiro(tabuleiro);

    return 0;
}
