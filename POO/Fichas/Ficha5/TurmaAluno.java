import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class TurmaAluno{
    private Map<String, Aluno> alunos;
    private String designacao;
    private int ocupacao;
    private static int capacidade = 20;

    //Constructors
    public TurmaAluno(){
        this.alunos = new HashMap<>();
        this.designacao = "";
        this.ocupacao = 0;
    }

    public TurmaAluno(Map<String, Aluno> alunos, String designacao, int ocupacao){
        this.alunos = alunos;
        this.designacao = designacao;
        this.ocupacao = ocupacao;
    }

    public TurmaAluno(TurmaAluno turma){
        this.alunos = new HashMap<>();
        for(Map.Entry<String, Aluno> entry : turma.alunos.entrySet()){
            this.alunos.put(entry.getKey(), entry.getValue().clone());
        }
        this.designacao = turma.designacao;
        this.ocupacao = turma.ocupacao;
    }

    //Getters e Setters
    public Map<String, Aluno> getAlunos(){return alunos;}
    public void setAlunos(Map<String, Aluno> alunos){this.alunos = alunos;}
    public String getDesignacao(){return designacao;}
    public void setDesignacao(String designacao){this.designacao = designacao;}
    public int getOcupacao(){return ocupacao;}
    public void setOcupacao(int ocupacao){this.ocupacao = ocupacao;}
    public static int getCapacidade(){return capacidade;}
    public static void setCapacidade(int capacidade){TurmaAluno.capacidade = capacidade;}

    public void iteraPorValues(){
        List<Aluno> alunos = this.alunos.values().stream().toList();
        for(Aluno aluno : alunos){}
        if(this.alunos.containsKey("a10000")){
            Aluno ret = this.alunos.get("a10000");
        }
    }

    private List<Aluno> sortedValues(){
        List<Aluno> alunos = this.alunos.values().stream().toList();
        this.alunos.values().stream().toList().sort(Aluno::compareTo);
        return alunos;
    }

    public  void addAluno(Aluno aluno){
        if(!this.alunos.containsKey(aluno.getNumero())) this.alunos.put(aluno.getNumero(), aluno.clone());
    }
}