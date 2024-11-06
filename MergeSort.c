#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void MergeSort(int arr[], int n);
void MSRecursao(int arr[], int esquerda, int direita);
void MSJuntar(int arr[], int esquerda, int meio, int direita);

void MergeSort(int arr[], int n) {// fiz dessa forma pra que so precisase declarar a array e seu tamanho para a função funcionar
   MSRecursao(arr, 0, n - 1);//começamos com 0 e o tamanho -1 para dividirmos a array toda
}
void MSRecursao(int arr[], int esquerda, int direita)//separamos inicialmente em duas array esquerda e direita
{
  //Para a recursao quando a esquerda é maior ou igual a direita
  if (esquerda < direita)
  {
    //Acha o meio
    int meio = esquerda + (direita - esquerda) / 2;
  
    //Aqui divide novamento porem agora do começo(esquerda) ata o meio
    MSRecursao(arr, esquerda, meio);
    //e do meio +1 ate o final(direita)
    MSRecursao(arr, meio + 1, direita);
  
    //aqui como ja foi tudo separado juntamos tuodo novamente porem de forma ordenada
    MSJuntar(arr, esquerda, meio, direita);
  }
}
void MSJuntar(int arr[], int esquerda, int meio, int direita)
{
  //Calcula o tamanho das partes esquerda e direita da array
  int TamanhoE = meio - esquerda + 1;
  int TamanhoD = direita - meio;
  
  //Cria arrays temporarias para armazenar cada parte
  int tempE[TamanhoE];
  int tempD[TamanhoD];
  
  //contadores para as 3 array 
  int i, j, k;
  
  // Copia a parte esquerda para a temporaria
  for (int i = 0; i < TamanhoE; i++)
    tempE[i] = arr[esquerda + i];
  
  //Copia a parte direita para a temporaria
  for (int i = 0; i < TamanhoD; i++)
    tempD[i] = arr[meio + 1 + i];
  
  // Basicamente usamos o i para passar pelo TempE e o j pelo TempD e o K na array principal para assim colocar o menor dentro da array e aumentar uma posição para colcar o proximo
  for (i = 0, j = 0, k = esquerda; k <= direita; k++)
  {
    // se quando percorreu tudo e a gente quer pegar o menor valor e ele esta no TempE ou o TempD acabou
    if ((i < TamanhoE) && (j >= TamanhoD || tempE[i] <= tempD[j]))
    {
      arr[k] = tempE[i];
      i++;
    }
   // Se o menor valor é o do tempD e a gente pega ele ou o tempE tiver acabado
    else
    {
      arr[k] = tempD[j];
      j++;
    }
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
    MergeSort(arr, n);
    fim = clock();
    
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    printf("%d %d %d",arr[0],arr[1],arr[n-1]);
    return 0;
}
