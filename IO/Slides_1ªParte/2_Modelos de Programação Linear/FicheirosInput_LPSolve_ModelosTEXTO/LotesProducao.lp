///////////////////////////////////////
//
//     Lotes de produ��o
//
///////////////////////////////////////
/*

Procura:

per�odo    1   2   3   4
           2   3   4   2  artigos

Custos de produ��o:

per�odo    1   2   3   4
          12  10  14  10  U.M. / artigo
          
Custos de posse de invent�rio:

per�odo    1   2   3   4
           1   1   1   1  U.M. / artigo
*/

/* Fun��o objectivo */
min: 12 x1 + 10 x2 + 14 x3 + 10 x4 + 1 s1 + 1 s2 + 1 s3 + 1 s4;

/* Restri��es */
s0 = 0;
x1 + s0 - s1 = 2;
x2 + s1 - s2 = 3;
x3 + s2 - s3 = 4;
x4 + s3 - s4 = 2;
s4 = 0;

// Capacidade m�xima de produ��o: 4 unidades / per�odo
x1 <= 4; x2 <= 4; x3 <= 4; x4 <= 4;

// Invent�rio m�ximo:  2 unidades
s1 <= 2; s2 <= 2; s3 <= 2; s4 <= 2;
