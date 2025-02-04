package EX1;

import java.util.ArrayList;

class Personne {
    private String nom, prenom, adresse;

    public Personne (String nom, String prenom, String adresse) {
        this.nom = nom;
        this.prenom = prenom;
        this.adresse = adresse;
    }

    public String toString() {
        return "Nom : " + this.nom + "\n" + "Prenom : " + this.prenom + "\n" + "Adresse : " + this.adresse;
    }

    public void afficher() {
        System.out.println(this.toString());
    }
}

class Compte {
    private String numero;
    private Personne titulaire;
    private double solde;

    public Compte (String numero, Personne titulaire) {
        this.numero = numero;
        this.titulaire = titulaire;
        this.solde = 0;
    }

    public void deposit(double somme) {
        this.solde += somme;
    }

    public void whithdraw(double somme) {
        if (this.solde >= somme) {
            this.solde -= somme;
        } else {
            System.out.println("Solde insuffisant (Sans le sous mdrr)");
        }
    }

    public double getSolde() {
        return this.solde;
    }

    public String getNum() {
        return this.numero;
    }

    public Personne getTitulaire() {
        return this.titulaire;
    }

    public void setSolde(double solde) {
        this.solde = solde;
    }

    public String toString() {
        return "Num : " + this.numero + "\n" + "Titulaire : " + this.titulaire + "\n" + "Solde : " + this.solde;
    }

    public void afficher() {
        System.out.println(this.toString());
    }
}

class CompteRemunere extends Compte {
    private double taux;

    public CompteRemunere(String numero, Personne titulaire, double taux) {
        super(numero, titulaire);
        this.taux = taux;
    }

    public String toString() {
        return super.toString() + "\n" + "Taux : " + this.taux;
    }

    public void afficher() {
        System.out.println(this.toString());
    }

    public void versementInt() {
        this.setSolde(this.getSolde() * this.taux);
    }
}

class Entreprise {

    private String nom;
    private Personne comptable;

    public Entreprise(String nom, Personne comptable) {
        this.nom = nom;
        this.comptable = comptable;
    }

    public String toString() {
        return "Nom : " + this.nom + "\n" + "Comptable : " + comptable.toString();
    }

    public void afficher() {
        System.out.println(this.toString());
    }

    public Personne getComptable() {
        return this.comptable;
    }
}

class CompteEntreprise extends Compte {

    private Entreprise proprietaire;

    public CompteEntreprise(String numero, Entreprise ent) {
        super(numero, ent.getComptable());
        this.proprietaire = ent;
    }

    public String toString() {
        return super.toString() + "\n" + "Titulaire : " + super.getTitulaire();
    }

    public void afficher() {
        System.out.println(this.toString());
    }

    public void mettreSoldeAZero() {
        super.setSolde(0);
    }

}

class Banque {
    private String nom;
    private ArrayList<Compte> lesComptes;

    public Banque(String nom) {
        this.nom = nom;
        lesComptes = new ArrayList<Compte>(100);
    }

    public void addCompte(Compte compte) {
        lesComptes.add(compte);
    }

    public void afficher() {
        System.out.println(this.nom);
        if (this.lesComptes.size() != 0) {
            System.out.println("Liste des " + this.lesComptes.size() + " comptes");
            for (int i = 0; i < this.lesComptes.size(); i++) {
                System.out.println("-----------------");
                lesComptes.get(i).afficher();
            }
        } else {
            System.out.println("Cette banque n'a pas de comptes !");
        }
    }
}