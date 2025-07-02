
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include < string.h>

1)
typedef struct {
    float nota_exercicios;
    float nota_prova1;
    float nota_prova2;  
} Aluno;


float calcula_media_final(Aluno aluno) {
    float peso_exercicios = 0.2f;
    float peso_prova1 = 0.8f * (4.0f / 10.0f);
    float peso_prova2 = 0.8f * (6.0f / 10.0f);

    float media = (aluno.nota_exercicios * peso_exercicios) +
                  (aluno.nota_prova1 * peso_prova1) +
                  (aluno.nota_prova2 * peso_prova2);

    return media;
}
2) Fiz como se fosse continuação da 1

typedef struct {
    char nome[50];
    Aluno dados;
} RegistroAluno;

typedef struct {
    RegistroAluno alunos[MAX_ALUNOS];
    int quantidade;
} ListaAlunos;

void calcular_e_imprimir_medias(ListaAlunos lista) {
    for (int i = 0; i < lista.quantidade; i++) {
        float media = calcula_media_final(lista.alunos[i].dados);
        printf("Aluno: %s\n", lista.alunos[i].nome);
        printf("Média final: %.2f\n\n", media);
    }
}

// 3)
typedef struct No {
    int valor;
    struct No* direita;
    struct No* abaixo;
} No;

typedef struct {
    int linhas;
    int colunas;
    No* inicio;
} Matriz;

// 4)

typedef struct {
    int valor;
} Decimal;

Decimal somar(Decimal d1, Decimal d2) {
    Decimal resultado;
    resultado.valor = d1.valor + d2.valor;
    return resultado;
}

Decimal subtrair(Decimal d1, Decimal d2) {
    Decimal resultado;
    resultado.valor = d1.valor - d2.valor;
    return resultado;
}

void imprimir(Decimal d) {
    printf("%d.%04d\n", d.valor / 10000, d.valor % 10000);
}


//5)

#define MAX_ITENS 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    float preco;
} Produto;

typedef struct {
    Produto itens[MAX_ITENS];
    int quantidade;
} Menu;

void inicializar_produto(Produto *produto, const char *nome, float preco) {
    strncpy(produto->nome, nome, MAX_NOME);
    produto->preco = preco;
}

void ler_menu(const char *arquivo, Menu *menu) {
    FILE *f = fopen(arquivo, "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo de menu.\n");
        return;
    }

    fscanf(f, "%d", &menu->quantidade); 
    fgetc(f);

    for (int i = 0; i < menu->quantidade; i++) {
        char nome[MAX_NOME];
        float preco;
        
        fgets(nome, MAX_NOME, f); 
        nome[strcspn(nome, "\n")] = 0;

        fscanf(f, "%f", &preco);
        fgetc(f);
        
        inicializar_produto(&menu->itens[i], nome, preco);
    }

    fclose(f);
}

void gerar_boleto(const char *arquivo, Menu *menu) {
    FILE *f = fopen(arquivo, "w");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo de boleto.\n");
        return;
    }

    float total = 0.0;
    int quantidades[MAX_ITENS];

    printf("Informe a quantidade de itens a ser comprada:\n");
    for (int i = 0; i < menu->quantidade; i++) {
        printf("%d. %s - R$ %.2f\n", i + 1, menu->itens[i].nome, menu->itens[i].preco);
        printf("Quantidade para o item %d: ", i + 1);
        scanf("%d", &quantidades[i]);
        total += menu->itens[i].preco * quantidades[i];
    }

    fprintf(f, "Boleto de Pedido:\n");
    fprintf(f, "================================\n");

    for (int i = 0; i < menu->quantidade; i++) {
        fprintf(f, "%s x %d - R$ %.2f\n", menu->itens[i].nome, quantidades[i], menu->itens[i].preco * quantidades[i]);
    }

    fprintf(f, "--------------------------------\n");
    fprintf(f, "Total: R$ %.2f\n", total);
    fclose(f);

    printf("Boleto gerado em 'boleto.txt'.\n");
}

int main() {
    Menu menu;
    
    ler_menu("menu.txt", &menu);
    gerar_boleto("boleto.txt", &menu);

    return 0;
}