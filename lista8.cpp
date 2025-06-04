#include <stdio.h>
#include <stdlib.h>

//1
int main() {
    int n, i;
    printf("Digite o numero de elementos: ");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        vetor[i] = i + 1;
    }

    printf("Vetor: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);
    return 0;
}

//2
int main() {
    int n, i;
    printf("Quantos numeros você deseja armazenar? ");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Vetor armazenado: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);
    return 0;
}

//3
int main() {
    int *vetor = NULL;
    int valor, n = 0;

    while (1) {
        printf("Digite um numero (ou -1 para sair): ");
        scanf("%d", &valor);

        if (valor == -1)
            break;

        vetor = (int *)realloc(vetor, (n + 1) * sizeof(int));
        if (vetor == NULL) {
            printf("Erro ao realocar memoria.\n");
            return 1;
        }

        vetor[n] = valor;
        n++;
    }

    printf("Vetor armazenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);
    return 0;
}

//4
int *filtraPares(int *V, int n, int *novoTamanho) {
    int *S = NULL;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (V[i] % 2 == 0) {
            S = (int *)realloc(S, (count + 1) * sizeof(int));
            S[count++] = V[i];
        }
    }

    *novoTamanho = count;
    return S;
}

int main() {
    int n;
    printf("Quantos numeros no vetor? ");
    scanf("%d", &n);

    int *V = (int *)malloc(n * sizeof(int));
    if (V == NULL) return 1;

    for (int i = 0; i < n; i++) {
        printf("V[%d]: ", i);
        scanf("%d", &V[i]);
    }

    int novoTamanho;
    int *pares = filtraPares(V, n, &novoTamanho);

    printf("Vetor com apenas os pares: ");
    for (int i = 0; i < novoTamanho; i++) {
        printf("%d ", pares[i]);
    }

    free(V);
    free(pares);
    return 0;
}

//5
int main() {
    int *matriz = (int *)calloc(9, sizeof(int));

    if (matriz == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    printf("Matriz 3x3 com zeros:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i * 3 + j]); 
        }
        printf("\n");
    }

    free(matriz);
    return 0;
}
