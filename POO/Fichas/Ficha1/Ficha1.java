import java.time.LocalDateTime;
import java.time.Duration;

public class Ficha1{
    public Ficha1(){};

    //Ex. 5.1
    public double celsiusParaFarenheit(double graus){
        double far = (graus * 9/5) + 32;

        return far;
    }

   //Ex. 5.2
   public int maximoNumeros(int a, int b){
        if(a < b) return b;
        else return a;
   }

  //Ex. 5.3
  public String criaDescricaoConta(String nome, double saldo){
        String key = "O saldo de " + nome + " é: " + saldo + ".";

        return key;
  }
  
 //Ex 5.4
    public double eurosParaLibras(double valor, double taxaConversao){
        double val = valor * taxaConversao;

        return val;
    }

    //Ex 5.5
   public int decresceEmedia(int a, int b){
        if(a < b){
            System.out.println(b);
            System.out.println(a);
        }
        else{
            System.out.println(a);
            System.out.println(b);
        }
        return (a+b)/2;
   }
   
  //Ex 5.6
  //recursivamente
  public long factorial(int num){
    if(num < 1) return 1;
    return num * factorial(num-1);
  }
 
  //iterativamente
  public long factorial(int num){
    long temp = num;

    while(num > 1){
        num--;
        temp = temp * num;
    }

    return temp;
  }
    
   //Ex 5.7
 public long tempoGasto(){
   LocalDateTime inicio = LocalDateTime.now();

    long res = factorial(5000);

    LocalDateTime fim = LocalDateTime.now();

    //as próximas chamadas usam funções da biblioteca Duration
    Duration duracao = Duration.between(inicio, fim);
    long tempoGasto = duracao.toMillis();

    return tempoGasto;
 }
}