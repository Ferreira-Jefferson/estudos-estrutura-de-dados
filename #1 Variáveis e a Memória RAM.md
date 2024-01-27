## 1 Variáveis e a Memória RAM

Nesta aula é explicado o como um tipo de dado interage com a memória RAM do computador

- Cada tipo de dado tem um tamanho, o int por exemplo ocupa 4 bytes
- Cada 1 byte equivale a 8 bits(0,0,0,0,0,0,0,0), logo 4 bytes ocupam 32 bits (4x8)
- Um ponto interessando citado é que existem dois tipos de organização de bytes, as chamadas **endianness**, são elas _LittleEndian_ e _BigEndian_, onde em resumo a LittleEndian armazena da direita para a esquerda e a BigEndian da esquerda para a direita (como lemos normalmente).
  - Byte de referência: 12345678
  - BigEndian: 12345678
  - LittleEndian: 87654321
  - **É importante notar que este conceito se aplica a bytes, já com relação a bits eles são sempre armazenados como _BigEndian_**
  - Link de um vídeo que explica bem este conceito -> [Big Endian e Little Endian em Programação](https://youtu.be/ggz24JKI0VQ?si=oiDn_Kr28Pku0tn2)
- Sempre que alocamos um espaço de memória, recebemos o endereço base, que é o primeiro endereço que a variável ocupa, e o computador sabendo o tamanho que aquele tipo de dado ocupa, consegue gerenciar onde está disponível para alocar um outro valor.
  - Tipo int = 4 bytes
  - Endereço base = 0x7ffe81d4a4d0
  - Próximo endereço disponível: End. base(0x7ffe81d4a4d0) + tamanho int (4 bytes) = 0x7ffe81d4a4d4
  - Perceba que o endereço de memória é um valor hexadecimal
    - Se convertermos os dois últimos dígitos para decimal temos [d0 = 208] e [d4 = 212] -> [conversor Hex para Dec](https://www.to-convert.com/pt/numero/converter-hexadecimal-para-decimal.php)
- Quando declaramos um valor estático (int x=10), ela é adicionada diretamente à _stack_, quando adicionamos um valor dinámico (int \*valor = {x=10}), um ponteiro\* é adicionado na stack e este ponteiro aponta para o endereço na memória _heap_ em que o valor se inicia.
  - Explicação sobre memória stack e heap -> [Memória Stack e Heap, tudo o que você precisa saber...](https://www.youtube.com/watch?v=Qve5f-PgQ18)
- Quando não atribuímos um valor a uma variável, ela poderá conter "lixos de memória", que são valores residuais do local em que aquela variável foi referenciada, _é importante se atentar a isso para não usar um valor que não foi o programa que atribuiu_.
- Uma variável possui um nome, um tipo, um valor e um endereço
  - para pegar o endereço de uma varíavel é usado o & (E comercial), antes do nome da variável
  - Ex: int nome_variavel = 50;
    - nome = nome_variavel
    - tipo: int = inteiro
    - valor: printf("%i", nome_variavel) = 50
    - endereco: printf("%p", &nome_variavel) = 0x123456789 _(endereço fictício)_

```c
#include <stdio.h>

int main(){
  int a = 10;
  int b, c;

  printf("&a = %p | a = %i \n", &a, a);
  printf("&b = %p | b = %i \n", &b, b);
  printf("&c = %p | c = %i \n\n", &c, c);

  b = 20;
  c = a + b;

  printf("&a = %p | a = %i \n", &a, a);
  printf("&b = %p | b = %i \n", &b, b);
  printf("&c = %p | c = %i \n", &c, c);

  return 0;
}

// Obs: os endereços de memória irão mudar
// &a = 0x7ffe5be78ecc | a = 10
// &b = 0x7ffe5be78ed0 | b = 0
// &c = 0x7ffe5be78ed4 | c = 0

// &a = 0x7ffe5be78ecc | a = 10
// &b = 0x7ffe5be78ed0 | b = 20
// &c = 0x7ffe5be78ed4 | c = 30

```
