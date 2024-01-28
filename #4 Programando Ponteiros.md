## 4 Programando Ponteiros

- Implementação do código apresentado no video 3
- Explica o motivo de não conseguir imprimir o valor que um ponteiro inicalizado como NULL possui
  - Isso ocorre pois o NULL representa "Lugar Nenhum", logo não tem como apresentar algum valor.
  - Quando tentamos mostrar o valor de um ponteiro NULL dá um erro de _Segmentation Fault_
  - De pedir para ver o que há no endereço de memória de uma variável ponteiro que não foi inicializada, não ocorrerá um erro, pois ela conterá um lixo de memória
- neste vídeo é inicado o assunto sobre ponteiro de ponteiros (\*\*), com a seguinte pergunta, dado o seguinte código:
  - int a = 10;
  - int \*p1 = &a;
  - int \*p2 = &p1;
  - Será possível fazer a atribuição do endereço de um ponteiro para uma variável do tipo ponteiro?
    - A responsta é NÃO, pois o \*p2, é do tipo int\*, ou seja ela recebe o endereço para uma variável do tipo int, enquanto o \*p1 possui o tipo int\*, assim como o \*p2, seria o mesmo que fazer a seguinte atribuição: int x = int;
    - O tipo de variável que recebe o endereço de um ponteiro é o (\*\*) e é representado a seguir
      - int \*\*p3 = &p1;
        - lê-se: A variável do tipo ponteiro de ponteiro de inteiro p3, recebe o endereço do ponteiro de inteiro p1
