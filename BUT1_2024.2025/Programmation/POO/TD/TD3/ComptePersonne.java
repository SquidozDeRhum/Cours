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

    public String getTitulaire() {
        return this.titulaire;
    }

    public double setSolde(double solde) {
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
        return "Nom : " + this.nom + "\n" + "Comptable : " + comptable.afficher();
    }

    public void afficher() {
        System.out.println(this.toString());
    }
}

class CompteEntreprise extends Compte {

    private Entreprise proprietaire;

    public CompteEntreprise(String numero, Personne titulaire) {
        super(numero, titulaire);
    }

    public String toString() {
        return "Num : " + super.getNum() + "\n" + "Titulaire : " + super.getTitulaire() + "\n" + "Solde : " + super.getSolde();
    }

}