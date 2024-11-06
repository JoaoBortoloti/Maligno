#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(int arr[], int n) {
    for(int x=1;x< n ;x++){//for q passa por todo a array
        int atual =arr[x];
        int y = x-1;
        while((y>=0) && (atual<arr[y])){// confere se o atual é menor que as posições que vao sendo passadas na array(arr[y]) e qnd for ele entra no loop
            arr[y+1] = arr[y];//essa parte faz a troca das variaveis de lugar pq é assim q funciona o insertion sort
            y=y-1;
        }
        arr[y+1]=atual;// realiza a inserção do menor valor numa posição anterior
    }

}

int main() {
    int arr[100];
    int n = sizeof(arr) / sizeof(arr[0]);
    
    srand(time(NULL));

    // Preenche a array com valores aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    printf("%d %d %d\n",arr[0],arr[n/2],arr[n-1]);
    clock_t inicio, fim;
    double tempo_cpu;
    
    inicio = clock();
    InsertionSort(arr, n);
    fim = clock();
    
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    printf("%d %d %d\n",arr[0],arr[n/2],arr[n-1]);
    return 0;
}
