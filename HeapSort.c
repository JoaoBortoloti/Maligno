#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para fazer o heapify em uma subárvore com a raiz em 'i'
void heapify(int arr[], int n, int i) {
    int maior = i;           // Inicializa o maior como a raiz
    int filhoesq = 2 * i + 1; // Filho esquerdo
    int filhodir = 2 * i + 2; // Filho direito

    // Se o filho esquerdo é maior que a raiz
    if (filhoesq < n && arr[filhoesq] > arr[maior])
        maior = filhoesq;

    // Se o filho direito é maior que o maior atual
    if (filhodir < n && arr[filhodir] > arr[maior])
        maior = filhodir;

    // Se o maior não é a raiz
    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;

        // Recursivamente faz o heapify na subárvore afetada
        heapify(arr, n, maior);
    }
}

// Função principal para realizar o heap sort
void HeapSort(int arr[], int n) {
    // Construir um heap máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extrair elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o final
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Chama o heapify na subárvore reduzida
        heapify(arr, i, 0);
    }
}

int main() {
    int arr[3];
    int n = sizeof(arr) / sizeof(arr[0]);
    
    srand(time(NULL));

    // Preenche a array com valores aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; 
    }

    printf("%d %d %d\n", arr[0], arr[1], arr[n-1]);

    clock_t inicio, fim;
    double tempo_cpu;
    
    inicio = clock();
    HeapSort(arr, n);
    fim = clock();
    
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    printf("%d %d %d\n", arr[0], arr[1], arr[n-1]);

    return 0;
}
