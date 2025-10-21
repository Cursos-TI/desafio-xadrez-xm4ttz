#include <stdio.h>

// =====================================================
// FUNÇÕES RECURSIVAS — Torre, Bispo, Rainha
// =====================================================

// Função recursiva para a Torre (movimento horizontal)
void moverTorre(int atual, int limite) {
    if (atual > limite) return; // condição de parada
    printf("Direita (%d)\n", atual);
    moverTorre(atual + 1, limite); // chamada recursiva
}

// Função recursiva para a Rainha (movimento horizontal)
void moverRainha(int atual, int limite) {
    if (atual > limite) return;
    printf("Esquerda (%d)\n", atual);
    moverRainha(atual + 1, limite);
}

// Função recursiva para o Bispo
// Aqui o movimento é diagonal: Cima + Direita
// Usamos loops aninhados dentro da recursão
void moverBispo(int linha, int maxLinha, int maxColuna) {
    if (linha > maxLinha) return;

    // Loop interno (horizontal)
    for (int coluna = 1; coluna <= maxColuna; coluna++) {
        printf("Cima, Direita (%d,%d)\n", linha, coluna);
    }

    moverBispo(linha + 1, maxLinha, maxColuna); // recursão vertical
}

// =====================================================
// MOVIMENTO COMPLEXO DO CAVALO (loops aninhados)
// =====================================================
void moverCavalo() {
    printf("\n=== Movimento do Cavalo ===\n");
    printf("Movimento em L: Duas casas para cima e uma para a direita\n");

    // Loops aninhados com múltiplas variáveis e controle de fluxo
    for (int i = 1, j = 0; i <= 2 || j <= 1; i++, j++) {
        // Movimento vertical (duas casas para cima)
        if (i <= 2) {
            printf("Cima (%d)\n", i);
            continue; // volta para o início do loop sem executar o resto
        }

        // Movimento horizontal (uma casa à direita)
        for (int k = 1; k <= 1; k++) {
            printf("Direita (%d)\n", k);
            break; // sai após uma casa
        }

        if (i > 2 && j > 1) break; // evita loop infinito
    }
}

// =====================================================
// PROGRAMA PRINCIPAL
// =====================================================
int main() {
    // Movimentos definidos diretamente no código
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

