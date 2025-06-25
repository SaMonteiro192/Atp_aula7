
1)#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool eh_primo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Use o programa passando dois números como argumentos.\n");
        return 1;
    }

    int inicio = atoi(argv[1]);
    int fim = atoi(argv[2]);

    printf("Números primos entre %d e %d:\n", inicio, fim);
    for (int i = inicio; i <= fim; i++) {
        if (eh_primo(i)) {
            printf("%d\n", i);
        }
    }getchar();
    return 0;
}

2)#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double arredondar(double valor, int casas) {
    double multiplicador = pow(10, casas);
    return round(valor * multiplicador) / multiplicador;
}

int main() {
    double valor = 3.14159;
    printf("Valor arredondado (2 casas): %.2f\n", arredondar(valor, 2));
    printf("Valor arredondado (0 casas): %.0f\n", arredondar(valor, 0));
    getchar();
    return 0;
}

3)#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gerar_bingo() {
    int bingo[5][5] = {0};
    int i, j, numero;

    srand(time(NULL));

 
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {  // Posição central "FREE"
                bingo[i][j] = -1;
            } else {
                switch(i) {
                    case 0: numero = rand() % 15 + 1; break;  // Coluna B
                    case 1: numero = rand() % 15 + 16; break; // Coluna I
                    case 2: numero = rand() % 15 + 31; break; // Coluna N
                    case 3: numero = rand() % 15 + 46; break; // Coluna G
                    case 4: numero = rand() % 15 + 61; break; // Coluna O
                }
                bingo[i][j] = numero;
            }
        }
    }

  
    FILE *arquivo = fopen("cartela_bingo.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (bingo[i][j] == -1)
                fprintf(arquivo, "FREE");
            else
                fprintf(arquivo, "%d", bingo[i][j]);

            if (j < 4)
                fprintf(arquivo, ",");
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
    printf("Cartela de Bingo gerada em 'cartela_bingo.csv'.\n");
}

int main() {
    gerar_bingo();
    return 0;
}

4)#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void somar_matrizes(int m1[MAX][MAX], int m2[MAX][MAX], int resultado[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

int main() {
    FILE *arquivo = fopen("matriz.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int n;
    fscanf(arquivo, "%d", &n);
    int m1[MAX][MAX], m2[MAX][MAX], resultado[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(arquivo, "%d", &m1[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(arquivo, "%d", &m2[i][j]);
        }
    }

    fclose(arquivo);

    somar_matrizes(m1, m2, resultado, n);

    printf("Resultado da soma das matrizes:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }
    getchar();
    return 0;
}

5)#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 100
#define MAX_NOME 50

void ler_menu(const char *arquivo, char menu[MAX_ITENS][MAX_NOME], float precos[MAX_ITENS], int *quantidade) {
    FILE *f = fopen(arquivo, "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo de menu.\n");
        return;
    }

    fscanf(f, "%d", quantidade); 
    fgetc(f); 

    for (int i = 0; i < *quantidade; i++) {
        fgets(menu[i], MAX_NOME, f);
        menu[i][strcspn(menu[i], "\n")] = 0; 
        fscanf(f, "%f", &precos[i]);
        fgetc(f);
    }

    fclose(f);
}

void gerar_boleto(const char *arquivo, char menu[MAX_ITENS][MAX_NOME], float precos[MAX_ITENS], int quantidade) {
    FILE *f = fopen(arquivo, "w");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo de boleto.\n");
        return;
    }

    float total = 0.0;
    int quantidades[MAX_ITENS];

    printf("Informe a quantidade de itens a ser comprada:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d. %s - R$ %.2f\n", i + 1, menu[i], precos[i]);
        printf("Quantidade para o item %d: ", i + 1);
        scanf("%d", &quantidades[i]);
        total += precos[i] * quantidades[i];
    }

    fprintf(f, "Boleto de Pedido:\n");
    fprintf(f, "================================\n");

    for (int i = 0; i < quantidade; i++) {
        fprintf(f, "%s x %d - R$ %.2f\n", menu[i], quantidades[i], precos[i] * quantidades[i]);
    }

    fprintf(f, "--------------------------------\n");
    fprintf(f, "Total: R$ %.2f\n", total);
    fclose(f);

    printf("Boleto gerado em 'boleto.txt'.\n");
}

int main() {
    char menu[MAX_ITENS][MAX_NOME];
    float precos[MAX_ITENS];
    int quantidade;

    ler_menu("menu.txt", menu, precos, &quantidade);
    gerar_boleto("boleto.txt", menu, precos, quantidade);
    getchar();
    return 0;
}


