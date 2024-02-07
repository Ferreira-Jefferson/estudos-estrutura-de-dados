## 2. Introdução a Ponteiros

Neste vídeo, o professor faz uma analogia usando tipo, endereço da casa, morador, valor e carteiro, para falar sobre **ponteiros**.

- **Tipo:** Identificação do que é o morador e do que ele pode conter como valor.
- **Morador:** Variável que contém um valor.
- **Valor:** Valor de uma variável.
- **Endereço da casa:** Endereço de uma variável/morador.
- **Carteiro:** Conhece o endereço do morador, mas não o valor que o morador possui. Além disso, um carteiro só trabalha com o mesmo tipo do morador; se o morador é int, ele também é int.

# Tentando se aproximar mais da programação, seria o seguinte:

- **Tipo:** Tipo (int, float, tipo_criado_pelo_desenvolvedor) que um ponteiro irá apontar.
- **Morador:** Variável que contém um valor; é quem é apontado quando olhamos o endereço da memória que o ponteiro guarda.
- **Valor:** Valor de uma variável; é quem retorna quando pedimos para ver o que a variável contém. Fazemos isso usando o \* antes do nome de uma variável do tipo ponteiro já declarada e que aponta para um endereço de memória.
- **Endereço da casa:** Endereço de memória de uma variável, obtido colocando o & antes do nome da variável.
- **Carteiro:** Ponteiro; guarda o endereço em que uma variável está armazenada no heap, declarado usando o \* antes do nome da variável.

# Usando os símbolos adequados

- **Tipo:** int, float, tipo_criado_pelo_desenvolvedor.
- **Morador:** int **morador**;
- **Valor:** int morador = **20**;
- **Endereço da casa:** int \*end_casa = &morador; **// 0x25df4385**
- **Carteiro:** **end_casa**

**De fato, é meio confuso no começo; vendo o vídeo de analogia fica mais fácil entender o que foi escrito acima.**

# Lembre-se

- O símbolo **&** (E comercial) é usado para retornar um endereço.
- O símbolo **\*** (asterisco) retorna o valor de uma variável em que um ponteiro aponta, mas quando em uma declaração de variável, declara uma variável do tipo ponteiro.
