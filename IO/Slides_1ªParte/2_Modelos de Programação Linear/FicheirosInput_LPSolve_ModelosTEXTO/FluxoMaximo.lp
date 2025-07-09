
//   fluxo máximo

/* Objective function */
max: f;

/* Restrições */
//  conservação de fluxo
vertice_s: xs1 + xs2 = f;
vertice_1: xs1 = x12 + x13 + x14;
vertice_2: xs2 + x12 = x24;
vertice_3: x13 = x34 + x3t;
vertice_4: x14 + x24 + x34 = x4t;
vertice_t: x3t + x4t = f;

//  capacidade dos arcos
arco_s1: xs1 <= 2;
arco_s2: xs2 <= 3;
arco_12: x12 <= 2;
arco_13: x13 <= 3;
arco_14: x14 <= 1;
arco_24: x24 <= 2;
arco_34: x34 <= 4;
arco_3t: x3t <= 1;
arco_4t: x4t <= 3;













