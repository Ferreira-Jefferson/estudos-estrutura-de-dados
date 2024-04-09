## 38 Evitando Múltiplos Includes (Include Guards)

- Nesta aula é apresentado o Include Guards, que não mais são que uma solução para erros de inclusão duplicada.

  - Pode ocorrer de em um arquivo de header, fazemos o uso de uma outra tad, se o uso de tads ocorrer em multiplos arquivos toda vez que ele for lido pelo compilador, este tentará adicionar ao arquivo final todo o código que aquela expecificação representa, o que pode ocasionar a tentatica de multiplas inclusões eeventualmente um erro na compilação.

- Para corrigir isso, a linguagem C indica o uso de 3 linhas no arquivo header (.h)
  - `#ifndef X` - "Se não definido X" onde X é uma macro que rotula um header
  - `#define X` - "define X" se a macro X não existir é criado o X para que em uma outra tentativa de uso do header, o X exista e a condição não seja atendida
  - `#endif` - sinaliza o fim do bloco ifndef

# Exemplo de aplicação

- hello.h

```c
#ifndef HELLO
#define HELLO

void hello(char *message);

#endif
```

- hello.c

```c
include "hello.h"

void hello(char *message){
  printf("%s", message);
}
```

- float_vector.h

```c
#ifndef FLOAT_VECTOR
#define FLOAT_VECTOR

#include "hello.h"

typedef struct float_vector FloatVector;

FloatVector* create_fv(int capacity); // cria o vetor
void destroy_fv(FloatVector** vector_ref); // Desaloca o vetor

#endif
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
  hello("Vector created");
  return vec;
}

void destroy_fv(FloatVector** vector_ref) {
  FloatVector* aux = *vector_ref;
  free(aux->data);
  free(aux);
  *vector_ref = NULL;
}
```

- app.c

```c
#include <stdio.h>
#include "float_vector.h"
#include "hello.h"

int main() {
  FloatVector *vec = create_fv(2);

  hello("in main function");

  return 0;
}
```

- Note que o arquivo header (.h) foi utilizado tanto em **float_vector.h** quanto em **app.c**, não ouve nenhum erro de compilação neste sentido pois assim que ouve a primeira chamada a macro HELLO foi criada e na segunda por ela já existir, o código apenas foi ignorado, isso também seria verdade caso float_vector também fosse utilizado em mais de um lugar.

- Compilar implementação da tad hello: `gcc -c hello.c`
- Compilar implementação da tad float_vector: `gcc -c float_vector.c`
- Compilar app passando a implementação compilada: `gcc app.c hello.o float_vector.o -o app`
