

/*    Emparelhamento máximo de um grafo

Considere o seguinte grafo em que vértices representam pessoas e
um arco entre duas pessoas significa que elas são compatíveis,
podendo formar uma equipa.
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

determinar o número máximo de equipas.

J.M. Valério de Carvalho

*/
/*
   Definição das variáveis de decisão

   variáveis binárias:

   x_ij = 1, se a a aresta (i,j)$ for seleccionada
          , caso contrário
 */

 /* Objective function */
max: x12 + x13 + x23 + x24 + x25 + x35 + x45 + x46 + x56;

 /*
   Restrições
   
   para cada vértice, deve haver no máximo uma aresta incidente

 */
v1: x12 + x13 <=1;
v2: x12 + x23 + x24 + x25 <=1;
v3: x13 + x23 + x35 <=1;
v4: x24 + x45 + x46 <=1;
v5: x25 + x35 + x45 + x56 <=1;
v6: x46 + x56 <=1;

// restrições de integralidade
bin x12, x13, x23, x24, x25, x35, x45, x46, x56;














