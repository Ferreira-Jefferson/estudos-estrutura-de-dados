## 7 Mão na massa: Ponteiro de Ponteiros

Neste vídeo além do professor repassar com exemplos no código o conceito de ponteiros para ponteiros, ele nos faz uma provocação a cerca do resultado dos seguintes códigos:

```c
#include <stdio.h>

int main(){
  float a = 10.5;
  float *p = &a;

  printf("*&a: %f \n", *&a);
  printf("*p: %f \n", *p);
  printf("**&p: %f \n", **&p);
  return 0;
}
```

- Este código compila?
- Se compila: Ele roda?
- Se roda: Qual o retorno de cada linha?
- Com base nas análises anteriores, qual seria o resultado de &\*a ?
