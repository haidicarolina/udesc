package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.io.IOException;

public class EmailController {

    @FXML private TextField txtTo;
    @FXML private TextField txtSubject;
    @FXML private TextArea txtArea;

    private Stage stage;
    private Scene scene;
    private Parent root;

    String username;

    public void setUsername(String usrname) {
        this.username = usrname;
    }

    public String getUsername() {
        return this.username;
    }

    public String getTo(){
        return txtTo.getText();
    }

    public String getSubject(){
        return txtSubject.getText();
    }

    public String getTextArea(){
        return txtArea.getText();
    }

    public void enviarMensagem(ActionEvent event) throws IOException {

        FXMLLoader loader = new FXMLLoader();
        loader.setLocation(getClass().getResource("lobby.fxml"));

        Talker.getInstance().enviarMensagem(getUsername(), getTo(), getSubject(),getTextArea());
        switchToLobby(event);
    }

    public void switchToLobby(ActionEvent event) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("lobby.fxml"));
        root = loader.load();

        LobbyController lobbyController = loader.getController();
        lobbyController.setUsername(username);

        stage = (Stage) ((Node)event.getSource()).getScene().getWindow();
        scene = new Scene(root);
        stage.setScene(scene);
        stage.show();
    }

}
