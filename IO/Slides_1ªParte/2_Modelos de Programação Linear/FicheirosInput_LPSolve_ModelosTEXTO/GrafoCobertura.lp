

/*    Cobertura das arestas de um grafo

Considere o seguinte grafo em que arestas representam os corredores de um museu.
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

determinar o n�mero m�nimo de guardas que s�o necess�rios
para vigiar todos os corredores do museu.

J.M. Val�rio de Carvalho

*/
/*
   Defini��o das vari�veis de decis�o

   vari�veis bin�rias:

   x_j = 1, se houver um guarda no v�rtice j
          , caso contr�rio
 */

 /* Objective function */
min: x1 + x2 + x3 + x4+ x5 + x6;

 /*
   Restri��es
   
   para cada corredor (aresta (i,j)), deve haver um guarda no
   v�rtice i ou no v�rtice j

   a restri��o xi + xj >= 1 � um OU l�gico:
   uma das vari�veis, pelo menos, deve tomar o valor 1

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

// restri��es de integralidade
bin x1, x2, x3, x4, x5, x6;














