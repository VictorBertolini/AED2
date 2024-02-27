#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 41 67 34 0 69 24 78 58 62 64 5 45 81 27 61 

// Função para trocar dois elementos em um vetor
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para transformar um vetor em um max-heap
void maxHeapify(int A[], int i, int tamanhoDoHeap) {
    int maior = i; // Inicializa o nó pai como o maior
    int l = 2 * i + 1; // Calcula o índice do filho esquerdo
    int r = 2 * i + 2; // Calcula o índice do filho direito

    // Seleciona o maior entre pai, filho-esquerdo e filho-direito
    if (l < tamanhoDoHeap && A[l] > A[maior])
        maior = l;

    if (r < tamanhoDoHeap && A[r] > A[maior])
        maior = r;

    // Se o maior não for o pai, troca os elementos e chama recursivamente maxHeapify
    if (maior != i) {
        trocar(&A[i], &A[maior]);
        maxHeapify(A, maior, tamanhoDoHeap);
    }
}

// Função para construir um max-heap
void buildMaxHeap(int A[], int tamanhoDoArray) {
    // Para cada nó interno (não folha)
    for (int i = floor(tamanhoDoArray / 2) - 1; i >= 0; i--)
        // Chama maxHeapify seguindo o sentido folha-raiz
        maxHeapify(A, i, tamanhoDoArray);
}

// Função para ordenar um vetor usando heapsort
void heapsort(int A[], int tamanhoDoArray) {
    buildMaxHeap(A, tamanhoDoArray);

    for (int i = tamanhoDoArray - 1; i >= 1; i--) {
        trocar(&A[0], &A[i]);
        tamanhoDoArray--;
        maxHeapify(A, 0, tamanhoDoArray);
    }
}


int main()
{
    srand(time(NULL)); // Seed for random number generation

    // Definindo o tamanho do array
    int tamanho_do_array = 15;

    // Alocando dinamicamente o array
    int *array = (int *)malloc(tamanho_do_array * sizeof(int));

    // Preenchendo o array com números aleatórios
    printf("Array original: \n");
    for (int i = 0; i < tamanho_do_array; i++)
    {
        array[i] = rand() % 100; // Gera números aleatórios entre 0 e 99
        printf("%d ", array[i]);
    }

    // Chama a função heapsort para ordenar o array
    heapsort(array, tamanho_do_array);

    // Imprime o array ordenado
    printf("\nArray ordenado: ");
    for (int i = 0; i < tamanho_do_array; i++)
        printf("%d ", array[i]);
    
    // Libera a memória alocada dinamicamente para o array
    free(array);

    return 0;
}