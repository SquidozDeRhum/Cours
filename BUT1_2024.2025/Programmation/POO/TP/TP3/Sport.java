import java.util.ArrayList;

class Sport {

    private int code;
    private String libelle;

    public Sport(int code, String libelle) {
        this.code = code;
        this.libelle = libelle;
    }

    public String toString() {
        return "Code : " + this.code + "\nLibelle : " + this.libelle + "\n";
    }

    public void display() {
        System.out.print(this.toString());
    }

}

class SportCo extends Sport {
    private int nbJoueurs;

    public SportCo(int code, String libelle, int nbJoueurs) {
        super(code, libelle);
        this.nbJoueurs = nbJoueurs;
    }

    public String toString() {
        return super.toString() + "Nombre de joueurs : " + this.nbJoueurs + "\n";
    }
}

class LesSports {
    private ArrayList<Sport> sportsList;

    final int MAX = 100;

    public LesSports() {
        this.sportsList = new ArrayList<Sport>(MAX);
    }

    public void sportAdd(Sport sport) {
        this.sportsList.add(sport);
    }

    public void sportDisplay() {
        for (int i = 0; i < this.sportsList.size(); i++) {
            System.out.println("-------------------");
            this.sportsList.get(i).display();
        }
    }
}