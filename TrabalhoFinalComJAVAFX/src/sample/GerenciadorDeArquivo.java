package sample;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class GerenciadorDeArquivo {
    //1. Metodo construtor precisa ser private.
    //2. guardar uma referencia private para o objeto desta classe.
    //3. Metodo da classe para permitir acesso a instancia.
    private static GerenciadorDeArquivo instancia = null;

    public static GerenciadorDeArquivo getInstancia() {
        if(instancia == null) {
            instancia = new GerenciadorDeArquivo();
        }
        return instancia;
    }
    //
    private File file;
    private GerenciadorDeArquivo() {
        file = new File("arquivo.txt");
    }

    public void escreverNoArquivo(String texto) throws IOException {
        FileWriter fw = new FileWriter(file,true); //the true will append the new data
        texto = texto.replace("{\"send\":", "");
        texto = texto.replaceAll(" }$","");
        fw.write(texto + "\n");//appends the string to the file
        fw.close();
    }

    public List<String> lerJson() throws IOException {
        Scanner myReader = new Scanner(file);
        List<String> temps = new ArrayList<>();
        while (myReader.hasNextLine()) {
            String data = myReader.nextLine();
            temps.add(data);
        }
        myReader.close();

        return temps;
    }

    public String lerDoArquivo() throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(file));
        String resposta = "";
        String temp = br.readLine();
        if(temp != null) {
            temp = br.readLine();
            resposta+= temp;
        }
        br.close();
        return resposta;
    }

}
