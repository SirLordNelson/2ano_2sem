
/*      Conjunto de vértices independentes de um grafo

Considere o seguinte grafo em que as arestas representam os corredores de um museu.
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

determinar o número máximo de guardas que podem ser colocados
em vértices do grafo de modo a que nenhum guarda veja outro guarda.

J.M. Valério de Carvalho

*/

/* Objective function */
max: x1 + x2 + x3 + x4+ x5 + x6;


 /*
   Definição das variáveis de decisão

   variáveis binárias:

   xj = 1, se houver um guarda no vértice j
          , caso contrário
 */

 /*
   Restrições
   para cada corredor (aresta (i,j)), só pode haver um guarda no
   vértice i ou no vértice j:
   
   xi + xj <= 1

   a restrição xi + xj <= 1 pode ser vista como uma implicação, ie,
   se uma variável for igual a 1, a outra deve ser igual a 0:

   xi <= (1-xj): se xi = 1, então xj = 0
                 se xi = 0, então xj pode ser 0 ou 1

                 e vice-versa:
                 
                 se xj = 1, então xi = 0
                 se xj = 0, então xi pode ser 0 ou 1

 */
arestav1v2: x1 + x2 <=1;
arestav1v3: x1 + x3 <=1;
arestav2v3: x2 + x3 <=1;
arestav2v4: x2 + x4 <=1;
arestav2v5: x2 + x5 <=1;
arestav3v5: x3 + x5 <=1;
arestav4v5: x4 + x5 <=1;
arestav4v6: x4 + x6 <=1;
arestav5v6: x5 + x6 <=1;

// restrições de integralidade
bin x1, x2, x3, x4, x5, x6;














