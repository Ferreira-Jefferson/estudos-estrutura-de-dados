## 12 Funções - Exercícios

# ** disclaimer **

- O teste de mesa está feito de cima para baixo para facilitar a leitura, mas na _stack_ eles são inseridos em pilha, ou seja, o último a ser inserido fica encima e é o primeiro a ser desempilhado, é o que chamamos de **LIFO** - _Last In First Out_
- Os endereços das variáveis criadas na função main e os endereços das variáveis criadas nas demais funções estão sequênciais, mas prática, como já estudado, o sistema aloca a variável de cada função em um local separado na memória ram e não de forma sequêncial

# Exercício 1

```c
#include <stdio.h>

void troca(int *x, int *y) {
  int aux = *x;
  *x = *y;
  *y = aux;
}

int main(){
  int a = 20;
  int b = 30;

  troca(&a, &b);

  printf("a: %d, b: %d", a, b);

  return 0;
}

```

- Teste de mesa

| Linha | Memóra | Variável | Valor |
| ----- | ------ | -------- | ----- |
| 1     | 0x0    | a        | 20    |
| 2     | 0x4    | b        | 30    |
| 3     | 0x8    | \*x      | 0x0   |
| 4     | 0x16   | \*y      | 0x4   |
| 5     | 0x24   | aux      | 20    |
| 6     | 0x8    | \*x      | 30    |
| 7     | 0x16   | \*y      | 20    |

- Qual será o resultado do printf?
  - `a: 30, b: 20`

# Exercício 2

```c
#include <stdio.h>

void func(int *px, int *py) {
  px = py;
  *py = (*py) * (*px);
  *px = *px + 2;
}

int main(){
  int x, y;
  scanf("%d", &x);
  scanf("%d", &y);

  func(&x, &y);

  printf("x - %d, y - %d \n", x, y);

  return 0;
}

```

- Teste de mesa

| Linha | Memóra | Variável | Valor |
| ----- | ------ | -------- | ----- |
| 1     | 0x0    | x        | ####  |
| 2     | 0x4    | y        | ####  |
| 3     | 0x0    | x        | s10   |
| 4     | 0x4    | y        | s20   |
| 5     | 0x8    | \*px     | 0x0   |
| 6     | 0x16   | \*py     | 0x4   |
| 7     | 0x16   | px       | 0x4   |
| 8     | 0x16   | \*py     | 400   |
| 9     | 0x16   | \*px     | 402   |

- "####" são representações de lixo da memória
- o **"s"** antes do valor na linha 3 e 4 representa que este valor foi recebido pela função _scanf_
  - **scanf**: intercepta valores digitados pelo usuário e insere nas variáveis que foram passadas por referência`scanf("%d %d", &x, &y);`
  - sobre a função scanf, note que ela ao contrário do printf, recebe entre aspas o tipo ou tipos que ela irá atribuir a variável passada após as aspas
  - as variáveis são passadas por referência, por conta disso fazemos o uso do _&_
- Qual será o resultado do printf?
  - `x - 10, y - 402`
