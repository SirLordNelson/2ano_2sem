
/*      Conjunto de v�rtices independentes de um grafo

Considere o seguinte grafo em que as arestas representam os corredores de um museu.
Um guarda colocado num v�rtice do grafo vigia todas as arestas que s�o
incidentes no v�rtice e v� os guardas (eventualmente) colocados nos v�rtices adjacentes,
e s� esses.
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

determinar o n�mero m�ximo de guardas que podem ser colocados
em v�rtices do grafo de modo a que nenhum guarda veja outro guarda.

J.M. Val�rio de Carvalho

*/

/* Objective function */
max: x1 + x2 + x3 + x4+ x5 + x6;


 /*
   Defini��o das vari�veis de decis�o

   vari�veis bin�rias:

   xj = 1, se houver um guarda no v�rtice j
          , caso contr�rio
 */

 /*
   Restri��es
   para cada corredor (aresta (i,j)), s� pode haver um guarda no
   v�rtice i ou no v�rtice j:
   
   xi + xj <= 1

   a restri��o xi + xj <= 1 pode ser vista como uma implica��o, ie,
   se uma vari�vel for igual a 1, a outra deve ser igual a 0:

   xi <= (1-xj): se xi = 1, ent�o xj = 0
                 se xi = 0, ent�o xj pode ser 0 ou 1

                 e vice-versa:
                 
                 se xj = 1, ent�o xi = 0
                 se xj = 0, ent�o xi pode ser 0 ou 1

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

// restri��es de integralidade
bin x1, x2, x3, x4, x5, x6;














