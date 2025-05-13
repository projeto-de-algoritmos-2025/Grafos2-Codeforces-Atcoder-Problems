# Grafos 2 - Leonardo G. Machado

## Questão 1 - Shortest Path 3

Plataforma: AtCoder

Rating/Dificuldade: 634 (Marrom)

[Tabela de Rankeamento](https://atcoder.jp/posts/16)

### Enunciado

Você recebe um grafo não direcionado simples e conectado com N vértices e M arestas. Cada vértice i(1≤i≤N) tem um peso Ai​. Cada aresta j(1≤j≤M) conecta os vértices Uj​ e Vj​ bidirecionalmente e tem um peso Bj​.

O peso de um caminho neste grafo é definido como a soma dos pesos dos vértices e arestas que aparecem no caminho.

Para cada i=2,3,…,N, resolva o seguinte problema:

Encontre o peso mínimo de um caminho do vértice 1 ao vértice i.

[Link do enunciado](https://atcoder.jp/contests/abc362/tasks/abc362_d)

### Solução

A solução consiste em aplicar o algoritmo de Dijkstra levando em conta o peso dos nós, além do peso das arestas.

[Link do codigo](shortest_path_3.cpp)

[Link da Submissão](https://atcoder.jp/contests/abc362/submissions/65746507)

## Questão 2 - Greg and Graph

Plataforma: Codeforces

Rating/Dificuldade: 1700 (Expert)

[Tabela de Rankeamento](https://codeforces.com/blog/entry/68288)

### Enunciado

Greg tem um grafo direcionado ponderado, composto por n vértices. Neste grafo, qualquer par de vértices distintos possui uma aresta entre eles em ambas as direções. Greg adora brincar com o grafo e agora inventou um novo jogo:

O jogo consiste em n etapas. No i-ésimo passo, Greg remove o vértice xi do grafo. À medida que Greg remove um vértice, ele também remove todas as arestas que entram e saem desse vértice.

Antes de executar cada etapa, Greg deseja saber a soma dos comprimentos dos caminhos mais curtos entre todos os pares de vértices restantes. O caminho mais curto pode passar por qualquer vértice restante. Em outras palavras, se assumirmos que d(i, v, u) é o caminho mais curto entre os vértices v e u no grafo formado antes da exclusão do vértice xi, então Greg deseja saber o valor da seguinte soma:

$\sum_{v, u, v \neq u} d(i, v, u)$

Ajude Greg, imprima o valor da soma necessária antes de cada etapa.

[Link do Enunciado](https://codeforces.com/problemset/problem/295/B)

### Solução

Para resolver o problema, foi utilizado o algoritmo de Floyd-Warshall, que computa em tempo O(n³), em que n é a quantidade de nós, todos os menores caminhos entre todos os pares de nós do grafo.

O problema é resolvido de maneira reversa, com o grafo inicialmente vazio, e com os nós sendo adicionados na ordem contrária de remoção.

Ao adicionar um nó, recalcula-se a menor distância para cada par de nós do grafo.

[Link do Código](greg.cpp)

[Link da Submissão](https://codeforces.com/problemset/submission/295/319444045)

## Questão 3 - K-th Path

Plataforma: Codeforces

Rating/Dificuldade: 2200 (International Master)

[Tabela de Rankeamento](https://codeforces.com/blog/entry/68288)


### Enunciado

Você recebe um grafo ponderado não direcionado conectado, composto por n vértices e m arestas.

Você precisa imprimir o k-ésimo menor caminho mais curto neste grafo (caminhos do vértice para si mesmo não são contados, caminhos de i para j e de j para i são contados como um).

Mais formalmente, se d é a matriz de caminhos mais curtos, onde di,j é o comprimento do caminho mais curto entre os vértices i e j (1 ≤i< j ≤ n), então você precisa imprimir o k-ésimo elemento na matriz ordenada, composta por todos os di,j, onde 1 ≤ i < j ≤ n.

[Link do Enunciado](https://codeforces.com/contest/1196/problem/F)

### Solução 

A solução proposta consiste em aplicar o algoritmo de Dijkstra para todos os nós do grafo e guardar o tamanho do menor caminho de cada par em um max-heap, com algumas restrições. A mais importante, dada no enunciado, diz que será escolhido no máximo o 400-ésimo menor caminho para qualquer grafo. Dessa forma, nosso heap atinge no máximo 400 elementos, sendo a raiz removida caso ultapasse. Entretando, mesmo com otimizações, não foi possível resolver um caso de teste em tempo hábil.

[Link do Código](kth_path.cpp)

[Link da submissão](https://codeforces.com/contest/1196/submission/319445302)