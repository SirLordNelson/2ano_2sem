/*
  Problem name: multicommodity flow problem: arc flow model
*/
min:  + 8x121 + 12x131 + 2x231 + 7x241 + 10x251 + 4x341 + 6x351 + 1x451
      + 8x211 + 12x311 + 2x321 + 7x421 + 10x521 + 4x431 + 6x531 + 1x541
      + 8x122 + 12x132 + 2x232 + 7x242 + 10x252 + 4x342 + 6x352 + 1x452
      + 8x212 + 12x312 + 2x322 + 7x422 + 10x522 + 4x432 + 6x532 + 1x542
      + 8x123 + 12x133 + 2x233 + 7x243 + 10x253 + 4x343 + 6x353 + 1x453
      + 8x213 + 12x313 + 2x323 + 7x423 + 10x523 + 4x433 + 6x533 + 1x543
      + 8x124 + 12x134 + 2x234 + 7x244 + 10x254 + 4x344 + 6x354 + 1x454
      + 8x214 + 12x314 + 2x324 + 7x424 + 10x524 + 4x434 + 6x534 + 1x544
      + 8x125 + 12x135 + 2x235 + 7x245 + 10x255 + 4x345 + 6x355 + 1x455
      + 8x215 + 12x315 + 2x325 + 7x425 + 10x525 + 4x435 + 6x535 + 1x545
      + 8x126 + 12x136 + 2x236 + 7x246 + 10x256 + 4x346 + 6x356 + 1x456
      + 8x216 + 12x316 + 2x326 + 7x426 + 10x526 + 4x436 + 6x536 + 1x546
      + 8x127 + 12x137 + 2x237 + 7x247 + 10x257 + 4x347 + 6x357 + 1x457
      + 8x217 + 12x317 + 2x327 + 7x427 + 10x527 + 4x437 + 6x537 + 1x547
      + 8x128 + 12x138 + 2x238 + 7x248 + 10x258 + 4x348 + 6x358 + 1x458
      + 8x218 + 12x318 + 2x328 + 7x428 + 10x528 + 4x438 + 6x538 + 1x548;


// volume of stream
stream1 =  8;
stream2 = 30;
stream3 = 20;
stream4 = 12;
stream5 = 16;
stream6 =  4;
stream7 =  3;
stream8 = 10;

// flow conservation for stream 1 with (origin,destination) =  (1,2)
Stream1Vertice1:-x211-x311+x121+x131 = +stream1;
Stream1Vertice2:-x121-x321-x421-x521+x211+x231+x241+x251=-stream1;
Stream1Vertice3:-x131-x231-x431-x531+x311+x321+x341+x351=0 ; 
Stream1Vertice4:-x241-x341-x541+x431+x421+x451=0;
Stream1Vertice5:-x251-x351-x451+x521+x531+x541=0;

// flow conservation for stream 2 with (origin,destination) =  (1,4)
Stream2Vertice1:-x212-x312+x122+x132 = +stream2;
Stream2Vertice2:-x122-x322-x422-x522+x212+x232+x242+x252=0;
Stream2Vertice3:-x132-x232-x432-x532+x312+x322+x342+x352=0;  
Stream2Vertice4:-x242-x342-x542+x432+x422+x452=-stream2;
Stream2Vertice5:-x252-x352-x452+x522+x532+x542=0;

// flow conservation for stream 3 with (origin,destination) =  (1,5)
Stream3Vertice1:-x213-x313+x123+x133 =+stream3;
Stream3Vertice2:-x123-x323-x423-x523+x213+x233+x243+x253=0;
Stream3Vertice3:-x133-x233-x433-x533+x313+x323+x343+x353=0;  
Stream3Vertice4:-x243-x343-x543+x433+x423+x453=0;
Stream3Vertice5:-x253-x353-x453+x523+x533+x543=-stream3;

// flow conservation for stream 4 with (origin,destination) =  (2,3)
Stream4Vertice1:-x214-x314+x124+x134 = 0;
Stream4Vertice2:-x124-x324-x424-x524+x214+x234+x244+x254=+stream4;
Stream4Vertice3:-x134-x234-x434-x534+x314+x324+x344+x354=-stream4;
Stream4Vertice4:-x244-x344-x544+x434+x424+x454=0;
Stream4Vertice5:-x254-x354-x454+x524+x534+x544=0;

// flow conservation for stream 5 with (origin,destination) =  (2,4)
Stream5Vertice1:-x215-x315+x125+x135 = 0;
Stream5Vertice2:-x125-x325-x425-x525+x215+x235+x245+x255=+stream5;
Stream5Vertice3:-x135-x235-x435-x535+x315+x325+x345+x355=0;  
Stream5Vertice4:-x245-x345-x545+x435+x425+x455=-stream5;
Stream5Vertice5:-x255-x355-x455+x525+x535+x545=0;

// flow conservation for stream 6 with (origin,destination) =  (3,4)
Stream6Vertice1:-x216-x316+x126+x136 = 0;
Stream6Vertice2:-x126-x326-x426-x526+x216+x236+x246+x256=0;
Stream6Vertice3:-x136-x236-x436-x536+x316+x326+x346+x356=+stream6 ;
Stream6Vertice4:-x246-x346-x546+x436+x426+x456=-stream6;
Stream6Vertice5:-x256-x356-x456+x526+x536+x546=0;

// flow conservation for stream 7 with (origin,destination) =  (3,5)
Stream7Vertice1:-x217-x317+x127+x137 = 0;
Stream7Vertice2:-x127-x327-x427-x527+x217+x237+x247+x257=0;
Stream7Vertice3:-x137-x237-x437-x537+x317+x327+x347+x357=+stream7;
Stream7Vertice4:-x247-x347-x547+x437+x427+x457=0;
Stream7Vertice5:-x257-x357-x457+x527+x537+x547=-stream7;

// flow conservation for stream 8 with (origin,destination) =  (4,5)
Stream8Vertice1:-x218-x318+x128+x138 = 0;
Stream8Vertice2:-x128-x328-x428-x528+x218+x238+x248+x258=0;
Stream8Vertice3:-x138-x238-x438-x538+x318+x328+x348+x358=0;
Stream8Vertice4:-x248-x348-x548+x438+x428+x458=+stream8;
Stream8Vertice5:-x258-x358-x458+x528+x538+x548=-stream8;

// capacity of arcs
Arco12: + x121 + x122 + x123 + x124 + x125 + x126 + x127 + x128
+ x211 + x212 + x213 + x214 + x215 + x216 + x217 + x218 <= 32;
Arco13: + x131 + x132 + x133 + x134 + x135 + x136 + x137 + x138
 + x311 + x312 + x313 + x314 + x315 + x316 + x317 + x318 <= 32;
Arco23: + x231 + x232 + x233 + x234 + x235 + x236 + x237 + x238
 + x321 + x322 + x323 + x324 + x325 + x326 + x327 + x328 <= 32;
Arco24: + x241 + x242 + x243 + x244 + x245 + x246 + x247 + x248
 + x421 + x422 + x423 + x424 + x425 + x426 + x427 + x428 <= 32;
Arco25: + x251 + x252 + x253 + x254 + x255 + x256 + x257 + x258
 + x521 + x522 + x523 + x524 + x525 + x526 + x527 + x528 <= 32;
Arco34: + x341 + x342 + x343 + x344 + x345 + x346 + x347 + x348
 + x431 + x432 + x433 + x434 + x435 + x436 + x437 + x438 <= 32;
Arco35: + x351 + x352 + x353 + x354 + x355 + x356 + x357 + x358
 + x531 + x532 + x533 + x534 + x535 + x536 + x537 + x538 <= 32;
Arco45: + x451 + x452 + x453 + x454 + x455 + x456 + x457 + x458
 + x541 + x542 + x543 + x544 + x545 + x546 + x547 + x548 <= 32;
 