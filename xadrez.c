#include <stdio.h>

// =====================================================
// FUNÇÕES RECURSIVAS — Torre, Bispo, Rainha
// =====================================================

// Função recursiva para a Torre (movimento horizontal)
void moverTorre(int atual, int limite) {
    if (atual > limite) return;
    printf("Direita (%d)\n", atual);
    moverTorre(atual + 1, limite);
}

// Função recursiva para a Rainha (movimento horizontal)
void moverRainha(int atual, int limite) {
    if (atual > limite) return;
    printf("Esquerda (%d)\n", atual);
    moverRainha(atual + 1, limite);
}

// Função recursiva para o Bispo (movimento diagonal)
void moverBispo(int linha, int maxLinha, int maxColuna) {
    if (linha > maxLinha) return;

    // Loop interno horizontal
    for (int coluna = 1; coluna <= maxColuna; coluna++) {
        printf("Cima, Direita (%d,%d)\n", linha, coluna);
    }

    // Chamada recursiva vertical
    moverBispo(linha + 1, maxLinha, maxColuna);
}

// =====================================================
// MOVIMENTO COMPLEXO DO CAVALO (loops aninhados)
// =====================================================
void moverCavalo() {
    printf("\n=== Movimento do Cavalo ===\n");
    printf("Movimento em L: Duas casas para cima e uma para a direita\n");

    // i controla o movimento vertical, j o horizontal
    for (int i = 1; i <= 2; i++) {
        printf("Cima (%d)\n", i);

        // Quando termina o segundo movimento vertical, faz o movimento horizontal
        if (i == 2) {
            for (int j = 1; j <= 1; j++) {
                if (j == 1) {
                    printf("Direita (%d)\n", j);
                    break; // apenas uma casa para a direita
                }
            }
        }
    }
}

// =====================================================
// PROGRAMA PRINCIPAL
// =====================================================
int main() {
    int casasTorre = 5;
    int casasRainha = 8;
    int linhasBispo = 3;
    int colunasBispo = 3;

    printf("=== Movimento da Torre ===\n");
    moverTorre(1, casasTorre);

    printf("\n=== Movimento do Bispo ===\n");
    moverBispo(1, linhasBispo, colunasBispo);

    printf("\n=== Movimento da Rainha ===\n");
    moverRainha(1, casasRainha);

    moverCavalo();

    printf("\n=== Fim da Simulação ===\n");
    return 0;
}
