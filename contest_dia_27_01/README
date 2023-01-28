# Solução do contest "Brazilian ICPC Summer School 2023 - BF - Jan 27"

Contest: https://vjudge.net/contest/539990

## A - Missing Number

<details>
<summary><b>Solução</b></summary>

0. Inicialmente estou em dúvida em todos os números de 0 até n.

1. Vou contar quantos número de 0 até N tem o 1º bit setado e quantos não tem, chamo isso de b1 e b0.

2. Agora, vou pegar as posições que tenho dúvida e peguntar se o 1º bit é 1 ou 0, e contar quantos são 1 e quantos são 0, sendo a1 e a0.

3. Se a quantidade a1 = b1, então posso descarta todos o cara que tem o 1º bit 1. Senão posso descartar todos os números que tem o 1º bit 0. Com isso, minha dúvida diminue pela metade.

4. Repetir o mesmo processo (1, 2, 3) para os outros bits até ficar só 1 elemento.

</details>

## B - Do Not Try This Problem 

<details>
<summary><b>Solução</b></summary>

Para resolver essa questão você vai usar SQRT Decomposition. 

Se $a > \sqrt n$ então você pode fazer isso iterando pelo vetor e guardando uma tupla (O momento do update, o novo caracter) em um vetor V.

Caso contrário, você pode dividir em blocos de tamanho $\sqrt n$ e block[x][y][z]: 
- x: O id do bloco que diz respeito as posições de x*a até (x+1) * a - 1
- y: Posição que começo a mudança no bloco
- z: tamanho do pulo

block[x][y][z] tbm guarda a mesmo tupla.

Então para consultar a resposta de uma posição i, você precisa consulta o V[i] e procurar no block[][][] quais posições pode ter alguma informação sobre i. Vai tem que olhar em apenas $\sqrt n$ lugares.

Então a complexidade final fica: $O(N * \sqrt N)$

</details>

## C - Distinct Characters Queries

<details>
<summary><b>Solução</b></summary>

Podemos criar 26 BIT ou 26 Segtree, uma para cada caractere. E ai essa estrutura vai responder quantos ocorrência daquele caracter tem no range. 

A atualização é equivalente a remover de um e adicionar em outra.

Complexidade: $O(N*log(N)*26)$

</details>

## D - Tree Painting

<details>
<summary><b>Solução</b></summary>

resposta = (Quantidade de folhas + 1)/2

</details>

## E - 2-3-4 Tree

<details>
<summary><b>Solução</b></summary>

Basecamente implementar o que foi pedido. Questão muito chata de implementar.

</details>


## F - Palindromization

<details>
<summary><b>Solução</b></summary>

Resolvendo com DP. A solução dp(i, j, e). $i$ é o lado esquerdo e $j$ o lado direito.
$e = 1$ diz que já pulei alguém do lado esquerdo e $e = 2$ diz que já pulei alguém do lado direito. $e = 0$ não pulei ninguém.

Observação: para memorizar, só precisamos usar ($i$, $e$). O $j$ pode ser derivável a partir da combinação de $i$ e $e$.

Complexidade $O(N)$
</details>


## G - NCD Salary

<details>
<summary><b>Solução</b></summary>

Solução precisa aplicar log para evitar geração de um número muito grande. 

$ a^b = c^d $ -> $ log(a^b) = log(c^d) $ -> $ b*log(a) = d*log(c) $

Além disso, precisa lidar com erro de precisão e tratar os casos com 0.


</details>

## H - Pavels Party

<details>
<summary><b>Solução</b></summary>

Você pode fazer um swipe line. Cada pessoa vai tem o tempo de entrada ai e saida bi. 

Agora vamos manter uma BIT e fazer um laço i de 1 até j. E para cada i, vamos fazer:
- Inserir na BIT todo mundo com ai = i.
- Calcular a primeira posição da bit cuja a soma de prefixo é igual a i e printar na tela.
- Remove todo mundo que bi = i.

</details>

## I - Akinator

<details>
<summary><b>Solução</b></summary>

Comentário com a solução: https://codeforces.com/blog/entry/67178?#comment-513421

</details>

## J - Amazon

<details>
<summary><b>Solução</b></summary>

Nessa questão o que importa é apenas a inclinação das retas. Podemos fazer essa questão usando apenas inteiros. Se fizermos a equação da reta (ax + by + c = 0) e normalizar ela, o coeficiente a e b da reta, como um vetor (a, b), representa o vetor normal da reta. 

Agora, basta manter um map de pair, para contar a frequência de cada ângulo. E depois podemos ver dado um vetor (a, b), qual a frequência rot((a,b), +90) e rot((a, b), -90), onde o rot representa a rotação. Isso vai significar as intersecções de 90 grau.

OBS: precisa remover as retas repetidas.

Complexidade O(N * log(N)).

</details>


## K - Adnan and the Burned drivers

<details>
<summary><b>Solução</b></summary>

Para resolver essa questão bastar usar segtree. O segredo está na função de junção. Em cada nó guardamos o valor da hash da esquerda para direita e da direita para esquerda. Para saber se é palíndromo, basta ver se as duas hash são iguais.

Complexidade O(N * log(N))

Essa solução poderia ser usada para resolver a F.

</details>

## L - Lexicographically Minimal Shortest Path

<details>
<summary><b>Solução</b></summary>

Primeiramente, você vai precisar de 2 BFS. Uma partindo de 1 e outra de n. Agora, você vai precisar montar o menor caminho lexicográfico. 

O problema é, se você tem duas opções com o mesmo caracter que vai para um caminho mínimo, 
como saber quem pegar? Exemplo:

```
4 4
1 2 a
2 3 b
1 4 a
4 3 b
```

Para saber se uma aresta faz parte do caminho mínimo, basta ver se a dist[1][u] + 1 + dist[v][n] é igual a distância mínima.

Com isso, a ideia é ir mantendo todo mundo que é possível no vetor curr. E ver qual gera a melhor opção. Os que geram a melhor opção vai ser o próximo curr. E vamos fazendo isso até chegar no vértice N. Como se fosse um outra BFS que só anda pela aresta de menor caracter.

</details>

## M - Vasiliys Multiset

<details>
<summary><b>Solução</b></summary>

Você pode montar uma trie de bits. Para maximizar a xor, você vai tentando maximizar de forma gulosa, começando pelo maior bit. Para isso, você sempre que possível, tentar ir para o lado contrário ao bit do número da query. Assim, no final, você vai maximizar a resposta.

Complexidade O(N * log(MAXA))

</details>