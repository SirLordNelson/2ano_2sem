import java.util.Scanner;
import java.util.Arrays;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        
        int lenght = scanner.nextInt();
        int[] colecao = new int[lenght];

        System.out.println("Introduza " + lenght + " inteiros.");

        for(int idx = 0; idx < colecao.length; idx++){
            int auxiliar = scanner.nextInt();
            colecao[idx] = auxiliar;
        }

        Ficha2 ficha = new Ficha2(colecao);

        //Ex 1a)
        int minimo = ficha.calculaMinimo();
        
        System.out.println("O mínimo é: " + minimo);

        //Ex 1b)
        System.out.println("Introduza dois índices para criar.");
        System.out.println("Introduza o índice 1:");
        int idx1 = scanner.nextInt();
        System.out.println("Introduza o índice 2:");
        int idx2 = scanner.nextInt();

        int[] resultado_sub_array = ficha.subArray(idx1, idx2);

        System.out.println("O sub Array é " + Arrays.toString(resultado_sub_array));
        
        //Ex 1c)
        System.out.println("Defina o tamanho do segundo array:");
        int comp_array2 = scanner.nextInt();
        System.out.println("Defina o segundo array:");
        int[] array2 = new int[comp_array2];

        for(int i = 0; i < array2.length; i++){
            int aux = scanner.nextInt();
            array2[i] = aux;
        }

        int[] res = ficha.cmpArray(colecao, array2);

        System.out.println("Os comuns são: " + Arrays.toString(res));

       //Ex 3a)
        int[] res = ficha.ordenaArray(colecao);

        System.out.println("Array ordenado: " + Arrays.toString(res));

       //Ex 3b)
       int x = scanner.nextInt();

       int res = ficha.procuraBin(colecao, x);

       System.out.println("O elemento desejado encontra-se na posição: " + res);
    }
}