import java.util.Scanner;
import java.util.Arrays;

//"this" refere-se ao objeto com que vamos trabalhar

//Ex 1
public class Circulo{
    private double x;
    private double y;
    private double raio;

    //inicializa as variáveis
    public Circulo(){
        this.x = 0.0;
        this.y = 0.0;
        this.raio = 0.0;
    };

    //cria um objeto
    public Circulo(double x, double y, double raio){
        this.x = x;
        this.y = y;
        this.raio = raio;
    }

    //cria uma cópia de um objeto
    public Circulo(Circulo circulo){
        this.x = circulo.getX();
        this.y = circulo.getY();
        this.raio = circulo.getRaio();
    }

    //getters
    public double getX(){
        return x;
    }

    public double getY(){
        return y;
    }

    public double getRaio(){
        return raio;
    }

    //setters
    public void setX(double x){
        this.x = x;
    }

    public void setY(double y){
        this.y = y;
    }

    public void setRaio(double raio){
        this.raio = raio;
    }

    //e)
    public void alteraCentro(double x, double y){
        this.setX(x);
        this.setY(y);
    }

    //f)
    public double calculaArea(){
        double area = Math.PI * Math.pow(this.getRaio(), 2);

        return area;
    }

    //g)
    public double calculaPerimetro(){
        double perimetro = 2 * Math.PI * this.getRaio();

        return perimetro;
    }

    //outras
    public String toString(){
        return "Circulo{" + "x=" + x + ", y=" + y + ", raio=" + raio + "}";
    }

    public Circulo clone(){
        return new Circulo(this);
    }
}