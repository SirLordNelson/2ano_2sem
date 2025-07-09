public class Main3 {
    public static void main(String[] args) {
        // Criando carros usando diferentes construtores
        Carro carro1 = new Carro("AB-12-CD", "Toyota", "Corolla", 2022, 90, 6.5f, 800, 15000);
        Carro carro2 = new Carro(); // Construtor vazio
        Carro carro3 = new Carro(carro1); // Construtor de cópia

        // Configurando valores para o carro2 (construtor vazio)
        carro2.setMatricula("XY-34-ZW");
        carro2.setMarca("Ford");
        carro2.setModelo("Focus");
        carro2.setAno(2021);
        carro2.setVelocidadeMedia(85);
        carro2.setConsumoCemPorH(7.2f);
        carro2.setAutonomia(750);
        carro2.setKmsRealizados(20000);

        // Testando os métodos
        System.out.println("=== Carro 1 ===");
        System.out.println(carro1);
        System.out.println("HashCode: " + carro1.hashCode());

        System.out.println("\n=== Carro 2 ===");
        System.out.println(carro2);
        System.out.println("HashCode: " + carro2.hashCode());

        System.out.println("\n=== Carro 3 (cópia do Carro 1) ===");
        System.out.println(carro3);
        System.out.println("HashCode: " + carro3.hashCode());

        // Testando equals
        System.out.println("\nComparações:");
        System.out.println("Carro1 equals Carro2: " + carro1.equals(carro2));
        System.out.println("Carro1 equals Carro3: " + carro1.equals(carro3));

        // Modificando um carro para testar a cópia independente
        carro1.setKmsRealizados(16000);
        System.out.println("\nApós modificar Carro1:");
        System.out.println("Carro1 kms: " + carro1.getKmsRealizados());
        System.out.println("Carro3 kms: " + carro3.getKmsRealizados());
        System.out.println("Carro1 equals Carro3 após modificação: " + carro1.equals(carro3));

        // Testando getters
        System.out.println("\nDetalhes do Carro2:");
        System.out.println("Matrícula: " + carro2.getMatricula());
        System.out.println("Marca/Modelo: " + carro2.getMarca() + " " + carro2.getModelo());
        System.out.println("Ano: " + carro2.getAno());
        System.out.println("Velocidade Média: " + carro2.getVelocidadeMedia() + " km/h");
        System.out.println("Consumo: " + carro2.getConsumoCemPorH() + " l/100km");
        System.out.println("Autonomia: " + carro2.getAutonomia() + " km");
        System.out.println("Kms realizados: " + carro2.getKmsRealizados() + " km");
    }
}