import java.util.Scanner;

public class Produit {
    private String ref;
    public int date;
    static private Scanner keyboard = new Scanner(System.in);

    public Produit(int date) {
        this.date = date;
        System.out.print("Référence du produit : ");
        this.ref = this.keyboard.nextLine();
    }

    public String toString() {
        return "Produit : " + this.ref + ", Date d'entrée : " + this.date;
    }

    public void afficher() {
        System.out.println(this.toString());
    }
}