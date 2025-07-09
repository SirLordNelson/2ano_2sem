//////////////////////////////////////////////////////
//
//             Lotes de produção multi-artigo
//
//////////////////////////////////////////////////////

Min: CustoLaranja + CustoMaca + CustoPera
     + 10 xL1 + 10 xL2 + 10 xL3 + 10 xL4 + 10 xL5 + 10 xL6
     + 10 xL7 + 12 xL8 + 10 xL9 + 10 xL10 + 10 xL11 + 10 xL12
     + 10 xM1 + 10 xM2 + 10 xM3 + 10 xM4 + 10 xM5 + 10 xM6
     + 10 xM7 + 12 xM8 + 10 xM9 + 10 xM10 + 10 xM11 + 10 xM12
     + 10 xP1 + 10 xP2 + 10 xP3 + 10 xP4 + 10 xP5 + 10 xP6
     + 10 xP7 + 12 xP8 + 10 xP9 + 10 xP10 + 10 xP11 + 10 xP12
     +  1 iL1 +  1 iL2 +  1 iL3 +  1 iL4 + 1 iL5 + 1 iL6
     +  1 iL7 + 1 iL8 + 1 iL9 + 1 iL10 + 1 iL11 + 1 iL12
     +  1 iM1 + 1 iM2 + 1 iM3 + 1 iM4 + 1 iM5 + 1 iM6
     +  1 iM7 + 1 iM8 + 1 iM9 + 1 iM10 + 1 iM11 + 1 iM12
     +  1 iP1 + 1 iP2 + 1 iP3 + 1 iP4 + 1 iP5 + 1 iP6
     +  1 iP7 + 1 iP8 + 1 iP9 + 1 iP10 + 1 iP11 + 1 iP12
     +  3 fL1 + 3 fL2 + 3 fL3 + 3 fL4 + 3 fL5 + 3 fL6
     +  3 fL7 + 3 fL8 + 3 fL9 + 3 fL10 + 3 fL11 + 3 fL12
     +  3 fM1 + 3 fM2 + 3 fM3 + 3 fM4 + 3 fM5 + 3 fM6
     +  3 fM7 + 3 fM8 + 3 fM9 + 3 fM10 + 3 fM11 + 3 fM12
     +  3 fP1 + 3 fP2 + 3 fP3 + 3 fP4 + 3 fP5 + 3 fP6
     +  3 fP7 + 3 fP8 + 3 fP9 + 3 fP10 + 3 fP11 + 3 fP12;

CustoLaranja = 145 cL1 + 145 cL2 + 155 cL3 + 150 cL4 + 165 cL5 + 160 cL6
             + 170 cL7 + 145 cL8 + 150 cL9 + 135 cL10+ 125 cL11+ 145 cL12;
CustoMaca    = 231 cM1 + 299 cM2 + 287 cM3 + 198 cM4 + 210 cM5 + 298 cM6
             + 211 cM7 + 180 cM8 + 117 cM9 + 116 cM10+ 221 cM11+ 217 cM12;
CustoPera    = 116 cP1 + 116 cP2 + 124 cP3 + 120 cP4 + 132 cP5 + 128 cP6
             + 136 cP7 + 116 cP8 + 120 cP9 + 108 cP10+ 100 cP11+ 116 cP12;

// Inventário de matéria prima
 iL0 = 16;
cL1 + iL0 - iL1 - xL1  = 0; cL2 + iL1 - iL2 - xL2  = 0;
cL3 + iL2 - iL3 - xL3  = 0; cL4 + iL3 - iL4 - xL4  = 0;
cL5 + iL4 - iL5 - xL5  = 0; cL6 + iL5 - iL6 - xL6  = 0;
cL7 + iL6 - iL7 - xL7  = 0; cL8 + iL7 - iL8 - xL8  = 0;
cL9 + iL8 - iL9 - xL9  = 0; cL10 + iL9 - iL10 - xL10 = 0;
cL11 + iL10 - iL11 - xL11 = 0; cL12 + iL11 - iL12 - xL12 = 0;
 iL12 = 16;

 iM0 = 8;
cM1 + iM0 - iM1 -xM1  = 0; cM2 + iM1 - iM2 -xM2  = 0;
cM3 + iM2 - iM3 -xM3  = 0; cM4 + iM3 - iM4 -xM4  = 0;
cM5 + iM4 - iM5 -xM5  = 0; cM6 + iM5 - iM6 -xM6  = 0;
cM7 + iM6 - iM7 -xM7  = 0; cM8 + iM7 - iM8 -xM8  = 0;
cM9 + iM8 - iM9 -xM9  = 0; cM10 + iM9 - iM10 -xM10  = 0;
cM11 + iM10 - iM11 - xM11 = 0; cM12 + iM11 - iM12 -xM12 = 0;
 iM12 = 8;

 iP0 = 6;
cP1 + iP0 - iP1 - xP1 = 0; cP2 + iP1 - iP2 - xP2  = 0;
cP3 + iP2 - iP3 - xP3 = 0; cP4 + iP3 - iP4- xP4  = 0;
cP5 + iP4 - iP5 - xP5 = 0; cP6 + iP5 - iP6 - xP6 = 0;
cP7 + iP6 - iP7 - xP7 = 0; cP8 + iP7 - iP8 - xP8 = 0;
cP9 + iP8 - iP9 - xP9 = 0; cP10 + iP9 - iP10 - xP10 = 0;
cP11 + iP10 - iP11 - xP11 = 0; cP12 + iP11 - iP12 - xP12 = 0;
iP12 = 6;

// Inventário final (produtos acabados)
 fL0 = 20;
xL1 + fL0 - fL1 = 9;  xL2 + fL1 - fL2 = 9;
xL3 + fL2 - fL3 = 9;  xL4 + fL3 - fL4 = 12;
xL5 + fL4 - fL5 = 16; xL6 + fL5 - fL6 = 17;
xL7 + fL6 - fL7 = 19; xL8 + fL7 - fL8 = 19;
xL9 + fL8 - fL9 = 16; xL10 + fL9 - fL10 = 12;
xL11 + fL10 - fL11 = 10; xL12 + fL11 - fL12 = 9;
fL12 = 20;

fM0 = 10;
xM1 + fM0 - fM1 = 5; xM2 + fM1 - fM2 = 5;
xM3 + fM2 - fM3 = 5; xM4 + fM3 - fM4 = 6;
xM5 + fM4 - fM5 = 8; xM6 + fM5 - fM6 = 9;
xM7 + fM6 - fM7 = 10; xM8 + fM7 - fM8 = 10;
xM9 + fM8 - fM9 = 8; xM10 + fM9 - fM10 = 6;
xM11 + fM10 - fM11 = 5; xM12 + fM11 - fM12 = 5;
fM12 = 10;

fP0 = 10;
xP1 + fP0 - fP1 = 4; xP2 + fP1 - fP2 = 4;
xP3 + fP2 - fP3 = 4; xP4 + fP3 - fP4 = 5;
xP5 + fP4 - fP5 = 6; xP6 + fP5 - fP6 = 7;
xP7 + fP6 - fP7 = 8; xP8 + fP7 - fP8 = 8;
xP9 + fP8 - fP9 = 6; xP10 + fP9 - fP10 = 5;
xP11 + fP10 - fP11 = 4; xP12 + fP11 - fP12 = 4;
fP12 = 10;

// Inventário máximo matéria prima:  30 unidades
iL1 + iM1 + iP1 <= 30; iL2 + iM2 + iP2 <= 30;
iL3 + iM3 + iP3 <= 30; iL4 + iM4 + iP4 <= 30;
iL5 + iM5 + iP5 <= 30; iL6 + iM6 + iP6 <= 30;
iL7 + iM7 + iP7 <= 30; iL8 + iM8 + iP8 <= 30;
iL9 + iM9 + iP9 <= 30; iL10 + iM10 + iP10 <= 30;
iL11 + iM11 + iP11 <= 30; iL12 + iM12 + iP12 <= 30;

// Inventário máximo final (produtos acabados):  40 unidades
fL1 + fM1 + fP1 <= 40; fL2 + fM2 + fP2 <= 40;
fL3 + fM3 + fP3 <= 40; fL4 + fM4 + fP4 <= 40;
fL5 + fM5 + fP5 <= 40; fL6 + fM6 + fP6 <= 40;
fL7 + fM7 + fP7 <= 40; fL8 + fM8 + fP8 <= 40;
fL9 + fM9 + fP9 <= 40; fL10 + fM10 + fP10 <= 40;
fL11 + fM11 + fP11 <= 40; fL12 + fM12 + fP12 <= 40;

// Capacidade máxima de produção: 30 unidades / período

xL1 + xM1 + xP1 <= 40; xL2 + xM2 + xP2 <= 40;
xL3 + xM3 + xP3 <= 40; xL4 + xM4 + xP4 <= 40;
xL5 + xM5 + xP5 <= 40; xL6 + xM6 + xP6 <= 40;
xL7 + xM7 + xP7 <= 40; xL8 + xM8 + xP8 <= 40;
xL9 + xM9 + xP9 <= 40; xL10 + xM10 + xP10 <= 40;
xL11 + xM11 + xP11 <= 40; xL12 + xM12 + xP12 <= 40;

///////////////////////////////////////////////////
//     Apenas 1 produto por período
///////////////////////////////////////////////////

no1: yL1 + yM1 + yP1 <=1;
no2: yL2 + yM2 + yP2 <=1;
no3: yL3 + yM3 + yP3 <=1;
no4: yL4 + yM4 + yP4 <=1;
no5: yL5 + yM5 + yP5 <=1;
no6: yL6 + yM6 + yP6 <=1;
no7: yL7 + yM7 + yP7 <=1;
no8: yL8 + yM8 + yP8 <=1;
no9: yL9 + yM9 + yP9 <=1;
no10: yL10 + yM10 + yP10 <=1;
no11: yL11 + yM11 + yP11 <=1;
no12: yL12 + yM12 + yP12 <=1;

xL1 <= 40 yL1; xL2 <= 40 yL2; xL3 <= 40 yL3; xL4 <= 40 yL4;
xL5 <= 40 yL5; xL6 <= 40 yL6; xL7 <= 40 yL7; xL8 <= 40 yL8;
xL9 <= 40 yL9; xL10 <= 40 yL10; xL11 <= 40 yL11; xL12 <= 40 yL12;

xM1 <= 40 yM1; xM2 <= 40 yM2; xM3 <= 40 yM3; xM4 <= 40 yM4;
xM5 <= 40 yM5; xM6 <= 40 yM6; xM7 <= 40 yM7; xM8 <= 40 yM8;
xM9 <= 40 yM9; xM10 <= 40 yM10; xM11 <= 40 yM11; xM12 <= 40 yM12;

xP1 <= 40 yP1; xP2 <= 40 yP2; xP3 <= 40 yP3; xP4 <= 40 yP4;
xP5 <= 40 yP5; xP6 <= 40 yP6; xP7 <= 40 yP7; xP8 <= 40 yP8;
xP9 <= 40 yP9; xP10 <= 40 yP10; xP11 <= 40 yP11; xP12 <= 40 yP12;

bin yL1,yM1,yP1,yL2,yM2,yP2,yL3,yM3,yP3,yL4,yM4,yP4;
bin yL5,yM5,yP5,yL6,yM6,yP6,yL7,yM7,yP7,yL8,yM8,yP8;
bin yL9,yM9,yP9,yL10,yM10,yP10,yL11,yM11,yP11,yL12,yM12,yP12;
