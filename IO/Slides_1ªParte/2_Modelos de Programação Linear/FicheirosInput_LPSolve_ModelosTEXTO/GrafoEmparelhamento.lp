

/*    Emparelhamento m�ximo de um grafo

Considere o seguinte grafo em que v�rtices representam pessoas e
um arco entre duas pessoas significa que elas s�o compat�veis,
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

determinar o n�mero m�ximo de equipas.

J.M. Val�rio de Carvalho

*/
/*
   Defini��o das vari�veis de decis�o

   vari�veis bin�rias:

   x_ij = 1, se a a aresta (i,j)$ for seleccionada
          , caso contr�rio
 */

 /* Objective function */
max: x12 + x13 + x23 + x24 + x25 + x35 + x45 + x46 + x56;

 /*
   Restri��es
   
   para cada v�rtice, deve haver no m�ximo uma aresta incidente

 */
v1: x12 + x13 <=1;
v2: x12 + x23 + x24 + x25 <=1;
v3: x13 + x23 + x35 <=1;
v4: x24 + x45 + x46 <=1;
v5: x25 + x35 + x45 + x56 <=1;
v6: x46 + x56 <=1;

// restri��es de integralidade
bin x12, x13, x23, x24, x25, x35, x45, x46, x56;














