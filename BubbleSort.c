#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int arr[], int n) {
    for (int x=0;x<n;x++){//for q faz passar por todo a array 
        for(int y=0;y<n-1;y++){// tb passa por toda a array menos 1 ja q estara sendo comparada com outra variavel 
            if(arr[y]> arr[y+1])//compara em pares e caso o anterior seja maior faz a troca
            {
                int temp = arr[y];// usa a variavel temporari(temp) para poder fazer a troca das outras variaveis de lugar 
                arr[y] = arr[y+1];
                arr[y+1] = temp;
            }
        }
    }
    
}
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
    BubbleSort(arr, n);
    fim = clock();
    
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    printf("%d %d %d",arr[0],arr[1],arr[n-1]);
    return 0;
}
