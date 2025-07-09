import java.util.Arrays;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.time.temporal.ChronoUnit;

//o this funciona como um apontador

public class Ex2 {
    private List<LocalDate> datas;

    public Ex2(){
        this.datas = new ArrayList<>();
    }

    //Ex2a)
    public void insereData(LocalDate data){
        this.datas.add(data);
    }

    //Ex2b)
    public LocalDate dataMaisProxima(LocalDate data){
        if(datas.isEmpty()){
            System.out.println("O array está vazio.");
            return null;
        }

        LocalDate dataMaisProxima = datas.get(0);
        long menorDiferenca = Math.abs(ChronoUnit.DAYS.between(data, dataMaisProxima));

        for(LocalDate d : datas){ //outra forma de colocar o for, mas funciona como os normais, percorrendo o array datas até ao final
            long diferenca = Math.abs(ChronoUnit.DAYS.between(data, d));
            if(diferenca < menorDiferenca){
                menorDiferenca = diferenca;
                dataMaisProxima = d;
            }
        }
        
        return dataMaisProxima;
    }

    //Ex2c)
    public void mostraDatas(){
        System.out.println("Array de datas: " + datas);
    }
}