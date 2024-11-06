#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Troca(int *x, int *y);
void QuickSort(int arr[], int length);
void Recursao(int arr[], int menor, int maior);
int Repartir(int arr[], int menor, int maior);

// Realiza a troca nas partições da array
void troca(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
// Essa função so existe para que a entrada principal seja apenas da array e seu tamanho
void QuickSort(int arr[], int n)
{
  //Escolhe um pivo de forma randomica ja que é assim q o quicksort funciona
  srand(time(NULL));
  
  // Começa no zero e termina no ultimo elemento ja que queremos aplicar o quicksort na array toda
  Recursao(arr, 0, n - 1);
}
// Aplica a recursao de forma a "dividir e conquistar" na array dentro do atual menor e maior elementos
void Recursao(int arr[], int menor, int maior)
{
  // Para a recursao caso o menor n seja < q o maior
  if (menor < maior)
  {
    //Reparte apartir do pivo e retorna sua posiçao
    int pivo = Repartir(arr, menor, maior);

    //Aplica o quicksort na parte a esquerda da subarray
    Recursao(arr, menor, pivo - 1);

    //Aplica na parte direita da subarray
    Recursao(arr, pivo + 1, maior);
  }
}

//Reparte a array entre a posiçao menor e o maior pelo valor do pivo e retorna a posiçao do pivo
int Repartir(int arr[], int menor, int maior)
{
  //Seleciona de forma aleatoria o pivo dentro do menor-maior pq assim tem menos chance de ter uma performance ruim no metodo quicksort
  int pivo= menor + (rand() % (maior - menor));
  
  //Troca o elemento na posição do pivo com o na posiçao maior(o ultimo elemento da array) assim podemos aplicar na parte abaixo do algoritimo
  if (pivo != maior)
    troca(&arr[pivo], &arr[maior]);

  //Agora o valor do pivo é oq estava na posição maior
  int valorpivo = arr[maior];

  //O repartir vai separar os elementos que sao menores q o pivo para a parte da frente, com o i mantendo guardado onde os elementos maiores q o pivo pertencem
  int i = menor; 

  //O j vai ir do menor ao maior porem sem incluir o valor do pivo no maior
  for (int j = menor; j < maior; j++)
  {
    //Se o valor na posiçao j for menor que o valor do pivo sera realizada a troca com o valor da posiçao i assim movendo tudo
    //menor q o pivo para a parte da frente e usamos o i para colocar os valores maiores doq o do pivo onde eles devem ficar
    if (arr[j] <= valorpivo)
    {
      troca(&arr[i], &arr[j]);
      i++;
    }
  }

  //Sabendo q o valor da posiçao i é maior ou igual do pivo realizamos a troca com o valor do pivo para completar a repartição
  troca(&arr[i], &arr[maior]);
  
  //O valor i agora contem o valor do pivo ent a gente retorna ele para q a funçao do quicksort saiba onde
  //onde se separar quando aplicar o algoritimo na subarray resultante
  return i;
}


int main() {
    int arr[3];
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
    QuickSort(arr, n);
    fim = clock();
    
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    printf("%d %d %d\n",arr[0],arr[n/2],arr[n-1]);
    return 0;
}
