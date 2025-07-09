

/*    Cobertura das arestas de um grafo

Considere o seguinte grafo em que arestas representam os corredores de um museu.
Um guarda colocado num vértice do grafo vigia todas as arestas que são
incidentes no vértice e vê os guardas (eventualmente) colocados nos vértices adjacentes,
e só esses.
                    v2            v4
                      -------------
                    / |\           | \
                  /   |  \         |   \
              v1/     |    \       |     \ v6
                \     |      \     |     /
                  \   |        \   |   /
                    \ |          \ | /
                       ------------
                    v3             v5

determinar o número mínimo de guardas que são necessários
para vigiar todos os corredores do museu.

J.M. Valério de Carvalho

*/
/*
   Definição das variáveis de decisão

   variáveis binárias:

   x_j = 1, se houver um guarda no vértice j
          , caso contrário
 */

 /* Objective function */
min: x1 + x2 + x3 + x4+ x5 + x6;

 /*
   Restrições
   
   para cada corredor (aresta (i,j)), deve haver um guarda no
   vértice i ou no vértice j

   a restrição xi + xj >= 1 é um OU lógico:
   uma das variáveis, pelo menos, deve tomar o valor 1

 */
arestav1v2: x1 + x2 >=1;
arestav1v3: x1 + x3 >=1;
arestav2v3: x2 + x3 >=1;
arestav2v4: x2 + x4 >=1;
arestav2v5: x2 + x5 >=1;
arestav3v5: x3 + x5 >=1;
arestav4v5: x4 + x5 >=1;
arestav4v6: x4 + x6 >=1;
arestav5v6: x5 + x6 >=1;

// restrições de integralidade
bin x1, x2, x3, x4, x5, x6;














