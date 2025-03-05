import java.util.Scanner;

class Date {
    private int jour;
    private int mois;
    private int annee;

    private static Scanner keyboard = new Scanner(System.in);

    public Date() {
        System.out.print("Jour : ");
        this.jour = Integer.parseInt(keyboard.nextLine());

        System.out.print("Mois : ");
        this.mois = Integer.parseInt(keyboard.nextLine());

        System.out.print("Annee : ");
        this.annee = Integer.parseInt(keyboard.nextLine());
    }

    public Date(int jour, int mois, int annee) {
        this.jour = jour;
        this.mois = mois;
        this.annee = annee;
    }

    public String toString() {
        return "Jour : " + this.jour + "\n" +
        "Mois : " + this.mois + "\n" +
        "Annee : " + this.annee;
    }

    public void display() {
        System.out.println(this.toString());
    }

    public void setJour(int jour) {
        this.jour = jour;
    }

    public void setMois(int mois) {
        this.mois = mois;
    }

    public void setAnnee(int annee) {
        this.annee = annee;
    }
}