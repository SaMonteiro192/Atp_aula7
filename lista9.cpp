#include <stdio.h>
#include <stdlib.h>

// 1
void somaMatrizes3x3(int A[3][3], int B[3][3], int resultado[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            resultado[i][j] = A[i][j] + B[i][j];
}

// 2
void transpostaMatriz3x3(int A[3][3], int transposta[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            transposta[j][i] = A[i][j];
}

// 3
int encontrarNumero(int A[3][3], int valor, int *linha, int *coluna) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (A[i][j] == valor) {
                *linha = i;
                *coluna = j;
                return 1;
            }
    return 0;
}

// 4
int somaDiagonalPrincipal(int A[3][3]) {
    int soma = 0;
    for (int i = 0; i < 3; i++)
        soma += A[i][i];
    return soma;
}

// 5
void produtoVetorial3x3(int A[3], int B[3], int resultado[3]) {
    resultado[0] = A[1]*B[2] - A[2]*B[1];
    resultado[1] = A[2]*B[0] - A[0]*B[2];
    resultado[2] = A[0]*B[1] - A[1]*B[0];
}

// 6
int** alocarMatriz(int linhas, int colunas) {
    int **matriz = malloc(linhas * sizeof(int*));
    for (int i = 0; i < linhas; i++)
        matriz[i] = malloc(colunas * sizeof(int));
    return matriz;
}

// 7
void liberarMatriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++)
        free(matriz[i]);
    free(matriz);
}

// 8
void preencherMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
}

// 9
void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

// 10
void produtoVetorialMatrizesDinamicas(int **A, int **B, int **resultado) {
    for (int i = 0; i < 3; i++)
        produtoVetorial3x3(A[i], B[i], resultado[i]);
}

int main() {
    int linhas = 3, colunas = 3;

    int **A = alocarMatriz(linhas, colunas);
    int **B = alocarMatriz(linhas, colunas);
    int **resultado = alocarMatriz(linhas, colunas);

    printf("Preencha a matriz A:\n");
    preencherMatriz(A, linhas, colunas);
    printf("Preencha a matriz B:\n");
    preencherMatriz(B, linhas, colunas);

    produtoVetorialMatrizesDinamicas(A, B, resultado);

    printf("Resultado do produto vetorial:\n");
    imprimirMatriz(resultado, linhas, colunas);

    liberarMatriz(A, linhas);
    liberarMatriz(B, linhas);
    liberarMatriz(resultado, linhas);

    return 0;
}
