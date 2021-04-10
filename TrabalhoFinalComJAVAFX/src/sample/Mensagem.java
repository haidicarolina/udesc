package sample;

import com.google.gson.annotations.SerializedName;

public class Mensagem {
    @SerializedName("remetente")
    String remetente;
    @SerializedName("destinatario")
    String destinatario;
    @SerializedName("assunto")
    String assunto;
    @SerializedName("texto")
    String texto;

    public Mensagem(String remetente, String destinatario, String assunto, String texto) {
        this.remetente    = remetente;
        this.destinatario = destinatario;
        this.assunto      = assunto;
        this.texto        = texto;
    }

    public String toString() {
        String resposta = "de:" + remetente+ "\n";
        resposta += "para:" + destinatario+ "\n";
        resposta += "assunto:" + assunto+ "\n";
        resposta += "texto:" + texto+ "\n";
        return resposta;
    }
}
