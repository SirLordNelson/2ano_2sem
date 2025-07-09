
/*
     Sequenciação de tarefas com custos dependentes da sequência
     Exemplo do forno
*/

min:           1.5 x12 -0.2 x13 +0.3 x14 -0.8 x15
     -0.2 x21          +0.3 x23 +1.2 x24 -0.5 x25
     -0.3 x31 +2.1 x32          +0.9 x34 -0.6 x35
     -1.1 x41 -0.1 x42 -0.8 x43          -1.4 x45
     -0.8 x51 +0.6 x53 -0.5 x53 -0.2 x54         ;

/*    Há apenas um arco a sair do vértice     */
              x12 +   x13 +   x14 +   x15 =  1 ; // vértice 1
      x21         +   x23 +   x24 +   x25 =  1 ; // vértice 2
      x31 +   x32         +   x34 +   x35 =  1 ; // vértice 3
      x41 +   x42 +   x43         +   x45 =  1 ; // vértice 4
      x51 +   x53 +   x53 +   x54         =  1 ; // vértice 5
      
/*    Há apenas um arco a entrar no vértice   */
              x21 +   x31 +   x41 +   x51 =  1 ;  // vértice 1
      x12         +   x32 +   x42 +   x52 =  1 ;  // vértice 2
      x13 +   x23         +   x43 +   x53 =  1 ;  // vértice 3
      x14 +   x24 +   x34         +   x54 =  1 ;  // vértice 4
      x15 +   x25 +   x35 +   x45         =  1 ;  // vértice 5


