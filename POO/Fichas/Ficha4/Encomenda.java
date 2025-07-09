import java.util.List;
import java.util.ArrayList;
import java.time.LocalDate;

public class Encomenda{
    private static int numEncomenda = 0;
    private String nomeCliente;
    private int nif;
    private String morada;
    private int nEnc;
    private LocalDate data;
    private List<LinhaEncomenda> linhas;

    public Encomenda(String nomeCliente, int nif, String morada, LocalDate data, List<LinhaEncomenda> linhasEnc){
        this.nomeCliente = nomeCliente;
        this.nif = nif;
        this.morada = morada;
        this.data = data;
        this.nEnc = numEncomenda++;
        this.linhas = new ArrayList<>(linhasEnc);
    }

    // Getters
    public String getNomeCliente(){return nomeCliente;}
    public int getNif(){return nif;}
    public String getMorada(){return morada;}
    public LocalDate getDataEncomenda(){return data;}
    public int getNumEncomenda(){return nEnc;}
    public List<LinhaEncomenda> getLinhaEncomenda(){return linhas;}

    // Setters
    public void setNomeCliente(String nomeCliente){this.nomeCliente = nomeCliente;}
    public void setNif(int nif){this.nif = nif;}
    public void setMorada(String morada){this.morada = morada;}
    public void setDataEncomenda(LocalDate data){this.data = data;}
    public void setLinhaEncomenda(List<LinhaEncomenda> linhas){this.linhas = new ArrayList<>(linhas);}

    public void addLinhaEncomenda(LinhaEncomenda linha){this.linhas.add(linha);}

    @Override
    public String toString(){
        return "Encomenda{" +
                "nomeCliente='" + nomeCliente + '\'' +
                ", nif=" + nif +
                ", morada='" + morada + '\'' +
                ", nEnc=" + nEnc +
                ", data=" + data +
                ", linhas=" + linhas +
                '}';
    }

    //Ex 2b)
    public double calculaValorTotal(){
        double total = 0.0;
        List<LinhaEncomenda> l = this.getLinhaEncomenda();
        for (LinhaEncomenda linha : l){
            total += linha.calculaValorLinhaEnc();
        }
        return total;
    }

    
    //Ex 2c)
    public double calculaValorDesc(){
        double totalD = 0.0;
        List<LinhaEncomenda> l = this.getLinhaEncomenda();
        for(LinhaEncomenda linha : l){
            totalD = totalD + linha.calculaValorDesconto();
        }
        return totalD;
    }

    //Ex 2d)
    public int numeroTotalProdutos(){
        int num = 0;
        List<LinhaEncomenda> l = this.getLinhaEncomenda();
        for(LinhaEncomenda linha : l){
            num = num + linha.getQuantidade();
        }
        return num;
    }

    //Ex 2e)
    public boolean existeProdutoEncomenda(String refProduto){
        List<LinhaEncomenda> l = this.getLinhaEncomenda();
        for(LinhaEncomenda linha : l){
            if(refProduto == linha.getReferencia()) return true;
        }
        return false;
    }
}