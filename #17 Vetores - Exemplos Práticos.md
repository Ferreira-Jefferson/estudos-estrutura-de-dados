## 17 Vetores - Exemplos Práticos

# Vetor Estáticos

```c
#include <stdio.h>
#include <stdlib.h>

void print_vetor(const int *v, int len, char *tipo)  {
    printf("Recebe via %s \n", tipo);
    printf("Enderecos: &v = %p | v = %p | &v[0] %p \n", &v, v, &v[0]);
    for(int i=0; i < len; i++) {
        printf("v[%d] = %d\n", i,v[i]);
    }
    puts("");
}

void print_vetor_via_ponteiro(const int *v, int len) {
    char tipo[] = "Ponteiro";
    print_vetor(&*v, len, tipo);
}

void print_vetor_via_colchetes(const int v[], int len) {
    char *tipo = "Colchetes";
    print_vetor(v, len, tipo);
    puts("");
}

int main() {
    int v[5] = {1,2,3,4,5};

    printf("Endereco na Main: %p \n\n", &v);
    print_vetor_via_ponteiro(&v[0], 5);
    print_vetor_via_colchetes(&v, 5);
    return 0;
}
```

# Vetor dinâmico

```c
#include <stdio.h>
#include <stdlib.h>

void print_vetor(const int *v, int len, char *tipo)  {
    printf("Recebe via %s \n", tipo);
    printf("Enderecos: &v = %p | v = %p | &v[0] %p \n", &v, v, &v[0]);
    for(int i=0; i < len; i++) {
        printf("v[%d] = %d\n", i,v[i]);
    }
    puts("");
}

void print_vetor_via_ponteiro(const int *v, int len) {
    char tipo[] = "Ponteiro";
    print_vetor(&*v, len, tipo);
}

void print_vetor_via_colchetes(const int v[], int len) {
    char *tipo = "Colchetes";
    print_vetor(v, len, tipo);
    puts("");
}

int main() {
    int *v = calloc(5, sizeof(int));
    *v = 10;
    v[1] = 20;
    *(v+2) = 30;
    *(*&v+3) = 40;
    *&*(*&v+4) = 50;

    printf("Endereco na Main: %p \n\n", &v);
    print_vetor_via_ponteiro(&v[0], 5);
    print_vetor_via_colchetes(v, 5);

    free(v);
    v = NULL;
    return 0;
}
```

- Sempre que alocamos um ponteiro dinâmicamente, devemos desalocar usando free()
- É uma boa prática apontar o ponteiro para NULL após desalocar
- O uso da palavra reservada conte na declaração dos parâmetros das funções é uma boa prática para evitar bugs, tendo em vista que as funções devem apenas imprimir e não alterar o valor dos vetores e/ou ponteiros
