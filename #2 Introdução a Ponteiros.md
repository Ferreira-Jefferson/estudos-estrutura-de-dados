## 2 Introdução a Ponteiros

Neste vídeo o professor faz uma analogia usando tipo, endereço da casa, morador, valor e carteiro, para falar sobre **ponteiros**

- tipo: identificação do que é o morador e do que ele pode conter como valor
- morador: variável que contém um valor
- valor: valor de uma variável
- endereço da casa: endereço de uma variável/morador
- carteiro: conhece o endereço do morador, mas não o valor que o morador possuia, além disso, um carteiro só trabalha com o mesmo tipo do morador, se o morador é int, ele também é int.

# Tentando se aproximar mais da programação, seria o seguinte:

- tipo: tipo(int, float, tipo_criado_pelo_desenvolvedor) que um ponteiro irá apontar
- morador: variável que contém um valor, é quem é apontado quando olhamos o endereço da memória que o ponteiro guarda
- valor: valor de uma variável, é quem retorna quando pedimos para ver o que a variável contém, fazemos isso usando o \* antes do nome de uma variável do tipo ponteiro já declarada e que aponta para um endereço de memória
- endereço da casa: endereço de memória de uma variável, obtido colocando o & antes do nome da variável
- carteiro: ponteiro, guarda o endereço em que uma variável está armazenada no head, declarado usando o \* antes do nome da variável

# Usando os símbolos adequados

- tipo: int, float, tipo_criado_pelo_desenvolvedor
- morador: int **morador**;
- valor: int morador = **20**;
- endereço da casa: int \*end_casa = &morador; **// 0x25df4385**
- carteiro: **end_casa**

**De fato é meio confuso no começo, vendo o vídeo de analogia fica mais fácil entender o que foi escrito acima**

# Lembre-se

- o símbolo **&** (E comercial) é usado para retornar um endereço
- o símbolo **\*** (asterísco), retorna o valor de uma variável em que um ponteiro aponta, mas quando em uma declaração de variável, declara uma variável do tipo ponteiro
