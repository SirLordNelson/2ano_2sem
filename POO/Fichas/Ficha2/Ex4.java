import java.util.Arrays;

public class Ex4 {
    public String[] strings;

    //Ex4a)
    public String insereString(String input){
        return input;
    }

    //Ex4b)
    public String determinaMaiorString(){
        if(strings == null || strings.length == 0) return null;

        String maior = strings[0];
        for(String str : strings){ //para cada string str no array strings
            if (str.length() > maior.length()) maior = str;
        }
        return maior;
    }

    //Ex4c)
    public String maisRepetida(){
        int mr = 0;
        String maisrep = strings[0];

        for(int i = 0; i < strings.length; i++){
            int mp = 0;
            for(int j = 0; j < strings.length; j++){
                if(strings[i].equals(strings[j])) mp++;
            }
            if(mr < mp){
                mr = mp;
                maisrep = strings[i];
            }
        }
        return maisrep;
    }

    //Ex4d)
    public int strRepetida(String s){
        int mp = 0;
        for(int i = 0; i < strings.length; i++){
            if(s.equals(strings[i])) mp++;
        }
        return mp;
    }

    public void mostraString(){
        if(strings == null || strings.length == 0){
            System.out.println("O array está vazio.");
            return;
        }

        System.out.println("Strings inseridas:");
        for(String str : strings){
            System.out.println(str);
        }
    }
}