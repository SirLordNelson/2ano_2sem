import java.time.LocalDateTime;
import java.util.Arrays;

public class Encomenda{
    private String nomeCliente;
    private int nif;
    private String morada;
    private String numEncomenda;
    private LocalDateTime dataEncomenda;
    private LinhaEncomenda[] linhaEncomendas;

    public Encomenda(){
        this.nomeCliente = "";
        this.nif = 0;
        this.morada = "";
        this.numEncomenda = "";
        this.dataEncomenda = LocalDateTime.now();
        this.linhaEncomendas = new LinhaEncomenda[10];
    }

    public Encomenda(String nomeCliente, int nif, String morada, String numEncomenda, LinhaEncomenda[] linhaEncomendas, LocalDateTime dataEncomenda){
        this.nomeCliente = nomeCliente;
        this.nif = nif;
        this.morada = morada;
        this.numEncomenda = numEncomenda;
        this.linhaEncomendas = linhaEncomendas;
        this.dataEncomenda = dataEncomenda;
    }

    public Encomenda(Encomenda encomenda){
        this.nomeCliente = encomenda.getNomeCliente();
        this.nif = encomenda.getNif();
        this.morada = encomenda.getMorada();
        this.numEncomenda = encomenda.getNumEncomenda();
        this.dataEncomenda = encomenda.getDataEncomenda();
        this.linhaEncomendas = Arrays.copyOf(encomenda.getLinhaEncomendas(), encomenda.getLinhaEncomendas().length);
    }

    //Getters
    public String getNomeCliente(){return nomeCliente;}
    public int getNif(){return nif;}
    public String getMorada(){return morada;}
    public LocalDateTime getDataEncomenda(){return dataEncomenda;}
    public String getNumEncomenda(){return numEncomenda;}
    public LinhaEncomenda[] getLinhaEncomendas(){return linhaEncomendas;}

    //Setters
    public void setNomeCliente(String nomeCliente){this.nomeCliente = nomeCliente;}
    public void setNif(int nif){this.nif = nif;}
    public void setMorada(String morada){this.morada = morada;}
    public void setDataEncomenda(LocalDateTime dataEncomenda){this.dataEncomenda = dataEncomenda;}
    public void setNumEncomenda(String numEncomenda){this.numEncomenda = numEncomenda;}
    public void setLinhaEncomendas(LinhaEncomenda[] linhaEncomendas){this.linhaEncomendas = linhaEncomendas;}

    @Override
    public String toString(){
        return "Encomenda{" +
                "nomeCliente='" + nomeCliente + '\'' +
                ", nif=" + nif +
                ", morada='" + morada + '\'' +
                ", numEncomenda='" + numEncomenda + '\'' +
                ", dataEncomenda=" + dataEncomenda +
                ", linhaEncomendas=" + Arrays.toString(linhaEncomendas) +
                '}';
    }

    //Ex 10b)
    public double calculaValorTotal(){
        double total = 0.0;
        for(LinhaEncomenda l : this.getLinhaEncomendas()){
            if(l != null) total = total + l.calculaValorLinhaEnc();
        }
        return total;
    }

    //Ex 10c)
    public double calculaValorDesconto(){
        double totalD = 0.0;
        for(LinhaEncomenda l : this.getLinhaEncomendas()){
            if(l != null) totalD = totalD + l.calculaValorDesconto();
        }
        return total;
    }

    //Ex 10d)
    public int numeroTotalProdutos(){
        int num = 0;
        for(LinhaEncomenda l : this.getLinhaEncomendas()){
            if(l != null) num = num + l.getQuantity();
        }
        return num;
    }

    //Ex 10e)
    public boolean existeProdutoEncomenda(String refProduto){
        for(LinhaEncomenda l : this.getLinhaEncomendas()){
            if(refProduto == l.getReference()) return true;
        }
        return false;
    }
}