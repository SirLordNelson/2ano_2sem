import java.util.Arrays;

public class Ficha2{
    private int[] colecao;

    public Ficha2(int[] colecao){
        this.colecao = colecao;
    };

    //Ex 1a)
    public int calculaMinimo(){
        int min = Integer.MAX_VALUE;

        for(int valor : this.colecao){
            if(valor < min) min = valor;
        }

        return min;
    }

    //Ex 1b)
    public int[] subArray(int idx1, int idx2){
        int[] subarray = Arrays.copyOfRange(this.colecao, idx1, idx2);
        return subarray;
    }

    //Ex 1c)
    public int[] cmpArray(int[] array1, int[] array2){
        int[] res = new int[array1.length];

        for(int i = 0; i < array1.length; i++){
            for(int j = 0; j < array2.length; j++){
                if(array1[i] == array2[j]) res[j] = array2[j];
            }
        }
        
        return res;
    }

    //Ex 3a)
    public int[] ordenaArray(int[] array){
        for(int i = 0; i < array.length; i++){
            for(int j = 0; j < array.length-i-1; j++){
                int temp;
                if(array[j] > array[j+1]){
                    temp = array[j];
                    array [j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
        return array;
    }

    //Ex 3b)
    public int procuraBin(int[] array, int x){
        int esquerda = 0;
        int direita = array.length - 1;

        while(esquerda <= direita){
            int meio = esquerda + (direita - esquerda) / 2;

            if (array[meio] == x) return meio;

            if (array[meio] < x) esquerda = meio + 1;

            else direita = meio - 1;
        }

        return -1;
    }
}