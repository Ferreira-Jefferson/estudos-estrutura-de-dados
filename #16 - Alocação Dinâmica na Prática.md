## 16 - Alocação Dinâmica na Prática

Alocação dinâmica é quando o tamanho ocupado da memória pode ser alterado no ciclo de vida do sistema
A memória que é manipulada é memória heap, que por ser muito maior que a stack, consegue suportar reajustes extensivos de memória
Usamos duas principais funções para fazer essa alocação dinâmica, são elas a função malloc e calloc

- int \*x = (int \*) malloc(5 \* sizeof(int))

  - int \*x: variável x é do tipo ponteiro de inteiro
  - (int \*): isso se chama CAST, basicamente está convertendo o retorno de malloc que é um ponteiro de void para o tipo da variável, entretanto não é amplamente recomendado fazer o _casting_, pois seu uso podem esconder erros de compilação ou causar probemas de portabilidade
  - malloc(5 \* sizeof(int)): função que aloca o espaço passado como parâmetro na memória heap e retorna o endereço inicial do espaço alocado
    - recebe como parâmetro o tamanho total que se deseja alocar, é interessante não colocar valores fixos, mas sim usar o sizeof(TIPO) para permitir uma maior portabilidade do código para diferentes arquiteturas, isso porquê o tamanho de um tipo pode mudar de acordo com a arquitetura do sistema ou linguagem

- int \*x = calloc(5, sizeof(int))
  - A única diferença do calloc para o malloc é que ele intancia todos os espaços retornado com o zero do tipo

# Alocação Na Prática

```c
#include <stdio.h>
#include <stdlib.h>

void runEstatica() {
  puts("Alocacao Estatica");

  int v[5] = {0, 10, 20, 30, 40};

  for(int i=0; i < 5; i++){
    printf("v[%d]: %d, &v[%d]: %p \n", i, v[i], i, &v[i]);
  }
  puts("");
}

void runMalloc() {
  puts("Alocação Dinamica MALLOC");
  puts("--Com Lixo na memória");

  int *vm = malloc(5*sizeof(int));

  for(int i=0; i < 5; i++){
    printf("---vm[%d]: %d, &vm[%d]: %p \n", i, vm[i], i, &vm[i]);
    vm[i] = i*10;
  }
  for(int i=0; i < 5; i++){
    printf("vm[%d]: %d, &vm[%d]: %p \n", i, vm[i], i, &vm[i]);
  }
  free(vm);
  vc = NULL;
  puts("");
}

void runCalloc() {
  puts("\nAlocação Dinamica CALLOC");
  puts("--Sem Lixo na memória");

  int *vc = calloc(5, sizeof(int));

  for(int i=0; i < 5; i++){
    printf("---vc[%d]: %d, &vc[%d]: %p \n", i, vc[i], i, &vc[i]);
    vc[i] = i*10;
  }
  for(int i=0; i < 5; i++){
    printf("vc[%d]: %d, &vc[%d]: %p \n", i, vc[i], i, &vc[i]);
  }
  free(vc);
  vc = NULL;
  puts("");
}

int main() {
  runEstatica();
  runMalloc();
  runCalloc();
  return 0;
}
```

- ⚠️: Nunca se esqueça de desalocar os ponteiros dinâmicos
- ⚠️: É uma boa prática colocar o valor do ponteiro apontando para NULL após desalocá-lo
