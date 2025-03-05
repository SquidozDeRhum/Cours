import java.util.Scanner;
import java.util.ArrayList;

class Voiture {

    private String immatriculation;
    private String modele;
    private int kilometres;
    private float tarif;

    private static Scanner keyboard = new Scanner(System.in);

    public Voiture() {
        System.out.print("Immatriculation : ");
        this.immatriculation = keyboard.nextLine();

        System.out.print("Modele : ");
        this.modele = keyboard.nextLine();

        System.out.print("Kilomètres : ");
        this.kilometres = Integer.parseInt(keyboard.nextLine());

        System.out.print("Tarif : ");
        this.tarif = Float.parseFloat(keyboard.nextLine());
        System.out.println();
    }

    public Voiture(String immatriculation, String modele, int kilometres, float tarif) {
        this.immatriculation = immatriculation;
        this.modele = modele;
        this.kilometres = kilometres;
        this.tarif = tarif;
    }

    public String getImma() {
        return this.immatriculation;
    }

    public String getModele() {
        return this.modele;
    }

    public int getKilometres() {
        return this.kilometres;
    }

    public float getTarif() {
        return this.tarif;
    }

    public void setKilometres(int kilometres) {
        this.kilometres = kilometres;
    }

    public String toString() {
        return "Immatriculation : " + this.immatriculation + "\n" + 
        "Modele : " + this.modele + "\n" + 
        "Kilomètres : " + this.kilometres + "\n" +
        "Tarif : " + this.tarif;
    }

    public void display() {
        System.out.println(this.toString());
    }

}