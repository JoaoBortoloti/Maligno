#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    for (int x = 0; x < n - 1; x++) {
        int menor = x;//loop externo para percorrer todo o array e definir onde o proximo menor elemento sera colocado
        for (int y = x + 1; y < n; y++) {
            if (arr[y] < arr[menor]) {
                menor = y;
            }// loop que compara os elementos com o menor e se necessario o substitui por y
        }
        if (menor != x) {
            int temp = arr[x];
            arr[x] = arr[menor];
            arr[menor] = temp;
        }//essa parte garante q a os elementos sejam substituidos na array e guarda o x em um variavel temporaria para ele nao se perder
    }
}

int main() {
    int arr[3];
    int n = sizeof(arr) / sizeof(arr[0]);
    
    srand(time(NULL));

    // Preenche a array com valores aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    printf("%d %d %d\n",arr[0],arr[1],arr[n-1]);

    clock_t inicio, fim;
    double tempo_cpu;
    
    inicio = clock();
    selectionSort(arr, n);
    fim = clock();
    
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    printf("%d %d %d",arr[0],arr[1],arr[n-1]);
    
    return 0;
}
