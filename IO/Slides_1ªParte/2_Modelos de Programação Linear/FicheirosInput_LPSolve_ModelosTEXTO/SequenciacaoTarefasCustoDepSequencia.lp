
/*
     Sequencia��o de tarefas com custos dependentes da sequ�ncia
     Exemplo do forno
*/

min:           1.5 x12 -0.2 x13 +0.3 x14 -0.8 x15
     -0.2 x21          +0.3 x23 +1.2 x24 -0.5 x25
     -0.3 x31 +2.1 x32          +0.9 x34 -0.6 x35
     -1.1 x41 -0.1 x42 -0.8 x43          -1.4 x45
     -0.8 x51 +0.6 x53 -0.5 x53 -0.2 x54         ;

/*    H� apenas um arco a sair do v�rtice     */
              x12 +   x13 +   x14 +   x15 =  1 ; // v�rtice 1
      x21         +   x23 +   x24 +   x25 =  1 ; // v�rtice 2
      x31 +   x32         +   x34 +   x35 =  1 ; // v�rtice 3
      x41 +   x42 +   x43         +   x45 =  1 ; // v�rtice 4
      x51 +   x53 +   x53 +   x54         =  1 ; // v�rtice 5
      
/*    H� apenas um arco a entrar no v�rtice   */
              x21 +   x31 +   x41 +   x51 =  1 ;  // v�rtice 1
      x12         +   x32 +   x42 +   x52 =  1 ;  // v�rtice 2
      x13 +   x23         +   x43 +   x53 =  1 ;  // v�rtice 3
      x14 +   x24 +   x34         +   x54 =  1 ;  // v�rtice 4
      x15 +   x25 +   x35 +   x45         =  1 ;  // v�rtice 5


