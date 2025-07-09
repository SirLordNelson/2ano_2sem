/* Objective function */
max: dt ;

/* Restrições */
posi_vs: ds = 0;
arco_s0: d0 <= ds + 0 ;
arco_s6: d6 <= ds + 0 ;
arco_01: d1 <= d0 + 4 ;
arco_04: d4 <= d0 + 4 ;
arco_12: d2 <= d1 + 6 ;
arco_23: d3 <= d2 + 7 ;
arco_3t: dt <= d3 + 2 ;
arco_42: d2 <= d4 + 9 ;
arco_45: d5 <= d4 + 9 ;
arco_53: d3 <= d5 + 4 ;
arco_5t: dt <= d5 + 4 ;
arco_610: d10 <= d6 + 5 ;
arco_67: d7 <= d6 + 5 ;
arco_74: d4 <= d7 + 6 ;
arco_78: d8 <= d7 + 6 ;
arco_85: d5 <= d8 + 4 ;
arco_89: d9 <= d8 + 4 ;
arco_9t: dt <= d9 + 2 ;
arco_1011: d11 <= d10 + 8;
arco_108: d8 <= d10 + 8 ;
arco_119: d9 <= d11 + 7 ;








