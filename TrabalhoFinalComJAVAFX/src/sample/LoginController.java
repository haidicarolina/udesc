package sample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.stage.Stage;

import java.io.IOException;

public class LoginController{

    @FXML TextField userName;

    @FXML
    public void efetuarLogin(ActionEvent event){
        try{
            String user = userName.getText();
            Talker.getInstance().login(user);

            FXMLLoader loader = new FXMLLoader(getClass().getResource("lobby.fxml"));
            Parent root = loader.load();

            LobbyController lobbyController = loader.getController();
            lobbyController.setUsername(user);

            Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
            Scene scene = new Scene(root);
            stage.setScene(scene);
            stage.show();
        } catch (IOException e){
            e.printStackTrace();
        }
    }
}
