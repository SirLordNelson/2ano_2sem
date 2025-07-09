//Ex 11
public class Triangulo{
    private Ponto ponto1 = new Ponto(0.0, 0.0);
    private Ponto ponto2 = new Ponto(1.0, 0.0);
    private Ponto ponto3 = new Ponto(1.0, 1.0);

    public Triangulo(Ponto ponto1, Ponto ponto2, Ponto ponto3){
        this.ponto1 = ponto1;
        this.ponto2 = ponto2;
        this.ponto3 = ponto3;
    }

    public Triangulo(Triangulo triangulo){
        this.ponto1 = triangulo.getPonto1();
        this.ponto2 = triangulo.getPonto2();
        this.ponto3 = triangulo.getPonto3();
    }

    //getter
    public Ponto getPonto1(){
        return ponto1;
    }

    public Ponto getPonto2(){
        return ponto2;
    }

    public Ponto getPonto3(){
        return ponto3;
    }

    //setter
    public void setPonto1(Ponto ponto1){
        this.ponto1 = ponto1;
    }

    public void setPonto2(Ponto ponto2){
        this.ponto2 = ponto2;
    }

    public void setPonto3(Ponto ponto3){
        this.ponto3 = ponto3;
    }

    private double distancia(Ponto p1, Ponto p2){
        return Math.sqrt(Math.pow(p2.getX() - p1.getX(), 2) + Math.pow(p2.getY() - p1.getY(), 2));
    }

    //b)
    public double calculaAreaTriangulo(){
        double x1 = ponto1.getX();
        double y1 = ponto1.getY();
        double x2 = ponto2.getX();
        double y2 = ponto2.getY();
        double x3 = ponto3.getX();
        double y3 = ponto3.getY();

        return Math.abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
    }

    //c)
    public double calculaPerimetroTriangulo(){
        double lado1 = distancia(ponto1, ponto2);
        double lado2 = distancia(ponto2, ponto3);
        double lado3 = distancia(ponto3, ponto1);

        return lado1 + lado2 + lado3;
    }
}