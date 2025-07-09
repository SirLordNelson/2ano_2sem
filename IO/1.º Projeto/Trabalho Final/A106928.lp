/* Objective function */
min: 11z1 + 10z2 + 7z3;

/* Variable bounds */
/* Restrições de controlo de fluxo */
bin_start_limit: x05 + x04 + x02 = z1 + z2 + z3;

bin11_end_limit: - x611 - x711 - x911 = -z1;
bin10_end_limit: - x510 - x610 - x810 = -z2;
bin7_end_limit: - x27 -x57 = -z3;

bin_middle_limit2: - x02 + x24 + x26 + x27 = 0;
bin_middle_limit4: - x04 - x24 + x46 + x48 + x49 = 0;
bin_middle_limit5: - x05 + x57 + x59 + x510 = 0;
bin_middle_limit6: - x26 - x46 + x68 + x610 + x611 = 0;
bin_middle_limit8: - x48 - x68 + x810 = 0;
bin_middle_limit9: - x49 - x59 - x79 + x911 = 0;

/* Restrições de Demanda dos items */
limit_item_quantity5: x05 + x27 + x49 + x510 + x611 >= 5;
limit_item_quantity4: x04 + x26 + x48 + x59 + x610 + x711 >= 10;
limit_item_quantity2: x02 + x24 + x46 + x57 + x68 + x79 + x810 + x911 >= 17;

/* Limitações de Contentores */
limit_bin_quantity11: z1 >= 0;
limit_bin_quantity10a: z2 <= 7;
limit_bin_quantity10b: z2 >= 0;
limit_bin_quantity7a: z3 <= 3;
limit_bin_quantity7b: z3 >= 0;

/* Limitações de Variáveis */
positive_var1: x05 >= 0;
positive_var2: x27 >= 0;
positive_var3: x49 >= 0;
positive_var4: x510 >= 0;
positive_var5: x611 >= 0;
positive_var6: x04 >= 0;
positive_var7: x26 >= 0;
positive_var8: x48 >= 0;
positive_var9: x59 >= 0;
positive_var10: x610 >= 0;
positive_var11: x711 >= 0;
positive_var12: x02 >= 0;
positive_var13: x24 >= 0;
positive_var14: x46 >= 0;
positive_var15: x57 >= 0;
positive_var16: x68 >= 0;
positive_var17: x79 >= 0;
positive_var18: x810 >= 0;
positive_var19: x911 >= 0;

/* Declaração das Variáveis Inteiras */
int z1, z2, z3, x05, x27, x49, x510, x611, x04, x26, x48, x59, x610, x711, x02, x24, x46, x57, x68, x79, x810, x911;