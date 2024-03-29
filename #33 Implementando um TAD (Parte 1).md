## 33 Implementando um TAD (Parte 1)

# Hands on!

Iremos criar nossa primeira TAD, será uma tad para criar e manipular um vetor de um tipo, o tipo escolhido é o float.

- Expecificação (.h)

* float_vector.h

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

- A saber, o nome dos atributos não são obrigatórios na assinatura das funções, somente o tipo, sendo assim, ambas as maneiras abaixo estão corretas.
  - `void print(const FloatVector vector);`
  - `void print(const FloatVector);`
- Nesta mesma linha, o nome do atributo na implementação da função não precisa ser o mesmo da assinatura, conforme mostrado abaixo.

  - `void print(const FloatVector vector);`
  - `void print(const FloatVector vector_ref) {...}`

- float_vector.c

```c
#include "float_vector.h"
#include <stdlib.h>

struct float_vector {
  int capacity;
  int size;
  float *data;
}
```

- O vídeo se encerra com a implementação da **struct** apenas, o restante da implementação se encontra nos vídeos seguintes e aqui serão implementados em outros arquivos.
