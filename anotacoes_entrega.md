# Anotacoes da Parte B e Discussao (Unidade 7)

## Questao L4 (Inspecionando os bytes de um int com union)
* **O primeiro byte mostrado na tela e `0x01` ou `0x04`? O que isso revela sobre a arquitetura?**
  O primeiro byte impresso (`u.b[0]`) e **`0x04`**. Isso prova que a maquina segue o padrao **little-endian**, guardando o byte de menor peso (`0x04`) no primeiro endereco da memoria e deixando o byte de maior peso (`0x01`) por ultimo (`u.b[3]`).

## Questao L5 (Analisando padding com sizeof e offsetof)
* **Por que `Ruim` ocupa 12 bytes e `Bom` ocupa 8 bytes mesmo tendo os mesmos campos? Onde fica o padding?**
  * **Na `struct Ruim` (12 bytes):**
    * O campo `a` (`char`, 1 byte) comeca no **offset 0**.
    * Como `b` (`int`, 4 bytes) exige endereco multiplo de 4, o compilador adiciona **3 bytes vazios de padding** nas posicoes **1, 2 e 3**.
    * O campo `b` ocupa do **offset 4 ao 7**.
    * O campo `c` (`char`, 1 byte) entra no **offset 8**.
    * Para fechar a estrutura em um tamanho multiplo de 4 (alinhamento do maior campo), entram mais **3 bytes de padding** nas posicoes **9, 10 e 11**, totalizando **12 bytes**.
  * **Na `struct Bom` (8 bytes):**
    * O campo `b` (`int`, 4 bytes) ja inicia no **offset 0** e vai ate o **3**.
    * O campo `a` (`char`) fica logo depois, no **offset 4**.
    * O campo `c` (`char`) entra na sequencia, no **offset 5**, sem precisar de espaco vazio entre eles.
    * No final entram apenas **2 bytes de padding** (posicoes **6 e 7**) para completar um multiplo de 4, fechando em **8 bytes**.

## Discussao final da unidade
* **Quais erros o compilador barra sozinho e quais dependem de analise de memoria ou execucao?**
  * **Barrados pelo compilador (erro de sintaxe/tipo):**
    * **Item 2:** usar ponto (`.`) em vez de seta (`->`) quando a variavel e um ponteiro de struct.
    * **Item 4:** tentar comparar duas structs inteiras usando `==`.
    * **Item 6:** acessar `c.numero` direto sem passar pela struct interna (`c.ender.numero`).
  * **Identificados apenas entendendo o layout da memoria (compilam sem avisos):**
    * **Item 7:** leitura de apenas 1 byte de um `short int` sobreposto em uma `union`, dependendo da ordem *little-endian*.
    * **Item 8:** gravar um `int` e ler um `float` na mesma `union`, fazendo os mesmos bits serem interpretados no formato IEEE 754.
  * **Gera warning na compilacao e falha ao executar:**
    * **Item 11:** devolver o endereco de uma variavel local (`return &p;`), que gera *warning* no GCC e aponta para memoria invalida da pilha quando o programa roda.
