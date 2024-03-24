## 32 Tipo Abstrato de Dados (Definição)

Tipos abstratos de dados ou TAD são, como o nome evidencia, técnicas para abstrair dados usando tipos, ou seja, criamos um tipo de dados personalizado, para abstrair toda a complexidade de um dados, por exemplo, imaginemos que compramos um drone, ao abri a caixa temos o drone, o controle e o manual; ao lermos o manual entendemos como operar o drone por meio do controle, mas o manual não diz como que o controle se comunica com o drone, apenas que apertando um botão ele liga, movendo a alavanca para um lado ele vai para o lado em questão, isso é abstrair, nós como usuários não queremos saber qual a frequência de onda que é utiliziada para se comunicar com o drone, ou como são feitos os circuitos eletrônicos dentro do controle, apenas nos interessa saber o que acontece ao pressionar cada botão.
Em todo caso é necessário que exista a implementação, mesmo que ele fique oculta ao usuário.

Em resumo, o TAD diz **O que faz** e **não** "Como é feito".

- O **Que** é a expecificação
- O **Como** é a implementação

- O conceito do TAD é similar ao _Encapsulamento_ da POO.

- TAD

  - Para criar um TAD devemos criar dois arquivos com o mesmo nome, mas extensões diferentes, um de especificação com extensão .h e outro com a implementação com extensão .c

  - Especificação (.h)

    - Sintaxe (Assinatura)
      - O que pode ser acessado
        - int soma(int a, int b);
    - Semântica
      - Explicação do que cada coisa faz
        - /** A função soma recebe dois inteiros e retorna a soma deles **/

  - Implementação (.c)

    - Algorítmo
      - Implementação concreta do que a especificação disponibiliza para uso e também de algorítmos auxiliares que não necessariamente estão listados na especificação
        - ```c
            int soma(int a, int b) {
              return a + b;
            }
          ```
    - Representação (Estrutura de dados)
      - Que tipo de dados serão utilizados para criar cada algorítmo
        - int
        - struct
        - vetor

# Como se usa um TAD

- Importamos o TAD por meio de seu cabeçalho (header) que é o arquivo de especificação, ele possui a extensão .h
- A declaração de uso é feito junto aos demais includes, sendo que diferente dos includes de libs padrões, os TADs devem ser declaradas entre aspas
  - Lib padrão: #include <stdio.h>
  - TAD: #include "minha_tad.h"

# Vantagens do TAD

- Reutilização

  - Não é necessário criar toda uma estrutura a cada vez que precisar de algo, já está criado e abstraído é só usar
    - Todo trecho que precisar fazer uma soma não preciso fazer `x = a + b;`, é só usar `x = soma(a, b);`.

- Manutenabilidade

  - Como o código está em um único lugar é necessário ajustar ou manter apenas um lugar o que evita bugs e trabalhos repetitivos.

- Corretude
  - É mais fácil testar o código tendo em vista que ele se encontra em apenas um lugar.
  - Como ele é utilizado em diversos contextos é fácil perceber inconsistências caso existam.
