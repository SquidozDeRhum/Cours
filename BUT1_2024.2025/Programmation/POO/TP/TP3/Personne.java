class Personne {
    private String nom, prenom, adresse;

    public Personne(String nom, String prenom, String adresse) {
        this.nom = nom;
        this.prenom = prenom;
        this.adresse = adresse;
    }

    public String toString() {
        return "Nom : " + this.nom + "\nPrenom : " + this.prenom + "\nAdresse : " + this.adresse + "\n";
    }

    public void display() {
        System.out.println(this.toString());
    }

    public String getNom() {
        return this.nom;
    }

    public String getPrenom() {
        return this.prenom;
    }

    public String getAdresse() {
        return this.adresse;
    }
}

class Entraineur extends Personne {
    
    private Sport sport;

    public Entraineur(String nom, String prenom, String adresse, Sport sport) {
        super(nom, prenom, adresse);
        this.sport = sport;
    }

    public String toString() {
        return super.toString() + "--- Sport : \n" + this.sport.toString();
    }

}

class Jockey extends Personne {

    private Entraineur entraineur;

    public Jockey(String nom, String prenom, String adresse, Entraineur entraineur) {
        super(nom, prenom, adresse);
        this.entraineur = entraineur;
    }

    public String toString() {
        return super.toString() + "--- Entraineur : \n" + this.entraineur.toString() + "\n";
    }
}