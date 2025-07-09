/* Objective function */
min:    15 x11 + 12 x12 + 10 x13 +  9 x14 +
         8 x21 +  4 x22 +  8 x23 +  6 x24 ;

/* Restricões */
machine1:  3 x11 +  4 x12 +  5 x13 +  6 x14 <= 10;
machine2:  4 x21 +  5 x22 +  8 x23 +  4 x24 <= 12;

job1: x11 + x21 = 1;
job2: x12 + x22 = 1;
job3: x13 + x23 = 1;
job4: x14 + x24 = 1;

/* Restricões de integralidade */
bin x11, x12, x13, x14;
bin x21, x22, x23, x24;



