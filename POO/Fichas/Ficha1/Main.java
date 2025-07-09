import java.util.Scanner;
import java.time.LocalDateTime;
import java.time.Duration;
import java.time.temporal.ChronoUnit;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in); //in -> input

        Ficha1 ficha = new Ficha1();

        //Ex. 5.1
        double temp = scanner.nextDouble();
        
        double far = ficha.celsiusParaFarenheit(temp);

        System.out.println("" + temp + " em C, corresponde a " + far + " em Farenheit");
    
       //Ex. 5.2
       int temp1 = scanner.nextInt();
       int temp2 = scanner.nextInt();

        int max = ficha.maximoNumeros(temp1, temp2);

        System.out.println("Entre " + temp1 + " e " + temp2 + ", o maior é " + max + ".");

       //Ex. 5.3
       String name = scanner.nextLine();

       double saldo = scanner.nextDouble();

       String sal = ficha.criaDescricaoConta(name, saldo);

       System.out.println(sal);

      //Ex 5.4
        //para demarcar casas decimais, usa-se uma vírgula em vez de um ponto
      double euro = scanner.nextDouble();
      double taxa = scanner.nextDouble();

      double libra = ficha.eurosParaLibras(euro, taxa);

      System.out.println(libra);

     //Ex 5.5
     int pri = scanner.nextInt();
     int sec = scanner.nextInt();

     int res = ficha.decresceEmedia(pri, sec);

     System.out.println("A média é:" + res);

    //Ex 5.6
    int num = scanner.nextInt();

    long res = ficha.factorial(num);

    System.out.println(res);

   //Ex 5.7
   long res = ficha.tempoGasto();

   System.out.println(res);
  

   //Ex 3.1
   int dia = scanner.nextInt();
   int mês = scanner.nextInt();
   int ano = scanner.nextInt();

   ano = (ano - 1900) * 365;
   ano = ano + ((ano-1900)/4);

    boolean ehBissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);

    if (ehBissexto && (mês == 1 || mês == 2)) ano -= 1;
    
    int[] diasPorMes = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (ehBissexto) diasPorMes[2] = 29; // Fevereiro tem 29 dias em anos bissextos

    int diasPassados = 0;

    //conta quantos dias já passaram desde o início do ano
    for (int i = 1; i < mês; i++) {
      diasPassados += diasPorMes[i];
    }

    diasPassados += dia - 1; // Subtrai 1 porque o dia atual ainda não foi completado

    ano += diasPassados;

    // Passo (b): Calcula o resto da divisão por 7
    int resto = ano % 7;

    // Passo (c): O resto é o dia da semana (0 = Domingo, 1 = Segunda, ..., 6 = Sábado)
    String[] diasDaSemana = {"Segunda-feira", "Terça-feira", "Quarta-feira", "Quinta-feira", "Sexta-feira", "Sábado", "Domingo"};
    System.out.println("O dia da semana é: " + diasDaSemana[resto]);

   //Ex 3.2
   int dia1 = scanner.nextInt();
   int hora1 = scanner.nextInt();
   int min1 = scanner.nextInt();
   int sec1 = scanner.nextInt();

   int dia2 = scanner.nextInt();
   int hora2 = scanner.nextInt();
   int min2 = scanner.nextInt();
   int sec2 = scanner.nextInt();

   int totalSegundos = sec1 + sec2;
   int totalMinutos = min1 + min2;
   int totalHoras = hora1 + hora2;
   int totalDias = dia1 + dia2;

   // Ajusta os segundos e minutos
   totalMinutos += totalSegundos / 60;
   totalSegundos = totalSegundos % 60;

   // Ajusta os minutos e horas
   totalHoras += totalMinutos / 60;
   totalMinutos = totalMinutos % 60;

   // Ajusta as horas e dias
   totalDias += totalHoras / 24;
   totalHoras = totalHoras % 24;

   // printf -> permite formatar a string usando %d para inteiros.
   System.out.printf("%dD %dH %dM %dS\n", totalDias, totalHoras, totalMinutos, totalSegundos);

  //Ex 3.3
  int n = scanner.nextInt();
  int contador0a5 = 0;
  int contador5a10 = 0;
  int contador10a15 = 0;
  int contador15a20 = 0;

  for (int i = 0; i < n; i++) {
    System.out.print("Digite a classificação " + (i + 1) + ": ");
    double classificacao = scanner.nextDouble();

    if (classificacao >= 0 && classificacao < 5) contador0a5++;
    else if (classificacao >= 5 && classificacao < 10) contador5a10++;
    else if (classificacao >= 10 && classificacao < 15) contador10a15++;
    else if (classificacao >= 15 && classificacao <= 20) contador15a20++;
    else System.out.println("Classificação fora do intervalo válido");
  }

  System.out.println("\nNúmero de classificações em cada intervalo:");
  System.out.println("[0, 5[: " + contador0a5);
  System.out.println("[5, 10[: " + contador5a10);
  System.out.println("[10, 15[: " + contador10a15);
  System.out.println("[15, 20]: " + contador15a20);
  
  //Ex 3.4
  System.out.print("Digite o número de temperaturas (pelo menos 2): ");
  int n = scanner.nextInt();

  if (n < 2) {
    System.out.println("É necessário pelo menos 2 temperaturas.");
    return;
  }

  int[] temperaturas = new int[n];
    for (int i = 0; i < n; i++) {
      System.out.print("Digite a temperatura do dia " + (i + 1) + ": ");
      temperaturas[i] = scanner.nextInt();
    }

  int soma = 0;
  for (int temp : temperaturas) {
    soma += temp;
  }
  
  double media = (double) soma / n;

  int maiorVariacao = 0;
  int diaMaiorVariacao = 1; // Dia inicial (dia 2, pois comparamos com o dia anterior)
  int variacaoEfetiva = 0;

  for (int i = 1; i < n; i++) {
    int variacao = temperaturas[i] - temperaturas[i - 1];
    int variacaoAbsoluta = Math.abs(variacao);

    if (variacaoAbsoluta > maiorVariacao) {
      maiorVariacao = variacaoAbsoluta;
      diaMaiorVariacao = i + 1; // Dia atual (i + 1 porque os dias começam em 1)
      variacaoEfetiva = variacao;
      }
    }

    System.out.printf("A média das %d temperaturas foi de %.1f graus.\n", n, media);

    if (variacaoEfetiva < 0) {
      System.out.printf("A maior variação registou-se entre os dias %d e %d, tendo a temperatura descido %d graus.\n",
        diaMaiorVariacao - 1, diaMaiorVariacao, Math.abs(variacaoEfetiva));
    }else {
      System.out.printf("A maior variação registou-se entre os dias %d e %d, tendo a temperatura subido %d graus.\n",
      diaMaiorVariacao - 1, diaMaiorVariacao, variacaoEfetiva);
    }
  
   //Ex 3.5
   double base = scanner.nextDouble();
   double altura = scanner.nextDouble();

   double area = (base * altura) / 2;

   double hip = Math.sqrt((base*base) + (altura*altura));
   double perimetro = base + altura + hip;

   System.out.printf("A área é %.5f e o perímetro é %.5f.\n", area, perimetro);
   
   //Ex 3.6
    boolean jogarNovamente = true;

    while (jogarNovamente) {
      System.out.print("Digite um número inteiro n: ");
      int n = scanner.nextInt();

      // Verifica e imprime os números primos inferiores a n
      System.out.println("Números primos inferiores a " + n + ":");
      for (int i = 2; i < n; i++) {
        if (ehPrimo(i)) System.out.print(i + " ");
      }
      System.out.println(); // Pula uma linha após a lista de primos

      System.out.print("Deseja jogar novamente? (s/n): ");
      char resposta = scanner.next().charAt(0); //pega o primeiro caracter da string
      if (resposta != 's' && resposta != 'S') jogarNovamente = false;
    }

    System.out.println("Programa encerrado. Obrigado por jogar!");
    scanner.close();
    // específico deste exercício     }

    // Método auxiliar para verificar se um número é primo
    public static boolean ehPrimo(int numero){
        if (numero < 2) return false;

        for (int i = 2; i <= Math.sqrt(numero); i++) {
            if (numero % i == 0) return false;
        }
        return true;
    }

   //Ex 3.7
  System.out.println("Digite sua data de nascimento:");
        
  System.out.print("Ano: ");
  int ano = scanner.nextInt();
  System.out.print("Mês (1-12): ");
  int mes = scanner.nextInt();      
  System.out.print("Dia: ");
  int dia = scanner.nextInt();

  LocalDateTime dataHoraAtual = LocalDateTime.now();  
  LocalDateTime dataNascimento = LocalDateTime.of(ano, mes, dia, 0, 0);

  long horasVividas = ChronoUnit.HOURS.between(dataNascimento, dataHoraAtual); //enum que representa unidades de tempo, neste caso, horas
        
  System.out.println("\n=== Resultado do Cálculo ===");
  System.out.println("Data e hora atual: " + dataHoraAtual.getDayOfMonth() + "/" + dataHoraAtual.getMonthValue() + "/" + 
            dataHoraAtual.getYear() + " " + String.format("%02d:%02d:%02d", dataHoraAtual.getHour(), dataHoraAtual.getMinute(), 
            dataHoraAtual.getSecond()));
        
  System.out.println("Sua idade em horas: " + horasVividas + " horas");
        
  long dias = horasVividas / 24;
  long anos = dias / 365;
        
  System.out.println("\nIsso equivale aproximadamente a:");
  System.out.println(anos + " anos");
  System.out.println(dias + " dias");
        
  scanner.close();
  }
}