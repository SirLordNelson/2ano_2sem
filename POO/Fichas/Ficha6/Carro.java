import java.util.Objects;

public class Carro{
    public String matricula;
    public String marca;
    public String modelo;
    public int ano;
    public int velocidadeMedia;
    public Float consumoCemPorH;
    public int autonomia;
    public int kmsRealizados;

    //Getters e Setters
    public String getMatricula() {return matricula;}
    public void setMatricula(String matricula) {this.matricula = matricula;}
    public String getMarca() {return marca;}
    public void setMarca(String marca) {this.marca = marca;}
    public String getModelo() {return modelo;}
    public void setModelo(String modelo) {this.modelo = modelo;}
    public int getVelocidadeMedia() {return velocidadeMedia;}
    public void setVelocidadeMedia(int velocidadeMedia) {this.velocidadeMedia = velocidadeMedia;}
    public int getAno() {return ano;}
    public void setAno(int ano) {this.ano = ano;}
    public Float getConsumoCemPorH() {return consumoCemPorH;}
    public void setConsumoCemPorH(Float consumoCemPorH) {this.consumoCemPorH = consumoCemPorH;}
    public int getAutonomia() {return autonomia;}
    public void setAutonomia(int autonomia) {this.autonomia = autonomia;}
    public int getKmsRealizados() {return kmsRealizados;}
    public void setKmsRealizados(int kmsRealizados) {this.kmsRealizados = kmsRealizados;}

    //Constructors
    public Carro(String matricula, String marca, String modelo, int ano, int velocidadeMedia, Float consumoCemPorH, int autonomia, int kmsRealizados) {
        this.matricula = matricula;
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
        this.velocidadeMedia = velocidadeMedia;
        this.consumoCemPorH = consumoCemPorH;
        this.autonomia = autonomia;
        this.kmsRealizados = kmsRealizados;
    }

    public Carro(){}

    public Carro(Carro carro) {
        this.matricula = carro.matricula;
        this.marca = carro.marca;
        this.modelo = carro.modelo;
        this.ano = carro.ano;
        this.velocidadeMedia = carro.velocidadeMedia;
        this.consumoCemPorH = carro.consumoCemPorH;
        this.autonomia = carro.autonomia;
        this.kmsRealizados = carro.kmsRealizados;
    }

    //Equals, HashCode e toString
    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Carro carro = (Carro) o;
        return ano == carro.ano && velocidadeMedia == carro.velocidadeMedia && autonomia == carro.autonomia && kmsRealizados == carro.kmsRealizados && Objects.equals(matricula, carro.matricula) && Objects.equals(marca, carro.marca) && Objects.equals(modelo, carro.modelo) && Objects.equals(consumoCemPorH, carro.consumoCemPorH);
    }

    @Override
    public int hashCode() {
        return Objects.hash(matricula, marca, modelo, ano, velocidadeMedia, consumoCemPorH, autonomia, kmsRealizados);
    }

    @Override
    public String toString() {
        return "Carro{" +
                "matricula='" + matricula + '\'' +
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
    public int atualizaAutonomia(Carro c){
        return c.autonomia = autonomia - c.kmsRealizados;
    }

    public abstract custoKM();
}