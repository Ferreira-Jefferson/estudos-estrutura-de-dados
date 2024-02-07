## 15 - Tipos de Alocação de Memória

Em um computador, temos 2 tipos de memória RAM, a stack e a heap e dependendo do tipo de alocação que é feito, a variável vai para um dos dois tipos de memória

# Alocação Estática

- A memória stack é muito menor que a heap
- Sempre que declaramos uma variável _estática_ ou _local_ elas são alocadas na memória stack
  - É importante diferenciar variáveis estáticas de variáveis declaradas com static
    - Variáveis estáticas está fazendo menção a toda variável que foi declarada de forma direta dentro da função main ou demais funções, elas são também chamadas de variáveis locais, pois só existem enquanto a função que a criou existir e só existem dentro daquela função, e note, a função main não deixa de ser uma função, apesar de ser a principal do programa
    - Variáveis usando a palavra reservada _static_ `static int a=10;`, são declaradas de forma global, isso independente de onde elas forem declaradas, elas sempre são alocadas na área de dados do programa, não na stack, nem na heap, em uma memória separada, destinada aos dados do programa e podem ser acessadas por qualquer função.
- Os espaços da variáveis declaradas na stack, são reservados no início do programa e após seu uso são liberadas automaticamente pelo sistema operacional (SO).

- Em resumo, são declaradas na stack, toda variável que fica claro que existe e o tamanho que ela ocupa não pode ser alterado

```c
#include <stdio.h>

int main(){
  int a; // sizeof(int) = 4 bytes => stack
  float b = 2.5;  // sizeof(float) = 4 bytes => stack
  int *p;  // sizeof(*int) = 8 bytes => stack
  float *pp = &b;  // sizeof(float) = 8 bytes => stack
  char v[5]; // sizeof(char) * 5 = 5 bytes => stack

  return 0;
}
```

# Alocação Dinâmica

- São sempre do tipo ponteiro
- A alocação ocorre em tempo de execução, ou seja, de acordo com o que for ocorrendo com o sistema, mais memória pode ser "requisitada" ou "devolvida"
- Não é possível saber quanta memória será alocada
- As variáveis alocadas de maneira dinâmica são sempre declaradas na memória heap, também chamada de **(free store)**
- Utilizamos duas principais funções para alocar espaço, são elas malloc e calloc
  - malloc:
    - recebe um valor como parâmetro, que é o valor total que será alocado
    - int a = malloc(sizeof(int) \* 10)
    - só aloca o espaço, o lixo continua em memória
  - calloc:
    - recebe dois parâmetros, quantidade de itens a serem alocados e tamanho do tipo a ser alocado
    - int \*a = calloc(10, sizeof(int))
    - limpa a memória colocando o zero do tipo em cada espaços alocados
      - int = 0
      - float = 0.0
      - \*tipo = NULL
      - ...
- ⚠️: Todo espaço alocado deve ser desalocada manualmente, não é o SO que desaloca os espaços requeridos em tempo de execução
  - Utiliza-se para isso a função free(variavel)
  - Se o desalocamento não for feito, pode ter um estouro de memória
  - Requer muito cuidado e atenção
- A alocação dinâmica é utilizada principalmente quando não se sabe inicialmente quanto espaço será utilizado

```c
#include <stdio.h>
#include <stdlib.h>

void my_fun(int** x, int tamanho_inicial) {
  *x = realloc(*x, (tamanho_inicial + 5) * sizeof(int));  // De fato aumentou o valor de *a
}

int main(){
  int *a = malloc(sizeof(int) * 10); // sizeof(int) = inicialmente 40, mas pode aumentar => heap
  char *b = calloc(5, sizeof(char)); // sizeof(int) = inicialmente 5, mas pode aumentar => heap

  my_fun(&a, 10);

  free(a);
  free(b);

  return 0;
}
```
