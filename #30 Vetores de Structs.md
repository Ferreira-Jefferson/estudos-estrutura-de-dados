## 30 Vetores de Structs

A definição de vetores quando trabalhamos com struct não sofre alteração, sendo possível trabalhar com vetores estáticos de structs ou vetores dinâmicos.

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
- Mas ainda há algo que dá para melhorar, note que temos todo um processo repetitivo na criação e alocação dos vetores, por quê não transformamos o vetor de alunos em um tipo personalizado?

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
  int max;
} VetorAlunos;

Aluno* criarAluno(char *nome, int idade) {
    Aluno *aluno = calloc(1, sizeof(Aluno));
    strcpy(aluno->nome, nome);
    aluno->idade = idade;
    return aluno;
}

VetorAlunos* criarVetorAluno(int qtdAlunos) {
    VetorAlunos* vetAluno = calloc(1, sizeof(VetorAlunos));
    vetAluno->vet = calloc(qtdAlunos, sizeof(Aluno*));
    vetAluno->size = 0;
    vetAluno->max = qtdAlunos;
    return vetAluno;
}

void adicionaAlunoNoVetor(VetorAlunos** vetAluno, Aluno* aluno) {
    VetorAlunos* vetAux = *vetAluno;
    int index = vetAux->size;
    vetAux->vet[index] = aluno;
    vetAux->size = index + 1;
}

void freeVetorAlunos(VetorAlunos** vetAlunos){
    VetorAlunos* vetAux = *vetAlunos;
    for(int i=0; i < vetAux->size; i++){
        free(vetAux->vet[i]);
    }
    free(vetAux);
    *vetAlunos = NULL;
}

int main() {
  Aluno **vetAluno = calloc(2, sizeof(Aluno*));
  vetAluno[0] = criarAluno("Aluno 1", 15);
  printf("%s - %d\n", vetAluno[0]->nome, vetAluno[0]->idade);

  VetorAlunos* vetAlunos = criarVetorAluno(10);
  printf("Antes: %p - %d - %d\n", vetAlunos->vet[0]->nome, vetAlunos->size, vetAlunos->max);

  adicionaAlunoNoVetor(&vetAlunos, vetAluno[0]);

  printf("Depois: %s - %d - %d\n", vetAlunos->vet[0]->nome, vetAlunos->size, vetAlunos->max);

  free(vetAluno);
  vetAluno = NULL;

  freeVetorAlunos(&vetAlunos);
  printf("%d", vetAlunos == NULL);

  return 0;
}
```
