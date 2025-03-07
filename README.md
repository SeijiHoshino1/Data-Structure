# Estrutura de dados

[Estrutura de dados - DRIVE](https://drive.google.com/drive/folders/11oMxTWxwmkL5y54WTDpeqPiRIGtnFo-J)

## Estruturas homogêneas

Estruturas homogêneas são estruturas de dados que armazenam informações do mesmo tipo. São também conhecidas como vetores e matrizes.

### Características

- São formadas por um conjunto de variáveis do mesmo tipo;
- Os valores armazenados são acessíveis com um único nome;
- Os valores são armazenados contiguamente na memória;
- A individualização de cada variável é feita através do uso de índice(s);
- O primeiro elemento do conjunto estará no(s) índice(s) 0 (zero).

# Vetores em C

## Introdução

Vetores são estruturas de dados fundamentais em C que permitem armazenar múltiplos valores do mesmo tipo em uma única variável. Eles são essenciais para a manipulação eficiente de coleções de dados em programas C.

## Conceitos Básicos

### Declaração de Vetores

Em C, os vetores são declarados especificando o tipo de dados que eles armazenarão, seguido pelo nome do vetor e seu tamanho entre colchetes.

```c
tipo nome_do_vetor[tamanho];
```

### Inicialização

Vetores podem ser inicializados no momento da declaração ou posteriormente:

```c
int numeros[5] = {1, 2, 3, 4, 5};  // Inicialização na declaração
char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
```

Se você não inicializar todos os elementos, os restantes serão preenchidos com zero:

```c
int parcial[5] = {1, 2};  // Equivalente a {1, 2, 0, 0, 0}
```

## Acessando Elementos

Os elementos do vetor são acessados usando índices, que começam em 0:

```c
int numeros[5] = {10, 20, 30, 40, 50};
int terceiro_elemento = numeros[2];  // Acessa o terceiro elemento (30)
```

## Exemplos Práticos

### Exemplo 1: Cálculo da Média

```c
#include <stdio.h>

int main() {
    int notas[5] = {85, 92, 78, 90, 88};
    int soma = 0;
    float media;
    
    // Soma todos os elementos
    for (int i = 0; i < 5; i++) {
        soma += notas[i];
    }
    
    // Calcula a média
    media = (float)soma / 5;
    
    printf("A média das notas é: %.2f\n", media);
    
    return 0;
}
```

### Exemplo 2: Encontrar o Valor Máximo

```c
#include <stdio.h>

int main() {
    int numeros[8] = {42, 17, 93, 55, 23, 81, 39, 67};
    int maximo = numeros[0];  // Assume que o primeiro elemento é o máximo inicial
    
    // Encontra o valor máximo
    for (int i = 1; i < 8; i++) {
        if (numeros[i] > maximo) {
            maximo = numeros[i];
        }
    }
    
    printf("O valor máximo é: %d\n", maximo);
    
    return 0;
}
```

### Exemplo 3: Invertendo um Vetor

```c
#include <stdio.h>

int main() {
    int vetor[6] = {10, 20, 30, 40, 50, 60};
    int temp;
    
    printf("Vetor original: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", vetor[i]);
    }
    
    // Invertendo o vetor
    for (int i = 0; i < 6/2; i++) {
        temp = vetor[i];
        vetor[i] = vetor[5-i];
        vetor[5-i] = temp;
    }
    
    printf("\nVetor invertido: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", vetor[i]);
    }
    
    return 0;
}
```

## Vetores Multidimensionais

C também suporta vetores multidimensionais, como matrizes:

```c
int matriz[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};
```

### Exemplo 4: Soma de Matrizes

```c
#include <stdio.h>

int main() {
    int matriz1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matriz2[2][3] = {{7, 8, 9}, {10, 11, 12}};
    int resultado[2][3];
    
    // Somando as matrizes
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    
    // Exibindo o resultado
    printf("Resultado da soma das matrizes:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
```

## Vetores como Argumentos de Funções

Quando passamos vetores para funções, na verdade estamos passando um ponteiro para o primeiro elemento:

```c
#include <stdio.h>

// Função que recebe um vetor como argumento
void dobrar_elementos(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] *= 2;
    }
}

int main() {
    int numeros[5] = {1, 2, 3, 4, 5};
    
    printf("Vetor original: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    
    dobrar_elementos(numeros, 5);
    
    printf("\nVetor após dobrar elementos: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    
    return 0;
}
```

## Considerações Importantes

1. Em C, não há verificação de limites dos vetores. Acessar posições fora dos limites pode causar comportamentos inesperados ou crashes.

2. O tamanho do vetor deve ser conhecido em tempo de compilação, a menos que você use alocação dinâmica de memória.

3. Vetores em C ocupam espaço de memória contíguo, o que torna o acesso aos elementos muito eficiente.

## Conclusão

Vetores são fundamentais para a programação em C e formam a base para estruturas de dados mais complexas. Dominar o uso de vetores é essencial para qualquer programador C eficiente.

# Strings

As strings são conjuntos de caracteres e em C/C++ declaramos informando o identificador e a quantidade de caracteres entre colchetes.


(Em construção...)