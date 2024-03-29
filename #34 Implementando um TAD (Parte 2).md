## 34 Implementando um TAD (Parte 2)

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

- O vídeo se encerra com a implementação das funções **create** e **destroy**, o restante da implementação se encontra nos vídeos seguintes e aqui serão implementados em outros arquivos, mas convido você a tentar implementar as demais funções em _float_vector.h_, por conta própria antes de olhar a implementação concluída.
