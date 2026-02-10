# Ponderada (DHT) em C++

Este projeto implementa uma Distributed Hash Table (DHT) simples, inspirada no protocolo Kademlia, com o objetivo de demonstrar de forma didática os conceitos de armazenamento distribuído.

A aplicação simula uma rede de nós localmente, onde cada nó possui um identificador único. As chaves são armazenadas no nó cuja distância XOR em relação à chave é a menor, conceito central do Kademlia.

## Como executar

O projeto foi executado no Replit utilizando o template C++.

Basta colar o código no arquivo `main.cpp` e clicar em "Run".

## Tecnologias
- C++
- Replit

---

## Exemplo de Execução

Abaixo está um exemplo da saída gerada ao executar o programa:

```
Nó 10 adicionado 
Nó 40 adicionado 
Nó 90 adicionado
Chave 'arquivo1' armazenada no nó 40 
Chave 'arquivo2' armazenada no nó 40
Valor encontrado: dados do arquivo 1 
Valor encontrado: dados do arquivo 2 
Chave não encontrada
```

Essa saída demonstra a criação dos nós da DHT, o armazenamento de chaves utilizando a distância XOR e a recuperação de valores, incluindo o tratamento de uma busca por chave inexistente.
