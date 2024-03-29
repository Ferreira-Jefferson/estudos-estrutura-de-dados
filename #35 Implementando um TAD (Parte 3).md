## 35 Implementando um TAD (Parte 3)

# Hands on!

Essa é a continuação da implementação da nossa primeira TAD

- O foco principal é em testar o que foi implementado até o momento e para isso o professor explica como se compila a tad e como indicamos ao compilador qual a tad que iremos usar em nosso programa.

- float_vector.h

```c
typedef struct float_vector FloatVector;

FloatVector* create(int capacity); // cria o vetor
void destroy(FloatVector** vector_ref); // Desaloca o vetor
int size(const FloatVector vector); // retorna o tamanho do vetor (número atual de elementos inseridos)
int capacity(const FloatVector vector); // retorna a capacidade do vetor (número máximo de elementos)
float at (const FloatVector vector, int index); // retorna o elemento do índice 'index' com bound-checked
float get (const FloatVector vector, int index); // retorna o elemento do índice 'index'
void append(FloatVector vector, float val); // adiciona o valor 'val' no final do vetor. Lança um erro se o vetor estiver cheio.
void set(FloatVector vector, int index, float val); // Atribui o valor 'val' no índice 'index' do vetor de tipo 'FloatVector'. Lança um erro se o índice for inválido.
void print(const FloatVector vector); // Imprime todos os elementos do vetor.
```

- float_vector.c

```c
#include "float_vector.h"
#include <stdlib.h>

struct float_vector {
  int capacity;
  int size;
  float *data;
}

FloatVector* create(int capacity) {
  FloatVector* vec = calloc(1, sizeof(FloatVector));
  vec->capacity = capacity;
  vec->size = 0;
  vec->data = calloc(capacity, sizeof(float));
  return vec;
}

void destroy(FloatVector** vector_ref) {
  FloatVector* aux = *vector_ref;
  free(aux->data);
  free(aux);
  *vector_ref = NULL;
}
```

# Compilando a implementação da tad

Para utilizar nossa tad, antes é necessário que ela seja compilada, entretanto para compilar um arquivo .c é necessário que ele tenha a função main() em seu corpo, o que não é o caso da nossa tad.
O que parece ser algo complexo se torna simples quanto entendemos que a tab é uma lib e não um programa propriamente dito, sendo assim a exigência da main() cai por terra, tornando necessário apenas indicar para o compilador que estamos criando uma lib, fazemos isso colocando a flag **-c** antes do nome do arquivo.c da tad.

- gcc -c float_vector.c

Somente fazer isso já irá criar um arquivo com extensão (.o) que é a exetensão padrão criada pelo próprio gcc (compilador da linguagem c), para libs.

Note que em nenhum momento referenciamos a expecificação (.h) na compilação. Isso ocorre porque já a estamos referenciando dentro da implementação (.c) com o comando `#include "float_vector.h"` e como eles estão na mesma pasta não é ncessário indicar ao compilador aonde o expecificação está.

# Usando nossa 1ª tad

- app.c

```c
#include <stdio.h>
#include "float_vector.h"

int main() {
  FloatVector *vec = create(2);

  printf("vec: %p \n", vec);

  destroy(&vec);

  printf("vec == NULL: %d", vec == NULL);

  return 0;
}
```

- Para compilar corretamente um programa c que utiliza uma tad é necessário informar onde a tad está, pois no programa apenas estamos usando a especificação (.h), mas a expecificação não sabe onde a implementação concreta da tad se encontra.
  Para isso, ao compilar declaramos também o arquivo já compilado da tad (.o) o que irá gerar um arquivo de programa unindo tando a tad quanto o programa que irá utilizá-la, voltando ao exemplo do início dos estudos de tad, estamos colocando na caixa além do drone (o programa .c), também o manual (.h) e o controle (.o), veja como deve ser feita a compilação considerando nossa tad float_vector
  - gcc app.c float_vector.o -o app
    - gcc compila o app e a tad e dá um output chamado app
