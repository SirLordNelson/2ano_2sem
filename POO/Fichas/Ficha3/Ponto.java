public class Ponto{
    private double x = 0.0;
    private double y = 0.0;

    public Ponto(double x, double y){
        this.x = x;
        this.y = y;
    }

    public Ponto(Ponto ponto){
        this.x = ponto.getX();
        this.y = ponto.getY();
    }

    //getters
    public double getX(){
        return x;
    }

    public double getY(){
        return y;
    }

    //setters
    public void setX(double x){
        this.x = x;
    }

    public void setY(double y){
        this.y = y;
    }
}