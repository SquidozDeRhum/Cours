
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
        if (this.pile.sommet().date + 5 < dateJ) {
            System.out.println("Produit périmé, sortie de tout le stock");
            while (!this.pile.pileVide()) {
                this.pile.depiler();
            }
        } else {
            this.pile.depiler();
        }
    }

    public void afficheMenu() { 
        String choice;
        do {
            System.out.print("\n");
            System.out.println("e : entrée d'un produit dans le stock");
            System.out.println("s : sortie d'un produit du stock");
            System.out.println("i : incrémenter la date du jour");
            System.out.println("q : quitter");
            System.out.print("Choix : ");
            choice = keyboard.nextLine();

            switch (choice) {
                case "e":
                    this.entrer(new Produit(this.date));
                    break;
                case "s":
                    this.sortir(this.date);
                    break;
                case "i":
                    this.date++;
                    System.out.println("Date actuelle : " + this.date);
                    break;
                case "q":
                    System.out.println("Fin du programme");
                    break;
                default:
                    System.out.println("Erreur de saisie");
                    break;
            }
        } while (!choice.equals("q"));
    }
}