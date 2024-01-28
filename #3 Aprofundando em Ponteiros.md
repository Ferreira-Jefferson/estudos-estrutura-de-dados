## 3 Aprofundando em Ponteiros

Neste vídeo o professor mostra na prática o que foi introduzido no vídeo anterior.

- É explicado que um ponteiro ocupa 8 bytes, independente do tipo que ele aponta, segundo o chatGPT, isso ocorre em sistemas com arquitetura 64bits, já em sistemas com arquitetura 32bits um ponteiro ocupa 4bytes independente do tipo que ele aponta.
- Assim como uma variável normal, uma variável do tipo ponteiro, quando não atribuído um valor em sua declaração, conterá lixo de memória, o que pode ocasionar bugs, _é indicado inicializar as variáveis do tipo ponteiro com NULL_.
- **NULL** é uma palavra reservada da linguagem C que aponta para o nada.

O vídeo é mais _hands-on_, então segue um código para análise e estudo.

```c
#include <stdio.h>

int main(){
  int var_normal = 10;
  int *var_ponteiro_lixo;
  int *var_ponteiro_null = NULL;

  printf("&var_normal: %p | var_normal: %i \n", &var_normal, var_normal);
  printf("&var_ponteiro_lixo: %p | var_ponteiro_lixo: %p \n", &var_ponteiro_lixo, var_ponteiro_lixo);
  printf("&var_ponteiro_null: %p | var_ponteiro_null: %p \n\n", &var_ponteiro_null, var_ponteiro_null);

  var_ponteiro_lixo = &var_normal;
  var_ponteiro_null = var_ponteiro_lixo;
  printf("&var_normal: %p | var_normal: %i \n", &var_normal, var_normal);
  printf("&var_ponteiro_lixo: %p | var_ponteiro_lixo: %p | *var_ponteiro_lixo: %i\n", &var_ponteiro_lixo, var_ponteiro_lixo, *var_ponteiro_lixo);
  printf("&var_ponteiro_null: %p | var_ponteiro_null: %p | *var_ponteiro_null: %i \n\n", &var_ponteiro_null, var_ponteiro_null, *var_ponteiro_null);

  *var_ponteiro_null = 50;
  printf("&var_normal: %p | var_normal: %i \n", &var_normal, var_normal);
  printf("&var_ponteiro_lixo: %p | var_ponteiro_lixo: %p | *var_ponteiro_lixo: %i\n", &var_ponteiro_lixo, var_ponteiro_lixo, *var_ponteiro_lixo);
  printf("&var_ponteiro_null: %p | var_ponteiro_null: %p | *var_ponteiro_null: %i \n\n", &var_ponteiro_null, var_ponteiro_null, *var_ponteiro_null);

  return 0;
}

// ### Note que neste primeiro bloco NÃO FOI POSSÍVEL IMPRIMIR o valor de *var_ponteiro_lixo e *var_ponteiro_null ###
// &var_normal: 0x7ffd818273f4 | var_normal: 10
// &var_ponteiro_lixo: 0x7ffd818273f8 | var_ponteiro_lixo: (nil)
// &var_ponteiro_null: 0x7ffd81827400 | var_ponteiro_null: (nil)

// &var_normal: 0x7ffd818273f4 | var_normal: 10
// &var_ponteiro_lixo: 0x7ffd818273f8 | var_ponteiro_lixo: 0x7ffd818273f4 | *var_ponteiro_lixo: 10
// &var_ponteiro_null: 0x7ffd81827400 | var_ponteiro_null: 0x7ffd818273f4 | *var_ponteiro_null: 10

// &var_normal: 0x7ffd818273f4 | var_normal: 50
// &var_ponteiro_lixo: 0x7ffd818273f8 | var_ponteiro_lixo: 0x7ffd818273f4 | *var_ponteiro_lixo: 50
// &var_ponteiro_null: 0x7ffd81827400 | var_ponteiro_null: 0x7ffd818273f4 | *var_ponteiro_null: 50

```
