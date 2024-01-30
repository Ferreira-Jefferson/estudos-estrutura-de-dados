## 9 Funções - Passagem por Valor

Nesta aula nos é apresentado o conceito de função, o que são, como são definidas, o que são parâmetros, o que é retorno e como informar o tipo de retorno de uma função, essas perguntas são destrinchadas a seguir.

- o que é uma função

  - Uma função é um bloco de código que executa uma tarefa expecífica, podendo retonar um valor e/ou receber parâmetros

- como são definidas

  - Em C a função possui um retorno, um nome e um corpo definido por parênteses "{}" e **pode** receber parâmetros, mas estes não são obrigatórios

- o que são parâmetros

  - Parâmetros são valores que podem influenciar o comportamento e resultado da função

- o que é retorno

  - O retorno é um valor que a função pode retornar para quem a chamou, em C, mesmo que a função não retorne implicitamente um valor é necessário informar o tipo de retorno, neste caso usá-se o tipo void e não se torna obrigatório o uso da palavra reservada _return_

- como informar o tipo de retorno de uma função
  - antes do nome da função é necessário colocar o tipo que ela irá retornar e quando um resultado for obtido é só declarar o ponto de retorno utilizando a palavra reservada _return_

### Exemplos

- A função principal do C

```c
  #include <stdio.h>

  int main(int argc, char *argv[]){
    return 0;
  }
```

- Essa é a primeira e principal função do C, é por ela que todos os programas iniciam, neste trecho são apresentados todos os pontos que uma função possui

  - **int**: _tipo do retorno da função_
  - **main**: _nome da função_
  - **(int argc, char \*argv[])**: parâmetros da função
    - **int**: tipo do primeiro parâmetro
    - **argc**: nome do primeiro parâmetro
    - **char \*argv[]**: tipo e nome do segundo parâmetro
    - **Uma função pode ter _Nenhum_ ou _N_ parâmetros**
  - **{**: _chave de abertura do corpo da função_
  - **return**: _intrução que encerra a função corrente e retorna um valor e/ou o controle para que função que chamou_
  - **0**: valor de retorno da função, na função main o valor _0_ indica que a função rodou corretamente
  - **}**: _chave de fechamento do corpo da função_

- Função sem retorno
  - sem usar return

```c
      #include <stdio.h>

      void minha_funcao(){
        puts("Corpo da função \n");
      }

      int main(){
        minha_funcao();
        return 0;
      }
```

- usando return

```c
      #include <stdio.h>

      void minha_funcao(){
        puts("Corpo da função \n");
        return;
      }

      int main(){
        minha_funcao();
        return 0;
      }
```

- Além dos tipos primitivos, as funções também podem retornar tipos ponteiros, ou mesmo tipos personalizados criados pelo próprio desenvolvedor, mas para isso é necessário fazer a declaração do tipo _static_ ou o alocamento dinâmico utilizando a função _malloc()_, mas como ela ainda não foi apresentada, não será feito um exemplo desse tipo de retorno.
  - é importante lembrar que quando a função retorna, ela e todas as variáveis locais são excluídas _(desalocadas da stack)_, logo o endereço retornado pode apontar para uma região de memória inválida ou já ocupada por outra variável, ou seja, você estará criando um ponto de falha em seu programa.
