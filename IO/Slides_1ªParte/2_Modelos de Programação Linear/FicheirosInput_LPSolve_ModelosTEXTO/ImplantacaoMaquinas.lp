
/*
     Implanta��o deM�quinas num layout existente
     Problema de afecta��o
*/

min:  64 x11 + 93 x12 + 66 x13 +104 x14
    +118 x21 +128 x22 +137 x23 + 57 x24
    + 37 x31 +144 x32 +115 x33 +160 x34
    +  0 x41 +  0 x42 +  0 x43 +  0 x44;

/*    A m�quina deve ser implantada num local       */
      x11 +   x12 +   x13 +   x14  =  1 ; // m�quina R
      x21 +   x22 +   x23 +   x24  =  1 ; // m�quina S
      x31 +   x32 +   x33 +   x34  =  1 ; // m�quina T
      x41 +   x42 +   x43 +   x44  =  1 ; // m�quina fict�cia
//    A restri��o da m�quina fict�cia modela o facto de um dos
//    locais poss�veis de implanta��o ficar vazio
      
/*    Cada local pode receber apenas uma m�quina   */
      x11 +   x21 +   x31 +   x41  =  1 ;  // local W
      x12 +   x22 +   x32 +   x42  =  1 ;  // local X
      x13 +   x23 +   x33 +   x43  =  1 ;  // local Y
      x14 +   x24 +   x34 +   x44  =  1 ;  // local Z


