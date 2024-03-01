## 29 Codificando um CRUD de Structs

Exercício CRUD de Structs:

- Considere que o Aluno possui um livro favorito, que, por simplificação, possui um título, número de páginas e preço.
- Codifique a struct de Livro e adapte a struct de Aluno;
- Crie as funções de Criação (C), Delete (D) e de Impressão para a Struct Aluno e Livro. Na função de Delete, garanta que o ponteiro é atribuído como NULL depois da desalocação

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char titulo[100];
  int numero_paginas;
  float preco;
} Livro;

typedef struct {
  char nome[100];
  Livro *livro_favorito;
} Aluno;

Aluno* createAluno(const char nome[], const Livro *livro_favorito) {
  Aluno *aluno = calloc(1, sizeof(Aluno));
  strcpy(aluno->nome, nome);
  aluno->livro_favorito = livro_favorito;
  return aluno;
}

Livro* createLivro(const char titulo[], unsigned int numero_paginas, float preco) {
  Livro *livro = calloc(1, sizeof(Livro));
  strcpy(livro->titulo, titulo);
  livro->numero_paginas = numero_paginas;
  livro->preco = preco;
  return livro;
}

Livro* copyLivro(const Livro *livro) {
    return createLivro(livro->titulo, livro->numero_paginas, livro->preco);
}

void readLivro(const Livro *livro){
    printf("Título: %s\n", livro->titulo);
    printf("Nº Páginas: %d\n", livro->numero_paginas);
    printf("Preco: R$ %.2f\n", livro->preco);
}

void readAluno(const Aluno *aluno){
    printf("Aluno: %s\n", aluno->nome);
    readLivro(aluno->livro_favorito);
}

void delete(void **p){
    if(*p) {
      free(*p);
      *p = NULL;
    }
}

void deleteAluno(Aluno **aluno){
    delete(&(*aluno)->livro_favorito);
    delete(&(*aluno));
}

void deleteLivro(Livro **livro){
    delete(&(*livro));
}

int main(){
  Livro *livro = createLivro("Titulo Livro 1", 100, 25.50);
  Aluno *aluno = createAluno("Joséfino Montenegro", copyLivro(livro));

  readAluno(aluno);
  deleteAluno(&aluno);
  deleteLivro(&livro);

  return 0;
}
```
