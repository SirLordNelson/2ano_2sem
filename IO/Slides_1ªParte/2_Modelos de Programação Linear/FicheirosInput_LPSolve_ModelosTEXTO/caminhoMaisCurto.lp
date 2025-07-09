//   caminho mais curto num grafo acíclico
min: 4 x01 + 4 x04 + 6 x12 + 7 x23 + 2 x3t + 9 x42 + 9 x45 + 4 x53 +
     4 x5t + 5 x67 + 5 x610 + 6 x74 + 6 x78 + 4 x85 + 4 x89 + 2 x9t +
     8 x108 + 8 x1011 + 7 x119;

// fluxo que entra no vértice = fluxo que sai
vertice_s: xs0 + xs6 = 1;
vertice_0: xs0 = x01 + x04;
vertice_1: x01 = x12;
vertice_2: x12 + x42 = x23;
vertice_3: x23 + x53 = x3t;
vertice_4: x04 + x74 = x42 + x45;
vertice_5: x45 + x85 = x53 + x5t;
vertice_6: xs6 = x67 + x610;
vertice_7: x67 = x74 + x78;
vertice_8: x78 + x108 = x85 + x89;
vertice_9: x89 + x119 = x9t;
vertice_10: x610 = x108 + x1011;
vertice_11: x1011 = x119;












