/* Exercicio 12.3 */

min: 7 x1 +  4 x2 +  8 x3 +  1 x4 +
  + 20 y1 + 40 y2 + 10 y3 + 70 y4;

/* Quantidade total a fabricar */
quantidade: x1 + x2 + x3 + x4 = 1000;

/* Restri��es l�gicas que indicam uso da maquina
   quando h� a respectiva actividade
   (adicionalmente imp�em a capacidade m�xima da maquina) */
Actividade1_indica_UsoMaquina1: x1 <= 500 y1;
Actividade2_indica_UsoMaquina2: x2 <= 200 y2;
Actividade3_indica_UsoMaquina3: x3 <= 400 y3;
Actividade4_indica_UsoMaquina4: x4 <= 600 y4;

/* quantidade minima maquina 4 */
maquina4min: x4 >= 500 y4;

/* uma das m�quinas em manuten��o
   (poder� n�o haver interesse em usar todas as 3 restantes) */
manutencao: y1 + y2 + y3 + y4 <= 3;


bin y1,y2,y3,y4;

/*
as seguintes restri��es s�o muitas vezes relaxadas
na pr�tica, sendo o valor do n�vel de actividade arredondado
*/
//int x1, x2, x3;


