import java.util.Scanner;

class Client {
    private int num;
    private String nom;
    private String domicile;

    private static int nbClients = 0;

    private static Scanner keyboard = new Scanner(System.in);

    public Client() {
        this.num = this.nbClients;
        this.nbClients++;

        System.out.print("Nom client : ");
        this.nom = keyboard.nextLine();

        System.out.print("Domicile client : ");
        this.domicile = keyboard.nextLine();
    }

    public Client(String nomClient, String domicile) {
        this.num = this.nbClients;
        this.nbClients++;
        this.nom = nomClient;
        this.domicile = domicile;
    }

    public String toString() {
        return "Num : " + this.num + "\n" +
        "Nom : " + this.nom + "\n" +
        "Domicile : " + this.domicile;
    }

    public void display() {
        System.out.println(this.toString());
    }

    public static int getnbClients() {
        return Client.nbClients;
    }
}