import java.util.Objects;

public class CarroCombustao extends Carro {
    private int capacidadeDeposito; // em L
    private int precoLitro; // em euros
    private int consumoCem; // em L

    // Getters e Setters
    public int getCapacidadeDeposito() {return capacidadeDeposito;}
    public void setCapacidadeDeposito(int capacidadeDeposito) {this.capacidadeDeposito = capacidadeDeposito;}
    public int getPrecoLitro() {return precoLitro;}
    public void setPrecoLitro(int precoLitro) {this.precoLitro = precoLitro;}
    public int getConsumoCem() {return consumoCem;}
    public void setConsumoCem(int consumoCem) {this.consumoCem = consumoCem;}

    //Constructors
    public CarroCombustao(String matricula, String marca, String modelo, int ano, int velocidadeMedia, Float consumoCemPorH, int autonomia, int kmsRealizados, int capacidadeDeposito, int consumoCem, int precoLitro) {
        super(matricula, marca, modelo, ano, velocidadeMedia, consumoCemPorH, autonomia, kmsRealizados);
        this.capacidadeDeposito = capacidadeDeposito;
        this.consumoCem = consumoCem;
        this.precoLitro = precoLitro;
    }

    public CarroCombustao(int capacidadeDeposito, int consumoCem, int precoLitro) {
        this.capacidadeDeposito = capacidadeDeposito;
        this.consumoCem = consumoCem;
        this.precoLitro = precoLitro;
    }

    public CarroCombustao(Carro carro, int capacidadeDeposito, int consumoCem, int precoLitro) {
        super(carro);
        this.capacidadeDeposito = capacidadeDeposito;
        this.consumoCem = consumoCem;
        this.precoLitro = precoLitro;
    }

    // Equals, HashCode e toString

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        CarroCombustao that = (CarroCombustao) o;
        return capacidadeDeposito == that.capacidadeDeposito && precoLitro == that.precoLitro && consumoCem == that.consumoCem;
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), capacidadeDeposito, precoLitro, consumoCem);
    }

    @Override
    public String toString() {
        return "CarroCombustao{" +
                "capacidadeDeposito=" + capacidadeDeposito +
                ", precoLitro=" + precoLitro +
                ", consumoCem=" + consumoCem +
                ", matricula='" + matricula + '\'' +
                ", marca='" + marca + '\'' +
                ", modelo='" + modelo + '\'' +
                ", consumoCemPorH=" + consumoCemPorH +
                ", ano=" + ano +
                ", velocidadeMedia=" + velocidadeMedia +
                ", autonomia=" + autonomia +
                ", kmsRealizados=" + kmsRealizados +
                '}';
    }

    //Funções que dão jeito
    public int custoKM(){
        return this.precoLitro * (this.consumoCem/100);
    }
}