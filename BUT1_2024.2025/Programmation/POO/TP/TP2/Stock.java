
import java.util.Scanner;

public class Stock {
    private Pile pile;
    private int date = 1;
    static private Scanner keyboard = new Scanner(System.in);

    public Stock(int taille) {
        pile = new Pile(taille);
    }

    public void entrer(Produit p) {
        this.pile.empiler(p);
    }

    public void sortir(int dateJ) {
        
    }
}