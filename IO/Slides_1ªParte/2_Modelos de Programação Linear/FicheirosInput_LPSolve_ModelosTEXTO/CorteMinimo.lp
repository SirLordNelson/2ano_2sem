/* Corte mínimo       */

/* funcão objectivo   */
min:  2 vs1 + 3 vs2 + 2 v12 + 3 v13 + 1 v14
     +2 v24 + 4 v34 + 1 v3t + 3v4t;

/* restrições */
ts:      ut - us = 1;
arco_s1: us - u1 + vs1 >= 0 ;
arco_s2: us - u2 + vs2 >= 0 ;
arco_12: u1 - u2 + v12 >= 0 ;
arco_13: u1 - u3 + v13 >= 0 ;
arco_14: u1 - u4 + v14 >= 0 ;
arco_24: u2 - u4 + v24 >= 0 ;
arco_34: u3 - u4 + v34 >= 0 ;
arco_3t: u3 - ut + v3t >= 0 ;
arco_4t: u4 - ut + v4t >= 0 ;

free us, u1, u2, u3, u4, ut;








