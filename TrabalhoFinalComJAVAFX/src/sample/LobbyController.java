package sample;

import com.google.gson.Gson;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TreeItem;
import javafx.scene.control.TreeView;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import jdk.nashorn.internal.runtime.regexp.joni.ast.EncloseNode;

import java.io.IOException;
import java.net.URL;
import java.util.Arrays;
import java.util.List;
import java.util.ResourceBundle;

@SuppressWarnings("ALL")
public class LobbyController implements Initializable {

    @FXML private Label labelEmail;
    @FXML private TreeView<String> treeView;
    @FXML private ListView<String> listView;

    private Stage stage;
    private Scene scene;
    private Parent root;

    String username;
    int EnvRec = 0;
    Gson gson = new Gson();

    ObservableList<String> listEnviadas = FXCollections.observableArrayList();
    ObservableList<String> listRecebidas = FXCollections.observableArrayList();
    ObservableList<String> listMsgEnviadas = FXCollections.observableArrayList();
    ObservableList<String> listMsgRecebidas = FXCollections.observableArrayList();
    ObservableList<String> listPastas = FXCollections.observableArrayList();
    Mensagem[] response;
    Mensagem msg;
    List<String> temps;
    public void setUsername(String usrname) {
        this.username = usrname;
    }


    public void mouseClickTreeView() throws IOException {

        TreeItem<String> item = treeView.getSelectionModel().getSelectedItem();

        if (item != null) {
            response = Talker.getInstance().getMensagens(username);
            listRecebidas = FXCollections.observableArrayList();
            listEnviadas = FXCollections.observableArrayList();
            listView.setItems(listRecebidas);
            if (item.getValue().equals("Enviadas")) {
                EnvRec = 1;
                GerenciadorDeArquivo arquivo = GerenciadorDeArquivo.getInstancia();
                temps = arquivo.lerJson();
                for (String m : temps) {
                    msg = gson.fromJson(String.valueOf(m), Mensagem.class);
                    //System.out.println(msg.remetente + " == " + username + "= " + msg.remetente.equals(username) );
                    System.out.println("Testando: " + msg.remetente + " " + msg.destinatario + " " + msg.assunto + " " + msg.texto );
                    if (msg.remetente.equals(username)) {
                        System.out.println("Testando: " + msg.remetente + " " + msg.destinatario + " " + msg.assunto + " " + msg.texto );
                        String temp = "PARA: " + msg.destinatario + "\nASSUNTO: " + msg.assunto;
                        listEnviadas.add(temp);
                    }
                }
                listView.setItems(listEnviadas);
            } else if (item.getValue() == "Recebidas") {
                EnvRec = 2;
                if (response != null){
                    for ( Mensagem m : response) {
                        String temp = "DE: " + m.remetente + "\nASSUNTO: " + m.assunto;
                        listRecebidas.add(temp);
                    }
                    //System.out.println("mensagens do servidor: " + Arrays.toString(response));
                    listView.setItems(listRecebidas);
                }
            } else if(item.getValue() == "Pastas"){
                EnvRec = 0;
                try{
                    listView.setItems(listPastas);
                }catch (Exception e){
                    System.err.println(e);
                }
            }
        }else{
        }
        treeView.getSelectionModel().clearSelection();
    }

    public void mouseClickListView(MouseEvent mouseEvent) {
        int i = listView.getSelectionModel().getSelectedIndex();
        if (response != null && EnvRec == 2) { //Recebidas
            String item = listView.getSelectionModel().getSelectedItem();
            //System.out.println("Item: " + item + "I: " + i);
            if (listMsgRecebidas.isEmpty()) {
                for (Mensagem m : response) {
                    String temp = m.texto;
                    listMsgRecebidas.add(temp); //http://catolicasc-bigdata-valmor123.mybluemix.net/get?json={%20%22get%22:%20{%20%22user-id%22:%20%22Cristiano%22%20}%20}
                }
            }
            labelEmail.setText(listMsgRecebidas.get(i));
        }else if (response != null && EnvRec == 1) { //Enviadas
            if (temps != null) {
                for (String m : temps){
                    msg = gson.fromJson(String.valueOf(m), Mensagem.class);
                    if (msg.remetente.equals(username)) {
                        listMsgEnviadas.add(msg.texto);
                    }
                }
            }
            if (i >= 0 && !listMsgEnviadas.isEmpty())
                labelEmail.setText(listMsgEnviadas.get(i));
        }else{
        }
    }

    public void novaMensagem(ActionEvent event) throws IOException {
        switchToEmail(event);
    }

    public void switchToEmail(ActionEvent event) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("Email.fxml"));
        root = loader.load();

        EmailController emailController = loader.getController();
        emailController.setUsername(username);

        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }

    private void switchToLogin(ActionEvent event) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("login.fxml"));
        root = loader.load();
        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        TreeItem<String> pastas = new TreeItem<>("Pastas");
        pastas.setExpanded(true);
        TreeItem<String> enviadas = new TreeItem<>("Enviadas");
        TreeItem<String> recebidas = new TreeItem<>("Recebidas");
        pastas.getChildren().addAll(enviadas, recebidas);
        if (treeView != null) treeView.setRoot(pastas);
    }

    public void logout(ActionEvent event) throws IOException {
        switchToLogin(event);
    }

}
