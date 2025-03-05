class Cheval {
    private int num;
    private String nom, race;
    private int sexe;

    private static int nbChevaux = 0;

    public Cheval(String nom, String race, int sexe) {
        this.num = this.nbChevaux;
        this.nom = nom;
        this.race = race;
        this.sexe = sexe;

        this.nbChevaux++;
    }

    public String toString() {
        return "Num : " + this.num + "\nNom : " + this.nom + "\nRace : " + this.race + "\nSexe : " + this.sexe + "\n";
    }
}

class ChevalDeCourse extends Cheval {
    private float gains;
    private Entraineur entraineur;
    private Jockey jockey;

    public ChevalDeCourse(String nom, String race, int sexe, float gains, Entraineur entraineur) {
        super(nom, race, sexe);
        this.gains = gains;
        this.entraineur = entraineur;
    }

    public String toString() {
        return super.toString() + "Gains : " + this.gains + "\nEntraineur : " + this.entraineur.toString() + "\nJockey : " + this.jockey.toString() + "\n";
    }

    public void display() {
        System.out.println(this.toString());
    }

    public void attribueJockey(Jockey jockey) {
        this.jockey = jockey;
    }

}