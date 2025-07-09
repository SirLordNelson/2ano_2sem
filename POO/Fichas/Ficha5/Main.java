import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class Main{
    public static void main(String[] args) throws IOException{
        Object a = new Object();
        ObjectOutputStream oos = new ObjectOutputStream();
        oos.write(a);
        oos.flush();
        oos.close();

        FileOutputStream fos = new FileOutputStream("output.txt");
        PrintWriter writer = new PrintWriter(fos);

        writer.println("Isto é um teste");
        writer.flush(); // Fazer sempre após escrita
        writer.close(); // Garantir que se fecha no fim

        // Outra forma de ler ficheiros
        Path file = Paths.get("output.txt");
        List<String> lines = Files.readAllLines(file);
        System.out.println(lines.toString());
    }
}