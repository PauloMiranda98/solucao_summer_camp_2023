# Solução do contest "Brazilian ICPC Summer School 2023 - BF - Jan 28"

Contest: https://vjudge.net/contest/539994

## A - Just Two Functions

<details>
<summary><b>Solução</b></summary>
Podemos resolver usando exponenciação de matrizes.

$$
\begin{vmatrix}
f(n) \\ 
f(n-1) \\ 
f(n-2) \\ 
g(n) \\ 
g(n-1) \\ 
g(n-2)
\end{vmatrix} 

=

\begin{vmatrix}
a_1 & b_1 & 0 & 0 & 0 & c_1 \\ 
1 & 0 & 0 & 0 & 0 & 0 \\ 
0 & 1 & 0 & 0 & 0 & 0 \\ 
0 & 0 & c_2 & a_2 & b_2 & 0 \\ 
0 & 0 & 0 & 1 & 0 & 0 \\ 
0 & 0 & 0 & 0 & 1 & 0
\end{vmatrix}
*
\begin{vmatrix}
f(n-1) \\ 
f(n-2) \\ 
f(n-3) \\ 
g(n-1) \\ 
g(n-2) \\ 
g(n-3)
\end{vmatrix} 
$$

$$
\begin{vmatrix}
f(n) \\ 
f(n-1) \\ 
f(n-2) \\ 
g(n) \\ 
g(n-1) \\ 
g(n-2)
\end{vmatrix} 

=

\begin{vmatrix}
a_1 & b_1 & 0 & 0 & 0 & c_1 \\ 
1 & 0 & 0 & 0 & 0 & 0 \\ 
0 & 1 & 0 & 0 & 0 & 0 \\ 
0 & 0 & c_2 & a_2 & b_2 & 0 \\ 
0 & 0 & 0 & 1 & 0 & 0 \\ 
0 & 0 & 0 & 0 & 1 & 0
\end{vmatrix} ^ {n-2}
*
\begin{vmatrix}
f(2) \\ 
f(1) \\ 
f(0) \\ 
g(2) \\ 
g(1) \\ 
g(0)
\end{vmatrix} 
$$
</details>

## B - Sorting Colored Array

<details>
<summary><b>Solução</b></summary>

Para resolver o problema basta verificar se os elementos de mesma cor estão ordenados. Caso contrário vai ser impossível ordernar eles.

</details>

## C - Marbles

<details>
<summary><b>Solução</b></summary>

Vamos precisar interpretar o jogo de uma outra forma. Vamos dizer que se um jogado colocar uma bola de gude na diagonal principal, na linha 0 ou na coluna 0, ele vai perder. Com isso, temos um jogo mais parecido com NIM. Agora, basta calcular o número de Grundy para cada bola e depois faz a xor de todos.

OBS: você precisa tratar o caso que a bola de gude já começa na diagonal, na linha 0 ou na coluna 0.

</details>

## D - Text Editor

<details>
<summary><b>Solução</b></summary>

Essa questão pode ser feita usando função z. Primeiro concatenamos s + "#" + t. Aplicamos a função z e contamos a frequência de cada valor da função z que diz respeito ao texto t. 

Se tinha um prefixo de tamanho x na posição i, então vai ter um prefixo de tamanho x-1 também. Então, se pegarmos a soma do vetor de frequência no intervalo [x..maxX], temos a quantidade de vezes que o prefixo de tamanho x apareceu. 

Desafio: fazer com KMP.

</details>


## E - Graph Coloring

<details>
<summary><b>Solução</b></summary>

Esse problema podemos resolver usando gauss. Primeiro montamos o sistema linear. Após isso, descobrimos quantas variáveis são linearmente dependentes, sendo esse valor L. Com isso, temos que a solução é $K^L$.

</details>

## F - Environment-Friendly Travel 

<details>
<summary><b>Solução</b></summary>

Para resolver esse tipo de problema, podemos passar algumas restrições para o vértice. Então, ao invés de ter um vértice representado por (x, y), podemos ter um vertice representado por (x, y, k), onde k é a quantidade de km já usado. Com isso, podemos usar o Dijkstra normalmente.

</details>

## G - River Game 

<details>
<summary><b>Solução</b></summary>

Nesse problema, você primeiro vai resolver cada área molhada de forma independente. Como eles estão a distância 3, eles são jogos totalmente independentes. Para resolver cada area molhada, basta fazer de forma recursiva (dado que o N é pequeno), e aplicar o Grundy Number.

</details>

## H - Safe Path

<details>
<summary><b>Solução</b></summary>

Primeiro você vai rodar uma BFS para marcar as posição que são perigosas. Esse BFS precisa ser Multi-Source. Após isso, basta rodar uma BFS normal que não passe por posições perigosas.

</details>

## I - Apple Trees

<details>
<summary><b>Solução</b></summary>

Como o gcd(10, 45) é 5. Temos que F(a) = F(b) para todo a/5 = b/5 (divisão inteira). Então vamos focar em calcular F(n).

$$
\begin{vmatrix}
f(n) \\ 
f(n-5) \\ 
f(n-10) \\ 
f(n-15) \\ 
f(n-20) \\ 
f(n-25) \\
f(n-30) \\
f(n-35) \\
f(n-40)
\end{vmatrix} 

=

\begin{vmatrix}
0 & 16 & 0 & 9 & 0 & 4 & 0 & 1 & 0 \\ 
1 & 0 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\ 
0 & 1 & 0 & 0 & 0 & 0 & 0 & 0 & 0 \\ 
0 & 0 & 1 & 0 & 0 & 0 & 0 & 0 & 0 \\ 
0 & 0 & 0 & 1 & 0 & 0 & 0 & 0 & 0 \\ 
0 & 0 & 0 & 0 & 1 & 0 & 0 & 0 & 0 \\ 
0 & 0 & 0 & 0 & 0 & 1 & 0 & 0 & 0 \\ 
0 & 0 & 0 & 0 & 0 & 0 & 1 & 0 & 0 \\ 
0 & 0 & 0 & 0 & 0 & 0 & 0 & 1 & 0
\end{vmatrix}
*
\begin{vmatrix}
f(n-5) \\ 
f(n-10) \\ 
f(n-15) \\ 
f(n-20) \\ 
f(n-25) \\
f(n-30) \\
f(n-35) \\
f(n-40) \\
f(n-45)
\end{vmatrix} 
$$

Pode deixar os primeiros casos (n < 45) já calculados. 

</details>

## J - Equality Control

<details>
<summary><b>Solução</b></summary>

A questão é chata de implementar. Além disso, precisamos tratar os vetores alteatórios de forma especial. O que fiz nesse implementação, foi o shuffle(v) = inf + sort(v) + inf. Além disso, o sort(v), além de ordenar, ele vai remover os infinitos que foram adicionados. No fim, basta ver se os dois vetores são iguais.

</details>

## K - Say Goodbye to Tic-Tac-Toe 

<details>
<summary><b>Solução</b></summary>

Essa questão é diferente do que foi vista em aula pois X e O são diferentes. Os estados dos jogos podem ser G[N][a][b], onde N é o tamanho do jogo, 

a=0 -> não tem nada do lado esquerdo

a=1 -> tem um X no lado esquerdo

a=2 -> tem um O no lado esquerdo

b=0 -> não tem nada do lado direito

b=1 -> tem um X no lado direito

b=2 -> tem um O no lado direito

Com isso, basta calcular o número de grundy. No caso de já começar marcado, você pode quebrar em jogos simutâneos.

</details>

## L - Notifications

<details>
<summary><b>Solução</b></summary>

Você faz um laço e vai mantendo o último tempo que foi usado.

</details>

## M - Forgotten Spell

<details>
<summary><b>Solução</b></summary>

Essa é uma questão que pode ser feita com DP que retorna a quantidade de formas válidas. Para evitar overflow, você pode limitar a resposta para 3. 

Os estados são dp[i][a1][a2][a3], onde i é a posição da letra que vamos determinar, a1, a2 e a3 vão dizer se a pessoa 1, 2 e 3 já errou alguma letra. E internamente na DP você pode tentar adicionar qualquer caractere. No final, será necessário recuperar a resposta na DP.

</details>