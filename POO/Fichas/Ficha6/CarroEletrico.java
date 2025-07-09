import java.util.Objects;

public class CarroEletrico extends Carro {
    private int capacidadeBateria; // em kWh
    private int precoKW; // em euros
    private int consumoCem; // em kWh

    // Getters e Setters
    public int getCapacidadeBateria() {return capacidadeBateria;}
    public void setCapacidadeBateria(int capacidadeBateria) {this.capacidadeBateria = capacidadeBateria;}
    public int getConsumoCem() {return consumoCem;}
    public void setConsumoCem(int consumoCem) {this.consumoCem = consumoCem;}
    public int getPrecoKW() {return precoKW;}
    public void setPrecoKW(int precoKW) {this.precoKW = precoKW;}

    // Construtors
    public CarroEletrico(String matricula, String marca, String modelo, int ano, int velocidadeMedia, Float consumoCemPorH, int autonomia, int kmsRealizados, int capacidadeBateria, int precoKW, int consumoCem) {
        super(matricula, marca, modelo, ano, velocidadeMedia, consumoCemPorH, autonomia, kmsRealizados);
        this.capacidadeBateria = capacidadeBateria;
        this.precoKW = precoKW;
        this.consumoCem = consumoCem;
    }

    public CarroEletrico(int capacidadeBateria, int precoKW, int consumoCem) {
        this.capacidadeBateria = capacidadeBateria;
        this.precoKW = precoKW;
        this.consumoCem = consumoCem;
    }

    public CarroEletrico(Carro carro, int capacidadeBateria, int precoKW, int consumoCem) {
        super(carro);
        this.capacidadeBateria = capacidadeBateria;
        this.precoKW = precoKW;
        this.consumoCem = consumoCem;
    }

    // Equals, HashCode e toString

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        CarroEletrico that = (CarroEletrico) o;
        return capacidadeBateria == that.capacidadeBateria && precoKW == that.precoKW && consumoCem == that.consumoCem;
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), capacidadeBateria, precoKW, consumoCem);
    }

    @Override
    public String toString() {
        return "CarroEletrico{" +
                "capacidadeBateria=" + capacidadeBateria +
                ", precoKW=" + precoKW +
                ", consumoCem=" + consumoCem +
                ", matricula='" + matricula + '\'' +
                ", marca='" + marca + '\'' +
                ", modelo='" + modelo + '\'' +
                ", ano=" + ano +
                ", velocidadeMedia=" + velocidadeMedia +
                ", consumoCemPorH=" + consumoCemPorH +
                ", autonomia=" + autonomia +
                ", kmsRealizados=" + kmsRealizados +
                '}';
    }

    //Funções que dão jeito
    public int custoKM(CarroEletrico c){
        return (consumoCem/100) * precoKW;
    }
}