## 28 Alocação Estática e Dinâmica de Structs

# Alocação Estática de Structs

A alocação das structs não muda com relação as demais alocações, que já foram vistas, entretanto ela tem uma característica que é importante se atentar.
Por ela agrupar variáveis, quando alocamos uma struct, estamos alocando todas as variáveis que ela agrupa, na ordem em que ela foi criada, segue o exemplo.

```c
#include <stdio.h>
#include <string.h>

typedef _aluno {
  char nome[100];
  int idade;
} Aluno;

int main() {
  Aluno bruno;
  size_t len;

  stdcpy(bruno.nome, "Bruno");
  bruno.idade = 10;

  len = sizeof(Aluno)

  return 0;
}
```

| Linha | Memóra | Variável      | Valor |
| ----- | ------ | ------------- | ----- |
| 1     | 0x0    | bruno.nome    | ####  |
| 1     | ...    | bruno.nome    | ####  |
| 1     | 0x99   | bruno.nome    | ####  |
| 1     | 0x100  | bruno.idade   | ####  |
| 2     | 0x104  | len           | ####  |
| 3     | 0x0    | bruno.nome[0] | 'B'   |
| 3     | 0x1    | bruno.nome[1] | 'r'   |
| 3     | 0x2    | bruno.nome[2] | 'u'   |
| 3     | 0x3    | bruno.nome[3] | 'n'   |
| 3     | 0x3    | bruno.nome[4] | 'o'   |
| 3     | 0x3    | bruno.nome[5] | '\0'  |
| 3     | ...    | bruno.nome    | ####  |
| 3     | 0x99   | bruno.nome    | ####  |
| 4     | 0x100  | bruno.idade   | 10    |
| 5     | 0x104  | len           | 104   |

- Note que a variável bruno.nome foi declarada com 100 caracteres, logo, ele ocupa todos os espaços de memória, mesmo que não estejam em uso, no caso a variável bruno.nome só está utilizando 6 bytes de memória, 5 para o nome e 1 para o caracter **\0** que indica o fim da string.

  - Obs: o tipo **char** ocupa 1 byte

- Como já explicado a struct nos permite criar um tipo próprio e se usarmos a função sizeof que retorna o tamanho de um tipo, temos que a struct Aluno tem tamanho 104, o que é observado na última linha no teste de mesa, em que a variável _len_ contém o retorno do tamanho da struct Aluno

# Alocação Dinâmica de Structs

Na alocação dinâmica também continua a mesma coisa, só lembrando do detalhe que quando alocamos uma struct, estamos alocando todas as variáveis declaradas nela.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef _aluno {
  char nome[100];
  int idade;
} Aluno;

int main() {
  Aluno *bruno = calloc(1, sizeof(Aluno));

  stdcpy(bruno->nome, "Bruno");
  bruno->idade = 10;

  return 0;
}
```

- Memória Stack

  | Linha | Memóra | Variável | Valor |
  | ----- | ------ | -------- | ----- |
  | 1     | 0x0    | \*bruno  | 0h0   |
  |       | 0x8    |          | ####  |

- Memória Heap

  | Linha | Memóra | Variável       | Valor |
  | ----- | ------ | -------------- | ----- |
  | 1     | 0h0    | bruno->nome    | 0     |
  | 1     | ...    | bruno->nome    | 0     |
  | 1     | 0h99   | bruno->nome    | 0     |
  | 1     | 0h100  | bruno.idade    | 0     |
  | 2     | 0h0    | bruno->nome[0] | 'B'   |
  | 2     | 0h1    | bruno->nome[1] | 'r'   |
  | 2     | 0h2    | bruno->nome[2] | 'u'   |
  | 2     | 0h3    | bruno->nome[3] | 'n'   |
  | 2     | 0h3    | bruno->nome[4] | 'o'   |
  | 2     | 0h3    | bruno->nome[5] | '\0'  |
  | 2     | ...    | bruno->nome    | 0     |
  | 2     | 0h99   | bruno->nome    | 0     |
  | 3     | 0h100  | bruno.idade    | 10    |

- Perceba que o ponteiro bruno da memória heap, aponta para o primeiro endereço da struct, que neste caso é bruno->nome[0]
