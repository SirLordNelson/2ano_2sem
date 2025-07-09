
/*      Coloração dos vértices de um grafo

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

sabendo que é necessário haver guardas em todos os vértices do grafo,
determinar o número mínimo de cores de fardas de modo a que
cada guarda só veja guardas com fardas de cores diferentes da sua.

J.M. Valério de Carvalho

*/

/*

   Definição das variáveis de decisão

   variáveis binárias:
 
   x_ik = 1, se o vértice i tiver a cor k
          0, caso contrário
          
   y_k = 1, se a cor for usada
          , caso contrário

 */

/* Objective function */
min: y1 + y2 + y3 + y4+ y5 + y6;

// cada vértice deve ter uma cor:
// apenas uma das variáveis pode assumir o valor 1 para cada vértice
v1: x11 + x12 + x13 + x14 + x15 + x16 = 1;
v2: x21 + x22 + x23 + x24 + x25 + x26 = 1;
v3: x31 + x32 + x33 + x34 + x35 + x36 = 1;
v4: x41 + x42 + x43 + x44 + x45 + x46 = 1;
v5: x51 + x52 + x53 + x54 + x55 + x56 = 1;
v6: x61 + x62 + x63 + x64 + x65 + x66 = 1;
 
/* se um vértice usar uma cor, então essa cor deve ser usada

  nota: a restrição do tipo xik <= yk é uma implicação:
        se xik =1, então yk = 1,
        se xik =0, então yk pode ser 0 ou 1.
*/

cor1: x11 <= y1; x21 <= y1; x31 <= y1; x41 <= y1; x51 <= y1; x61 <= y1;
cor2: x12 <= y2; x22 <= y2; x32 <= y2; x42 <= y2; x52 <= y2; x62 <= y2;
cor3: x13 <= y3; x23 <= y3; x33 <= y3; x43 <= y3; x53 <= y3; x63 <= y3;
cor4: x14 <= y4; x24 <= y4; x34 <= y4; x44 <= y4; x54 <= y4; x64 <= y4;
cor5: x15 <= y5; x25 <= y5; x35 <= y5; x45 <= y5; x55 <= y5; x65 <= y5;
cor6: x16 <= y6; x26 <= y6; x36 <= y6; x46 <= y6; x56 <= y6; x66 <= y6;

/*
 se o vértice i e o vértice j forem adjacentes (unidos por uma aresta),
 não poderão ter a mesma cor k
 
  a restrição xik + xjk <= 1 pode ser vista como uma implicação, ie,
   se uma variável for igual a 1, a outra deve ser igual a 0:

  xik <= (1-xjk): se xik = 1, então xjk = 0
                : se xik = 1, então xjk pode ser 0 ou 1
                
                e vice-versa:
                
                : se xjk = 1, então xik = 0
                : se xjk = 1, então xik pode ser 0 ou 1
*/

v1v3: x11+x31<=1; x12+x32<=1; x13+x33<=1; x14+x34<=1; x15+x35<=1; x16+x36<=1;
v2v3: x21+x31<=1; x22+x32<=1; x23+x33<=1; x24+x34<=1; x25+x35<=1; x26+x36<=1;
v2v4: x21+x41<=1; x22+x42<=1; x23+x43<=1; x24+x44<=1; x25+x45<=1; x26+x46<=1;
v2v5: x21+x51<=1; x22+x52<=1; x23+x53<=1; x24+x54<=1; x25+x55<=1; x26+x56<=1;
v3v5: x31+x51<=1; x32+x52<=1; x33+x53<=1; x34+x54<=1; x35+x55<=1; x36+x56<=1;
v4v5: x41+x51<=1; x42+x52<=1; x43+x53<=1; x44+x54<=1; x45+x55<=1; x46+x56<=1;
v4v6: x41+x61<=1; x42+x62<=1; x43+x63<=1; x44+x64<=1; x45+x65<=1; x46+x66<=1;
v5v6: x51+x61<=1; x52+x62<=1; x53+x63<=1; x54+x64<=1; x55+x65<=1; x56+x66<=1;

// restrições de integralidade
bin x11, x12, x13, x14, x15, x16;
bin x21, x22, x23, x24, x25, x26;
bin x31, x32, x33, x34, x35, x36;
bin x41, x42, x43, x44, x45, x46;
bin x51, x52, x53, x54, x55, x56;
bin x61, x62, x63, x64, x65, x66;
bin y1, y2, y3, y4, y5, y6;














