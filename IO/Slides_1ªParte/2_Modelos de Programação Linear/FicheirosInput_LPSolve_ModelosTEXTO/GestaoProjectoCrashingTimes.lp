
// custo associado à redução das durações das actividades
min: 100 r0 + 300 r1 + 500 r2 + 100 r3 + 400 r4 + 800 r5 + 90 r6 + 0 r7 +
100 r8 + 0 r9 + 500 r10+ 300 r11;

// tempo máximo para concluir o projecto
tf <= 26;

// relações de precedência
// na restrição tj >= ti - ri + di, a fun<ão ti - ri + di designa
// o tempo de conclusão da actividade i após a redução da duração,
// de di para -ri + di
arco_01: t1 >= t0 - r0 + 4 ;
arco_12: t2 >= t1 - r1 + 6 ;
arco_23: t3 >= t2 - r2 + 7 ;
arco_i0: t0 >= ti + 0 ;
arco_04: t4 >= t0 - r0 + 4 ;
arco_42: t2 >= t4 - r4 + 9 ;
arco_53: t3 >= t5 - r5 + 4 ;
arco_3f: tf >= t3 - r3 + 2 ;
arco_45: t5 >= t4 - r4 + 9 ;
arco_5f: tf >= t5 - r5 + 4 ;
arco_i6: t6 >= ti + 0 ;
arco_74: t4 >= t7 - r7 + 6 ;
arco_85: t5 >= t8 - r8 + 4 ;
arco_9f: tf >= t9 - r9 + 2 ;
arco_67: t7 >= t6 - r6 + 5 ;
arco_78: t8 >= t7 - r7 + 6 ;
arco_89: t9 >= t8 - r8 + 4 ;
arco_610: t10 >= t6 - r6 + 5 ;
arco_108: t8 >= t10 - r10 + 8 ;
arco_119: t9 >= t11 - r11 + 7 ;
arco_1011: t11 >= t10 - r10 + 8;

// reduções máximas permitidas
r0 <= 1 ;
r1 <= 2 ;
r2 <= 4 ;
r3 <= 1 ;
r4 <= 3 ;
r5 <= 1 ;
r6 <= 2 ;
r7 <= 0 ;
r8 <= 1 ;
r9 <= 0 ;
r10 <= 1 ;
r11 <= 2 ;
