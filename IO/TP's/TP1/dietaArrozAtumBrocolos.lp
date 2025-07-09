///////////////////////////////////////
//
//     Problema da dieta
//
///////////////////////////////////////


/* Função objectivo  */
min: 0.10 arroz + 1.20 atum + 0.06 azeite + 0.24 brocolos;

/* Restrições */

proteina   =  2.5 arroz + 20.0 atum             + 3.0 brocolos;
lipidos    =  0.2 arroz +  8.0 atum + 12 azeite + 0.3 brocolos;
hidcarbono = 28.0 arroz                         + 5.5 brocolos;

energiaproteina   = 4 proteina;
energialipidos    = 9 lipidos;
energiahidcarbono = 4 hidcarbono;

energia = energiaproteina + energialipidos + energiahidcarbono;
energia >= 600;

energiaproteina >= 0.10 energia;
energiaproteina <= 0.15 energia;

energialipidos >= 0.15 energia;
energialipidos <= 0.30 energia;

energiahidcarbono >= 0.55 energia;
energiahidcarbono <= 0.75 energia;

//atum >= 0.5;
