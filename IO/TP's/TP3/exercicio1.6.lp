/*
     Vari�veis de decis�o

     xij: quantidade investida no projecto j, j=1,2,
                               no ano i, i=0,...,5

     Dados

          como o valor dispon�vel para investimento n�o � dado,
          vamos usar como quantidade dispon�vel no ano 0 o valor 1.

     Fun��o objectivo
          
          pretende-se maximizar o valor dispon�vel no final do ano 5.
*/

/* Objective function */
max: xfinal;

// para cada ano,
// o lado esquerdo da equa��o indica as quantidades investidas
// o lado direito da equa��o indica o montante dispon�vel

ano0: x01 + x02 = 1;
ano1: x11 + x12 = 1.7 x01;
ano2: x21 + x22 = 1.7 x11 + 3 x02;
ano3: x31 + x32 = 1.7 x21 + 3 x12;
ano4: x41 + x42 = 1.7 x31 + 3 x22;
ano5: xfinal    = 1.7 x41 + 3 x32;

// o lucro por unidade investida = valor xfinal - 1 (valor dispon�vel no ano 0)

// nota: este modelo pode ser representado num grafo em que se associam
//       ganhos aos arcos (neste exemplo, representam os lucros)


