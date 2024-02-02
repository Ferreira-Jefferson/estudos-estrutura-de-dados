## 14 Vetores e Aritmética de Ponteiros

Nesta aula é explicado no detalhe como funciona a Aritmética de Ponteiros, começamos revendo alguns conceitos

- Um vetor parece um ponteiro, mas não é, isso pq ele não possui um endereço próprio
- &v == &v[0] == v
- O nome da variável vetor aponta para o endereço do primeiro elemento, que também é seu próprio endereço

```c
 #include <stdio.h>

 int main(){
   int v[5] = {2};

    printf("\n&v: %p, &v[0]: %p v: %p \n", &v, &v[0], v);
    printf("\n*&v: %d, *&v[0]: %d *v: %d \n", *&v[0], *v, v[0]);

   return 0;
 }

// &v: 0x7fff4ae96110, &v[0]: 0x7fff4ae96110 v: 0x7fff4ae96110
// *&v: 2, *&v[0]: 2 *v: 2
```

# Aritmética de Ponteiros

- Referência: `int v[5] = {10, 20, 30, 40, 50}`

- Forma simples 01: `*(v + 3) = 40`
- Forma simples 02: `*(&v[0] + 3) = 40`

- A Aritmética de Ponteiros nada mais é que cálculos aritméticos básicos normais (+,-), só que quando o sistema identifica que está sendo feito com um ponteiro, ele considera o número como quantidade de bytes do tipo do ponteiro, ou seja o número **3** é entendido como 3 unidades de inteiro

- Calcule o endereço para ir no índice 3 e apresente seu valor, como o sistema faria
- Calculando na mão:

  - A aritmética começa identificando o endereço inicial do vetor
    - O endereço inicial seja representado por **#x000**, mas no sistema, este é um valor héxadecimal
  - É necessário saber o tipo de dado que o vetor contém
    - Tipo do vetor: Inteiro
  - Descobrir qual o tamanho de bytes que o tipo do vetor ocupa
    - Tamanho de um inteiro: 4 bytes
  - Multiplicar o índice que se deseja ir pelo tamanho de bytes do tipo do vetor
    - índice deseja: 3
    - Tamanho do byte de um int: 4
    - resultado: 3 \* 4 = 12 (bytes)
  - Somar a quantidade de bytes com os bytes do endereço inicial
    - Endereço inicial: #x000
    - Quantidade de bytes até o índice 3: 12 bytes
    - Endereço do valor no índice 3: #x000 + 12 = #x012
  - Apresentar valor como o sistema
    - Endereço desejado: #x012
    - `\*(#x012) = 40`

- ⚠️: Não é possível fazer `*(&v + 3) = 40`
- Em resumo, isso ocorre por conta do vetor não ser um ponteiro, apesar da estranheza inicial fica óbvio quando nos damos conta que _&v_ é o endereço do vetor
  - \*(v + 3): _v_ é o ponteiro para um primeiro valor do vetor + 3 tamanhos de inteiro
  - \*(&v[0] + 3): _v[0]_ é novamente o ponteiro para um primeiro valor do vetor + 3 tamanhos de inteiro
  - \*(&v + 3): **_&v_ é o endereço do vetor, logo ele aponta para um ponteiro de vetor de inteiro e tenta somar + 3 tamanhos de vetor de inteiro**
