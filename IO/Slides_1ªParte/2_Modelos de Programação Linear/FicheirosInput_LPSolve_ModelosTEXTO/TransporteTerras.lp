
/*
     TRANSPORTE DE TERRAS

     Xpq = volume de terra a transportar [em m^3]
           da origem p para o destino q

     p \in {a,c,g,j}
     q \in {b,d,e,i,Dep}

     Cpq = custo de transporte (dist�ncia) [em U.M / m^3 ]
           entre a origem p e o destino q
*/

min: 10 Xab + 30 Xad + 40 Xae + 80 Xai +  40 XaDep
   + 20 Xcb + 10 Xcd + 20 Xce + 60 Xci +  40 XcDep
   + 50 Xgb + 30 Xgd + 20 Xge + 20 Xgi +  80 XgDep
   + 80 Xjb + 60 Xjd + 50 Xje + 10 Xji + 110 XjDep;

//   a soma dos volumes de terra que saem de uma dada zona de empr�stimo
//   para cada zona de dep�sito perfaz o volume a deslocar

      Xab +   Xad +   Xae +   Xai +   XaDep =  20 ; // (saem da zona a)
      Xcb +   Xcd +   Xce +   Xci +   XcDep =  10 ; // (saem da zona c)
      Xgb +   Xgd +   Xge +   Xgi +   XgDep = 160 ; // (saem da zona g)
      Xjb +   Xjd +   Xje +   Xji +   XjDep =  20 ; // (saem da zona j)

//   a soma dos volumes de terra que chegam a uma dada zona de dep�sito
//   de cada zona de empr�stimo perfaz o volume a depositar;

      Xab +   Xcb +   Xgb +   Xjb   = 50 ;  // (chegam � zona b)
      Xad +   Xcd +   Xgd +   Xjd   = 40 ;  // (chegam � zona d)
      Xae +   Xce +   Xge +   Xje   = 70 ;  // (chegam � zona e)
      Xai +   Xci +   Xgi +   Xji   = 30 ;  // (chegam � zona i)
      XaDep + XcDep + XgDep + XjDep = 20 ;  // (chegam ao Dep�sito)


