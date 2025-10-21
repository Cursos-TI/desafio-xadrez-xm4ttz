#include <stdio.h>

// =====================================================
// FUNÇÕES RECURSIVAS
// =====================================================

// Função recursiva da Torre (usa FOR)
void moverTorre(int atual, int limite) {
    if (atual > limite) return;

    // usa um pequeno for interno só para seguir o padrão da torre (for)
    for (int i = atual; i <= atual; i++) {
        printf("Direita (%d)\n", i);
    }

    moverTorre(atual + 1, limite); // chamada recursiva
}

// Função recursiva da Rainha (usa DO-WHILE)
void moverRainha(int atual, int limite) {
    if (atual > limite) return;

    int contador = atual;
    do {
        printf("Esquerda (%d)\n", contador);
        break; // evita loop infinito (executa uma vez por chamada)
    } while (contador <= limite);

    moverRainha(atual + 1, limite);
}

// Função recursiva do Bispo (usa WHILE + loops aninhados)
void moverBispo(int linha, int maxLinha, int maxColuna) {
    if (linha > maxLinha) return;

    int col = 1;
    while (col <= maxColuna) {
        printf("Cima, Direita (%d,%d)\n", linha, col);
        col++;
    }

    moverBispo(linha + 1, maxLinha, maxColuna);
}

// =====================================================
// MOVIMENTO COMPLEXO DO CAVALO (loops aninhados)
// =====================================================
void moverCavalo() {
    printf("\n=== Movimento do Cavalo ===\n");
    printf("Movimento em L: Duas casas para cima e uma para a direita\n");

    // Movimento em "L": 2 pra cima + 1 pra direita
    for (int i = 1; i <= 2; i++) {
        printf("Cima (%d)\n", i);

        if (i == 2) {
            int j = 1;
            while (j <= 1) {
                printf("Direita (%d)\n", j);
                break;
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
