## 30 Vetores de Structs

A definição de vetores quando trabalhamos com struct não sofre alteração, sendo possível trabalhar com vetores estáticos de structs ou vetores dinâmicos.

# Alocação estática de um vetor de struct

```c
#include <stdio.h>
#include <string.h>

typedef struct {
  char nome[100];
  int idade;
} Aluno;

int main() {
  Aluno alunos[10];

  strcpy(alunos[0].nome, "Aluno 1");
  alunos[0].idade = 10;

  strcpy(alunos[1].nome, "Aluno 2");
  alunos[1].idade = 11;

  printf("alunos[0] | nome: %s - idade: %d\n", alunos[0].nome, alunos[0].idade);
  printf("alunos[1] | nome: %s - idade: %d\n", alunos[1].nome, alunos[1].idade);

  return 0;
}
// alunos[0] | nome: Aluno 1 - idade: 10
// alunos[1] | nome: Aluno 2 - idade: 11
```

# Alocação dinâmica de um vetor de struct

- Vetor simples

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[100];
  int idade;
} Aluno;

int main() {
  Aluno *alunos = calloc(10, sizeof(Aluno));

  strcpy(alunos[0].nome, "Aluno 1");
  alunos[0].idade = 10;

  strcpy(alunos[1].nome, "Aluno 2");
  alunos[1].idade = 11;

  printf("alunos[0] | nome: %s - idade: %d\n", alunos[0].nome, alunos[0].idade);
  printf("alunos[1] | nome: %s - idade: %d\n", alunos[1].nome, alunos[1].idade);

  free(alunos);
  alunos = NULL;

  return 0;
}
// alunos[0] | nome: Aluno 1 - idade: 10
// alunos[1] | nome: Aluno 2 - idade: 11
```

- Note que por ser um "vetor simples", a alocação aponta para o espaço de memória na heap e lá guarda em cada endereço, uma struct Aluno, logo seu acesso se dá por meio do ponto (.), essa abordade pode acarretar em confusão e erros, pois estamos trabalhando na heap assim como trabalharíamos na stack, uma solução para isso seria trabalhar com um vetor de ponteiros.

* Vetor de ponteiros

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[100];
  int idade;
} Aluno;

int main() {
  Aluno **alunos = calloc(10, sizeof(Aluno*));
  alunos[0] = calloc(1, sizeof(Aluno));
  alunos[1] = calloc(1, sizeof(Aluno));

  strcpy(alunos[0]->nome, "Aluno 1");
  alunos[0]->idade = 10;

  strcpy(alunos[1]->nome, "Aluno 2");
  alunos[1]->idade = 11;

  printf("alunos[0] | nome: %s - idade: %d\n", alunos[0]->nome, alunos[0]->idade);
  printf("alunos[1] | nome: %s - idade: %d\n", alunos[1]->nome, alunos[1]->idade);

  free(alunos[1]);
  free(alunos[0]);
  free(alunos)
  alunos = NULL;


  return 0;
}
// alunos[0] | nome: Aluno 1 - idade: 10
// alunos[1] | nome: Aluno 2 - idade: 11
```

- Esta solução nos permite identificar que o vetor de alunos foi alocado dinâmicamene o que impede eventuais erros e bugs
- Mas ainda há algo que dá para melhorar, note que temos todo um processo repetitivo na criação e alocação dos vetores, por quê não transformamos o vetor de alunos de dado?

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[100];
  int idade;
} Aluno;

typedef struct {
  Aluno **vet;
  int size;
} VetorAlunos;

VetorAlunos* criaVetorAlunos(int tamanho) {
  Aluno** alunos = calloc(tamanho, sizeof(Aluno*));
  VetorAlunos* vetor_alunos = calloc(1, sizeof(VetorAlunos));
  vetor_alunos->vet = alunos;
  vetor_alunos->size = tamanho;
  return vetor_alunos;
}

Aluno* criaAluno(const char nome[], int idade){
  Aluno *aluno = calloc(1, sizeof(Aluno));
  strcpy(aluno->nome, nome);
  aluno->idade = idade;
  return aluno;
}

VetorAlunos* popularVetorAlunos(VetorAlunos *vetor_alunos, const char *nomes[], const int idades[]) {

  for(int i=0; i < vetor_alunos->size; i++) {
    vetor_alunos->vet[i] = criaAluno(nomes[i], idades[i]);
  }
  return vetor_alunos;
}

int main() {
  VetorAlunos *vetor_alunos = criaVetorAlunos(2);
  char nomes[2][100] = {"Aluno 1", "Aluno 2"};
  int idades[2] = {10, 11};

  vetor_alunos = popularVetorAlunos(vetor_alunos, nomes, idades);

  printf("vetor_alunos[0] | nome: %s - idade: %d\n", vetor_alunos[0]->nome, vetor_alunos[0]->idade);
  printf("vetor_alunos[1] | nome: %s - idade: %d\n", vetor_alunos[1]->nome, vetor_alunos[1]->idade);

  free(vetor_alunos[1]);
  free(vetor_alunos[0]);
  free(vetor_alunos);
  vetor_alunos = NULL;

  return 0;
}
```
