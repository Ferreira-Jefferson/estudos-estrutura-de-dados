## 37 Encapsulamento em C

# Hands on!

Essa é a continuação da implementação da nossa primeira TAD

- O foco desta aula é mostrar como o encapsulamento ocorre utilizando uma tad, em resumo quando não definirmos uma determinada função ou tipo na expecificação (.h), ela não fica disponível para uso fora da implementação (.c).

- Outro ponto abordado é a questão de namespace,e m que ele cria uma função chamada `remove` e o gcc dá um erro pois já existe uma função com este mesmo nome em _stdio.h_. É explicado que a linguagem C tem essa limitação em que todas as funções devem ter nomes diferentes, por conta disso é recomendado que as funções criadas possuam prefixos ou sufixos que as tornem únicas.
- Outra recomendação como boa prática é utilizar o underline (\_) como prefixo de funções privadas, o que permite uma rápida identicação dentro do código.

- float_vector.h

```c
typedef struct float_vector FloatVector;

FloatVector* create_fv(int capacity); // cria o vetor
void destroy_fv(FloatVector** vector_ref); // Desaloca o vetor
int size_fv(const FloatVector *vector); // retorna o tamanho do vetor (número atual de elementos inseridos)
int capacity_fv(const FloatVector *vector); // retorna a capacidade do vetor (número máximo de elementos)
float at_fv(const FloatVector *vector, int index); // retorna o elemento do índice 'index' com bound-checked
float get_fv(const FloatVector *vector, int index); // retorna o elemento do índice 'index'
void append_fv(FloatVector *vector, float val); // adiciona o valor 'val' no final do vetor. Lança um erro se o vetor estiver cheio.
void set_fv(FloatVector *vector, int index, float val); // Atribui o valor 'val' no índice 'index' do vetor de tipo 'FloatVector'. Lança um erro se o índice for inválido.
void print_fv(const FloatVector *vector); // Imprime todos os elementos do vetor.
```

- float_vector.c

```c
#include "float_vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/***** INTERFACE PRIVADA *****/

struct float_vector {
  int capacity;
  int size;
  float *data;
}

bool _isFull_fv(FloatVector *vector) {
  return vector->size == vector->capacity;
}

/***** IMPLEMENTAÇÃO DA INTERFACE PÚBLICA *****/

FloatVector* create_fv(int capacity) {
  FloatVector* vec = calloc(1, sizeof(FloatVector));
  vec->capacity = capacity;
  vec->size = 0;
  vec->data = calloc(capacity, sizeof(float));
  return vec;
}

void destroy_fv(FloatVector** vector_ref) {
  FloatVector* aux = *vector_ref;
  free(aux->data);
  free(aux);
  *vector_ref = NULL;
}

void append_fv(FloatVector *vector, float val) {
  if(_isFull_fv(vector)){
      fprintf(stderr, "ERROR in 'append': vector is full \n");
      exit(EXIT_FAILURE);
  }
  vector->data[vector->size] = val;
  vector->size++;
}

int size_fv(const FloatVector *vector) {
  return vector->size;
}

int capacity_fv(const FloatVector *vector) {
  return vector->capacity;
}

float get_fv(const FloatVector *vector, int index) {
  return vector->data[index];
}

float at_fv(const FloatVector *vector, int index) {
  if(index < 0 || index >= vector->size) {
    fprintf(stderr, "ERROR in 'at': invalid index \n");
    exit(EXIT_FAILURE);
  }
  return vector->data[index];
}

void set_fv(FloatVector *vector, int index, float val) {
  if(index < 0 || index >= vector->size) {
    fprintf(stderr, "ERROR in 'set': invalid index \n");
    exit(EXIT_FAILURE);
  }
  vector->data[index] = val;
}

void print_fv(const FloatVector *vector) {
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
  FloatVector *vec = create_fv(2);

  append_fv(vec, 10.5);
  append_fv(vec, 15);
  print_fv(vec);

  printf("size: %d \n", size_fv(vec));
  printf("capacity: %d \n", capacity_fv(vec));
  printf("get: %.2f \n", get_fv(vec, 1));
  printf("at: %.2f \n", at_fv(vec, 0));

  // O vetor suporta somente 2 elementos, a linha abaixo, se descomentada, deve dar um erro.
  // append(vec, 23.1);

  destroy_fv(&vec);

  printf("vec == NULL: %d", vec == NULL);

  return 0;
}
```

- Compilar implementação da tad: `gcc -c float_vector.c`
- Compilar app passando a implementação compilada: `gcc app.c float_vector.o -o app`
