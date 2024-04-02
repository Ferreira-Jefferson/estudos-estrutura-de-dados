## 36 Implementando um TAD (Parte 4)

# Hands on!

Essa é a continuação da implementação da nossa primeira TAD

- float_vector.h

```c
typedef struct float_vector FloatVector;

FloatVector* create(int capacity); // cria o vetor
void destroy(FloatVector** vector_ref); // Desaloca o vetor
int size(const FloatVector *vector); // retorna o tamanho do vetor (número atual de elementos inseridos)
int capacity(const FloatVector *vector); // retorna a capacidade do vetor (número máximo de elementos)
float at (const FloatVector *vector, int index); // retorna o elemento do índice 'index' com bound-checked
float get (const FloatVector *vector, int index); // retorna o elemento do índice 'index'
void append(FloatVector *vector, float val); // adiciona o valor 'val' no final do vetor. Lança um erro se o vetor estiver cheio.
void set(FloatVector *vector, int index, float val); // Atribui o valor 'val' no índice 'index' do vetor de tipo 'FloatVector'. Lança um erro se o índice for inválido.
void print(const FloatVector *vector); // Imprime todos os elementos do vetor.
```

- float_vector.c

```c
#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>

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

void append(FloatVector *vector, float val) {
  if(vector->size == vector->capacity){
      fprintf(stderr, "ERROR in 'append': vector is full \n");
      exit(EXIT_FAILURE);
  }
  vector->data[vector->size] = val;
  vector->size++;
}

void print(const FloatVector *vector) {
  puts("--------------");
  printf("capacity: %d \n", vector->capacity);
  printf("size: %d \n", vector->size);
  printf("Data: \n");
  for(int i=0; i < vector->size; i++)
    printf("  [%d]: %.2f \n", i, vector->data[i]);
  puts("--------------");
}
```

- app.c

```c
#include <stdio.h>
#include "float_vector.h"

int main() {
  FloatVector *vec = create(2);

  append(vec, 10.5);
  append(vec, 15);
  print(vec);

  // O vetor suporta somente 2 elementos, a linha abaixo, se descomentada, deve dar um erro.
  // append(vec, 23.1);

  destroy(&vec);

  printf("vec == NULL: %d", vec == NULL);

  return 0;
}
```

- Compilar implementação da tad: `gcc -c float_vector.c`
- Compilar app passando a implementação compilada: `gcc app.c float_vector.o -o app`
