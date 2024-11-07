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
void SelectionSort(int arr[], int n) {
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
void troca(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
void QuickSort(int arr[], int n)// Essa função so existe para que a entrada principal seja apenas da array e seu tamanho
{
  //Escolhe um pivo de forma randomica ja que é assim q o quicksort funciona
  srand(time(NULL));
  
  // Começa no zero e termina no ultimo elemento ja que queremos aplicar o quicksort na array toda
  Recursao(arr, 0, n - 1);
}
void Recursao(int arr[], int menor, int maior)// Aplica a recursao de forma a "dividir e conquistar" na array dentro do atual menor e maior elementos
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
int Repartir(int arr[], int menor, int maior)//Reparte a array entre a posiçao menor e o maior pelo valor do pivo e retorna a posiçao do pivo
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
    int tmn;
    printf("Escolha um tamanho de 1 - 100.000: ");
    scanf("%d",&tmn);
    int arr[tmn];
    int n = sizeof(arr) / sizeof(arr[0]);
    srand(time(NULL));
    int escolha;
    printf("Qual o metodo que você quer usar para ordenar a array?\n");
    printf("1-Selection Sort\n");
    printf("2-Insertion Sort\n");
    printf("3-Bubble Sort\n");
    printf("4-Merge Sort\n");
    printf("5-Quick Sort\n");
    printf("6-Heap Sort\n");
    scanf("%d",&escolha);
    // Preenche a array com valores aleatórios
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    printf("%d %d %d\n",arr[0],arr[1],arr[n-1]);

    clock_t inicio, fim;
    double tempo_cpu;
    
    inicio = clock();
    if (escolha == 1) {
    SelectionSort(arr, n);
    } else if (escolha == 2) {
    InsertionSort(arr, n);
    } else if (escolha == 3) {
    BubbleSort(arr, n);
    } else if (escolha == 4) {
    MergeSort(arr, n);
    } else if (escolha == 5) {
    QuickSort(arr, n);
    } else if (escolha == 6) {
    HeapSort(arr, n);
    } else {
    printf("Opção inválida!\n");
    }

    fim = clock();
    
    tempo_cpu = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo de execução: %f segundos\n", tempo_cpu);
    printf("%d %d %d",arr[0],arr[1],arr[n-1]);
    
    return 0;
}
