#include <stdio.h>
#include <stdlib.h>

//1)
int main() {
    char nome[100];
    printf("Digite o nome:\n");
    scanf("%c", nome);
    printf("Seu nome começa com a letra %c", nome[0]);
    getchar();
    return 0;
}

//2)
int main(){
    int A[5], B[5], contador;
    printf("Digite os 5 valores de A: \n");
    for(contador = 0; contador < 5; contador++){
        scanf("%d", &A[contador]);
    } printf("Agora digite os 5 valores de B: \n");
        for(contador = 0; contador < 5; contador++){
        scanf("%d", &B[contador]);
    }
    printf("Esses sao os valores intercalados: \n");
    for(contador = 0; contador < 5; contador++){
        printf("%d ", A[contador]);
        printf("%d ", B[contador]);
    }
    getchar();
    return 0;
}

//3)
int verifica(int A[], int T, int x) {
    for (int i = 0; i < T; i++) {
        if (A[i] == x) {
            return 1; 
        }
    }
    return 0; 
    
//4)
void elementosComuns(int A[], int B[], int T) {
    printf("Elementos comuns nos vetores A e B:\n");
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) {
            if (A[i] == B[j]) {
                printf("%d ", A[i]);
                break; 
            }
        }
    }
}

//5)
void inverte(int *array, int tamanho) {
    int *inicio = array;
    int *fim = array + tamanho - 1; 
    int temp;

    while (inicio < fim) {
        temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}