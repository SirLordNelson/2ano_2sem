import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Main{
    public static void main(String[] args){
        LinhaEncomenda linha1 = new LinhaEncomenda("REF001", "Produto A", 10.0, 2, 0.23, 0.10);
        LinhaEncomenda linha2 = new LinhaEncomenda("REF002", "Produto B", 20.0, 1, 0.23, 0.05);

        List<LinhaEncomenda> linhas = new ArrayList<>();
        linhas.add(linha1);
        linhas.add(linha2);

        Encomenda encomenda = new Encomenda("João Silva", 123456789, "Rua das Flores, 123", LocalDate.now(), linhas);

        LinhaEncomenda linha3 = new LinhaEncomenda("REF003", "Produto C", 15.0, 3, 0.23, 0.15);
        encomenda.addLinhaEncomenda(linha3);

        System.out.println("Detalhes da Encomenda:\n");
        System.out.println(encomenda);

        double valorTotal = encomenda.calculaValorTotal();
        System.out.println("Valor Total da Encomenda: " + valorTotal + "€");

        double valorDescontoTotal = encomenda.calculaValorDesc();
        System.out.println("Valor Total de Desconto da Encomenda: " + valorDescontoTotal + "€");

        int numeroTotalProdutos = encomenda.numeroTotalProdutos();
        System.out.println("Número Total de Produtos: " + numeroTotalProdutos);

        boolean existeProdutoEncomenda = encomenda.existeProdutoEncomenda("REF007");
        if(existeProdutoEncomenda)System.out.println("O produto existe!");
        else System.out.println("O produto não existe...");
    }
}