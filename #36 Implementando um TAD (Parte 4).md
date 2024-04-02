## 36 Implementando um TAD (Parte 4)

# Hands on!

Essa é a continuação da implementação da nossa primeira TAD

- float_vector.h

```c
typedef struct float_vector FloatVector;

FloatVector* create(int capacity); // cria o vetor
void destroy(FloatVector** vector_ref); // Desaloca o vetor
int size(const FloatVector vector); // retorna o tamanho do vetor (número atual de elementos inseridos)
int capacity(const FloatVector vector); // retorna a capacidade do vetor (número máximo de elementos)
float at (const FloatVector vector, int index); // retorna o elemento do índice 'index' com bound-checked
float get (const FloatVector vector, int index); // retorna o elemento do índice 'index'
void append(FloatVector *vector, float val); // adiciona o valor 'val' no final do vetor. Lança um erro se o vetor estiver cheio.
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

void append(FloatVector *vector, float val) {
  vector->data[vector->size] = val;
}
```

- app.c

```c
#include <stdio.h>
#include "float_vector.h"

int main() {
  FloatVector *vec = create(2);

  append(vec, 10.5) ;
  printf("vec: %p \n", vec);
  printf("vec->data[0]: %.2f \n", vec->data[0]);

  destroy(&vec);

  printf("vec == NULL: %d", vec == NULL);

  return 0;
}
```
