import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        // final int maxV = 10;

        // ArrayList<Voiture> tabV = new ArrayList<Voiture>(maxV);

        // tabV.add(new Voiture());
        
        // Client client = new Client();

        // Date date = new Date();

        // Location location = new Location(tabV.get(0), client, date);

        // location.display();

        Agence jaaj = new Agence("Feur-Sur-Loire");

        // jaaj.registerLoc();
        jaaj.locReturn();

        jaaj.displayContrats();
    }
}