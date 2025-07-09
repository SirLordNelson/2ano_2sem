import java.util.Objects;

public class Aluno{
    private String numero;
    private String nome;
    private String curso;
    private int nota;

    //Constructors
    public Aluno(String numero, String nome, String curso, int nota) {
        this.numero = numero;
        this.nome = nome;
        this.curso = curso;
        this.nota = nota;
    }

    public Aluno(){}

    public Aluno(Aluno aluno){
        this.numero = aluno.numero;
        this.nome = aluno.nome;
        this.curso = aluno.curso;
        this.nota = aluno.nota;
    }

    //Getters
    public String getNumero(){return numero;}
    public String getNome(){return nome;}
    public String getCurso(){return curso;}
    public int getNota(){return nota;}

    //Setters
    public void setNumero(String numero){this.numero = numero;}
    public void setNome(String nome){this.nome = nome;}
    public void setCurso(String curso){this.curso = curso;}
    public void setNota(int nota){this.nota = nota;}

    @Override
    public String toString(){
        return "Aluno{" +
                "numero='" + numero + '\'' +
                ", nome='" + nome + '\'' +
                ", curso='" + curso + '\'' +
                ", nota=" + nota +
                '}';
    }

    @Override
    public boolean equals(Object o){
        if(o == null || getClass() != o.getClass()) return false;
        Aluno aluno = (Aluno) o;
        return nota == aluno.nota && Objects.equals(numero, aluno.numero) && Objects.equals(nome, aluno.nome) && Objects.equals(curso, aluno.curso);
    }

    @Override
    public int hashCode(){return Objects.hash(numero, nome, curso, nota);}

    public Aluno clone(){return new Aluno(this);}
    public int compareTo(Aluno aluno){return this.compareTo(aluno);}
}