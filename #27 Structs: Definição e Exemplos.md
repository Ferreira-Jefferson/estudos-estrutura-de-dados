## 27 Structs: Definição e Exemplos

- Struct ou registro é um "pacote" de variáveis que pode conter tipos diferentes, tem como objetivo agrupar um conjunto de dados que represente algo mais concreto
- Em última análise a struct é um novo tipo de dados que nós mesmos criamos, um tipo de dados personalizado, que ao invés de receber apenas um valor como `int x = 10;`, pode receber **N** valores.

  - Ex: Uma pessoa tem diversos atributos como nome, idade, peso, cada um desses atributos se representados no código deveria ser armazenado em uma variável de tipo diferente.
    - nome: char[]
    - idade: int
    - peso: double
  - para apenas um dado fazer dessa maneira não teria maiores problemas, mas se tivermos duas pessoas, teríamos que declarar novas variáveis e como elas não poderiam ter o mesmo nome, teriam que ser criadas abordagem de nomenclatura para não se perder nos nomes das variáveis:

    ```
      char nome_pessoa1[];
      int idade_pessoa1;
      double peso_pessoa1;

      char nome_pessoa2[];
      int idade_pessoa2;
      double peso_pessoa2;
    ```

  - Como pode ser observado, quando mais dados temos que representar, mais teríamos que criar novas variáveis e é para que isso não ocorra que usamos as structs

- A criação de uma struct segue o seguinte padrão

---

```
struct ?nome_struct {
  tipo_atributo1 nome_atributo1;
  ?tipo_atributo2 nome_atributo2;
} ?variavel_1, ?variavel_2;
```

---

- O criação da struct é feito da seguinte maneira
  `struct nome_struct nome_variavel;`

- O uso da struct é feito utilizando ponto (**.**)

  ```
  struct nome_struct nome_variavel;
  nome_variavel.atributo;
  ```

  - ⚠️: o uso do ponto é feito quando a struct é declarada de maneira estática, quando declaramos uma struct dinâmica, usamos seta (**->**)

- Atribuição de valores durante a alocação estática

  ```
  struct nome_struct nome_variavel = {.atributo1 = "valor", .atributo2 = 10};
  ```

  - entre chaves, usamos o ponto seguido do nome do atributo
  - a separação dos atributos é feita utilziando vírgula
  - atributos do tipo char[] podem ser atribuídos diretamente

- Note que alguns nomes começam com o ponto de interrogação (?), eles são campos opcionais

  - ?nome_struct: uma struct não necessariamente precisa ter um nome, ela pode ser uma struct anônima, neste caso é necessário criar ao menos uma variável, ela até pode ser útil em algumas situações, mas não e muito utilizada pelo fato de que você não consegue reutilizá-la, a única variável que terá seu tipo será a variável ou as variáveis definida em sua criação.

    ```
    struct {
      int quantidade;
      double valor;
    } produto_x;

    produto_x.quantidade = 10;
    produto_x.valor = 50.5;
    ```

    - Note que produto_x não é o nome da struct, mas sim a variável de uma struct anônima, logo seu uso é direto.

  - ?tipo_atributo2 nome_atributo2: apesar de uma struct ser criada para agrupar atributos comuns de algo, ela também pode ser criada com apenas uma atributo.

  ```
    struct Money {
      double valor;
    } dimdim;

    struct Money bufunfa;

    dimdim.valor = 23.2;
    bufunfa.valor = 10.5;
  ```

  - Note que neste exemplo a struct foi nomeada como _Money_, logo ela pode ser usada como tipo de outras variáveis que não foram declaradas no momento de criação da struct
  - ?variavel_1, ?variavel_2: o uso da declaração de variáveis no momento da criação da struct é muito útil em alguns caso, entretanto isso não é obrigatório, além disso, se necessário podem ser declaradas N variáveis no momento da criação de uma struct

  ```
  struct Aluno {
    char nome[50];
    double nota;
    int idade;
  }

  struct Animal {
    int idade;
    double peso;
  } cao, gato;

  struct Aluno pedrinho = {.nome = "Pedro", .nota = 4.5, .idade = 12};

  cao.idade = 2;
  cao.peso = 12.5;

  gato.idade = 3;
  gato.peso = 5.6;

  struct Animal vaca;
  vaca.idade = 15;
  vaca.peso = 400.8;
  ```

  - Note que cao e gato são variáveis declaradas na criação da struct e além delas a struct também pode ser usada para criar novas variáveis

- A struct nos dá muita liberdade para trabalhar com diversos dados de um mesmo tipo e reduz bastante o código e variáveis criadas, porém ela ainda pode ser melhorada, perceba que em toda declaração de variável estamos usando a palavra reservada _struct_ antes do nome da struct, isso pode ser contornado definindo a struct como um tipo de dados e dando um apelido (alias) à struct.

  ```
    typedef struct _aluno {
      double nota;
      int idade;
    } Aluno;
  ```

  - typedef: define a struct como um tipo de dados
  - \_aluno: nome da struct, o underline (**\_**) não é obrigatório, mas é uma convenção para desentimular o uso da struct da maneira padrão `struct nome_struct`
  - Aluno: alias ou apelido da struct, é ele que iremos querer usar na declaração das variáveis
    - ⚠️: Quando usamos o typedef todos os nomes que colocamos após a última chave da struct (**}**), não são variáveis, mas sim alias da struct, sendo que podemos declarar **N** alias diferentes para uma mesma struct
      ```
        typedef struct _aluno {
          double nota;
          int idade;
        } Aluno, Formando, Graduando;
      ```
  - **Uso**: Agora que a struct foi definida como um tipo de dado, podemos declarar novas variáveis utilizando apenas seus Alias
    - É possível usar também a maneira convencional, porém isso deve ser desestimulado para que o projeto siga o mesmo padrão

  ```
    typedef struct _aluno {
      char nome[50];
      double nota;
      int idade;
    } Aluno, Formando, Graduando;

    Aluno pedro;
    Aluno paulo = {.nome = "Paulo", .nota = 10, .idade = 18};
    Formando Maria;
    Graduando jose;

    struct _aluno zezinho; // Desestimulado: O ideal é seguir o padrão e usar somente os alias
  ```

- Outra maneira de utlizar o typedef é para tornar struct anônimas em structs que podem ser reutilizadas, além de eliminar o uso de convenções para informar que algo é opcional ou que não deve ser usado.

  ```
    typedef struct {
      char nome[50];
      double nota;
      int idade;
    } Aluno;

    Aluno pedro;
    Aluno paulo = {.nome = "Paulo", .nota = 10, .idade = 18};
  ```
