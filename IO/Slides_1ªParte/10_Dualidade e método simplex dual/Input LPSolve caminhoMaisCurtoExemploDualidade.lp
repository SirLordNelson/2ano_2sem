
//   caminho mais curto entre s e t num grafo ac�clico
//   afastamento m�ximo de v�rtices t e s
//
//   o modelo do problema do caminho mais curto � o seguinte:
//

/*
min:       1 xs1 +6 xs3 +3 x12 +2 x13 +1 x24 +1 x2t + 1x34 +6 x4t;

//         Restri��es
vertice_s: + xs1  + xs3                                              =  1;
vertice_1: - xs1         + x12  + x13                                =  0;
vertice_2:               - x12         + x24  + x2t                  =  0;
vertice_3:        - xs3         - x13                + x34           =  0;
vertice_4:                             - x24         - x34  + x4t    =  0;
vertice_t:                                    - x2t         - x4t    = -1;
*/

//   depois de multiplicar todas as restri��es por -1 e de
//   substituir as restri��es de = por restri��es de >=,
//   o que v�lido (porqu�?), o modelo do problema � o seguinte:

/*
min:       1 xs1 +6 xs3 +3 x12 +2 x13 +1 x24 +1 x2t + 1x34 +6 x4t;

//         Restri��es
vertice_s: - xs1  - xs3                                             >= -1;
vertice_1: + xs1         - x12  - x13                               >=  0;
vertice_2:               + x12         - x24  - x2t                 >=  0;
vertice_3:        + xs3         + x13                - x34          >=  0;
vertice_4:                             + x24         + x34  - x4t   >=  0;
vertice_t:                                    + x2t         + x4t   >= +1;
*/

//   associa-se uma vari�vel dual a cada restri��es que significa
//
//   di = dist�ncia do v�rtice i ao v�rtice s

max: dt - ds;

arco_s1:  d1 - ds <=  1;
arco_s3:  d3 - ds <=  6;
arco_12:  d2 - d1 <=  3;
arco_13:  d3 - d1 <=  2;
arco_24:  d4 - d2 <=  1;
arco_2t:  dt - d2 <=  1;
arco_34:  d4 - d3 <=  1;
arco_4t:  dt - d4 <=  6;
fixar_s:  ds = 0;










