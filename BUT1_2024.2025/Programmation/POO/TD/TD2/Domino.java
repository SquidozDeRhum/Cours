public class Domino {
    private int gauche;
    private int droite;

    public Domino(int vGauche, int vDroite) {
        this.gauche = vGauche;
        this.droite = vDroite;
    }

    public void afficher() {
        System.out.println("Valeur gauche : " + this.gauche);
        System.out.println("Valeur droite : " + this.droite);
    }

    public void inverser() {
        int buff = this.gauche;
        this.gauche = this.droite;
        this.droite = buff;
    }

    public int laGauche() {
        return this.gauche;
    }

    public int laDroite() {
        return this.droite;
    }
}