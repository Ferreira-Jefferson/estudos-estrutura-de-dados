## 4. Programando Ponteiros

- Implementação do código apresentado no vídeo 3.
- Explica o motivo de não conseguir imprimir o valor que um ponteiro inicializado como NULL possui.
  - Isso ocorre porque o NULL representa "Lugar Nenhum", logo não tem como apresentar algum valor.
  - Quando tentamos mostrar o valor de um ponteiro NULL, dá um erro de _Segmentation Fault_.
  - Ao pedir para ver o que há no endereço de memória de uma variável ponteiro que não foi inicializada, não ocorrerá um erro, pois ela conterá um lixo de memória.
- Neste vídeo, é iniciado o assunto sobre ponteiro de ponteiros (\*\*), com a seguinte pergunta:
  - Dado o seguinte código:
    - int a = 10;
    - int \*p1 = &a;
    - int \*p2 = &p1;
    - Será possível fazer a atribuição do endereço de um ponteiro para uma variável do tipo ponteiro?
    - A resposta é NÃO, pois o \*p2 é do tipo int\*, ou seja, ele recebe o endereço para uma variável do tipo int, enquanto o \*p1 possui o tipo int\*. Seria o mesmo que fazer a seguinte atribuição: `int x = int;`
    - O tipo de variável que recebe o endereço de um ponteiro é o (\*\*) e é representado da seguinte forma: ` int **p3 = &p1;`
      - Lê-se: A variável do tipo ponteiro de ponteiro de inteiro p3 recebe o endereço do ponteiro de inteiro p1.
