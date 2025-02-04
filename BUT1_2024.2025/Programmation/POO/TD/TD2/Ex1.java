import java.util.*;
import java.lang.*;

public class Ex1 {
    public static void main(String args[]) {
        final int N = 28;
        String response;
        int g, d, pose;
        Scanner keyboard = new Scanner(System.in);
        Table table = new Table(N);
        table.initTable();
        table.affTable();

        Pioche unePioche = new Pioche(N);
        unePioche.initPioche();

        System.out.println("Pioche");
        unePioche.affichePioche();

        System.out.println("Main 1");

        MainJoueur mainJoueur1 = new MainJoueur();

        mainJoueur1.initMainJoeur(unePioche);

        System.out.println("Main Joueur 1");
        mainJoueur1.afficheMain();

        System.out.println("Main 2");

        MainJoueur mainJoueur2 = new MainJoueur();

        mainJoueur2.initMainJoeur(unePioche);

        System.out.println("Main Joueur 2");
        mainJoueur2.afficheMain();

        if ((mainJoueur1.chercheIndiceDoubleDom()==-1) && (mainJoueur2.chercheIndiceDoubleDom()==-1)) {
            System.out.println("Pas de double ...");
        } else if

        System.out.println("Le jeu commence");
        do { 
            System.out.println("Valeur gauche : ");
            g = keyboard.nextInt();

            System.out.println("Valeur droite : ");
            d = keyboard.nextInt();

            pose=table.recherche(g, d);
            System.out.println("Pose : " + pose);

            switch (pose) {
                case -1:
                    table.poserAgauche(g, d);
                    break;

                case 1:
                    table.poserADroite(g, d);
                    break;

                case 0:
                    System.out.println("Pas possible");
                    break;
                default:
                    throw new AssertionError();
            }
            table.affTable();
            String feur = keyboard.nextLine();
            System.out.println("Arrêter le jeu : ");
            response=keyboard.nextLine();

        } while (response.compareTo("oui") != 0);
    }
}

class Domino {
    private int gauche;
    private int droite;

    public Domino(int vGauche, int vDroite) {
        this.gauche = vGauche;
        this.droite = vDroite;
    }

    public void afficher() {
        System.out.println(this.gauche + "/" + this.droite);
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

class Table {
    private Domino[] tabdom;
    private int nbDominos;

    public Table(int n) {
        this.tabdom = new Domino[n];
        this.nbDominos = 0;
    }

    public void initTable() {
        Scanner keyboard = new Scanner(System.in);
        int gauche, droite;

        System.out.println("Valeur gauche : ");
        gauche = keyboard.nextInt();

        System.out.println("Valeur droite : ");
        droite = keyboard.nextInt();

        this.tabdom[this.nbDominos] = new Domino(gauche, droite);
        this.nbDominos++;
    }

    public void affTable() {
        System.out.println("Table de " + this.nbDominos + " dominos");
        for (int i = 0; i < this.nbDominos; i++) {
            this.tabdom[i].afficher();
        }
    }

    public int recherche(int g, int d) {
        if (this.tabdom[0].laGauche() == d || this.tabdom[0].laGauche() == g) {
            return -1;
        } else if (this.tabdom[this.nbDominos - 1].laDroite() == d || this.tabdom[this.nbDominos - 1].laDroite() == g) {
            return 1;
        } else {
            return 0;
        }
    }Yolande Le Gall

    public void poserAgauche(int g, int d) {
        System.out.println("Poser à gauche");
        Domino domingo = new Domino(g, d);
        if (domingo.laDroite() != this.tabdom[0].laGauche()) {
            domingo.inverser();
        }

        for (int i = this.nbDominos; i > 0; i--) {
            this.tabdom[i] = this.tabdom[i - 1]; 
        }

        this.tabdom[0] = domingo;
        this.nbDominos++;
    }

    public void poserADroite(int g, int d) {
        System.out.println("Poser à droite");

        Domino domingo = new Domino(g, d);

        if (domingo.laGauche() != this.tabdom[this.nbDominos].laDroite()) {
            domingo.inverser();
        }

        this.tabdom[this.nbDominos] = domingo;
    }
}

class Pioche {
    private ArrayList<Domino> piocheJeu;

    public Pioche(int n) {
        this.piocheJeu = new ArrayList<Domino>(n);
    }

    public void initPioche() {
        for (int i = 0; i < 7; i ++) {
            for (int j = i; j < 7; i++) {
                this.piocheJeu.add(new Domino(i, j));
            }
        }
    }

    public Domino piocherDomino() {
        if (!this.piocheJeu.isEmpty()) {
            int indexPioche = (int)(Math.random() * this.piocheJeu.size());
            return this.piocheJeu.remove(indexPioche);
        } else {
            System.out.println("Plus de dominos disponibles !");
            return null;
        }
    }

    public void affichePioche() {
        if (!this.piocheJeu.isEmpty()) {
            for (int i = 0; i < this.piocheJeu.size() - 1; i++) {
                this.piocheJeu.get(i).afficher();
            }
        } else {
            System.out.println("Miskine y'a plus de dominos");
        }
    }
}

class MainJoueur {

    private ArrayList<Domino> piocheJoueur;

    public MainJoueur() {
        this.piocheJoueur = new ArrayList<Domino>(7);
    }

    public void initMainJoeur(Pioche pioche_et_pas_la_pioche_qu_on_utilise_pour_miner_les_cailloux_tout_ca_tu_connais_c_est_important_pour_miner_du_fer_dans_minecraft_comme_ca_ta_une_petite_armure_en_fer_ca_fait_plaise) {
        for (int i = 0; i < 7; i++) {
            piocheJoueur.add(pioche_et_pas_la_pioche_qu_on_utilise_pour_miner_les_cailloux_tout_ca_tu_connais_c_est_important_pour_miner_du_fer_dans_minecraft_comme_ca_ta_une_petite_armure_en_fer_ca_fait_plaise.piocherDomino());
        }
    }

    public int chercheIndiceDoubleDom() {
        int indice = -1;
        Domino max = new Domino(-1, -1);
        Domino current;
        for (int i = 0; i < piocheJoueur.size() - 1; i++) {
            current = piocheJoueur.get(i);
            if (current.laGauche() == current.laDroite()) {
                if (current.laGauche() > max.laGauche()) {
                    max = current;
                    indice = i;
                }
            }
        }
        return indice;
    }

    public Domino jouePlusGrosDom() {
        Domino max = new Domino(-1, -1);
        Domino current;
        for (int i = 0; i < piocheJoueur.size() - 1; i++) {
            current = piocheJoueur.get(i);
            if (current.laGauche() + current.laDroite() > max.laGauche() + max.laDroite()) {
                max = current;
            }
        }
        return max;
    }

    public void afficheMain() {
        for (int i = 0; i < this.piocheJoueur.size() - 1; i++) {
            this.piocheJoueur.get(i).afficher();
        }
    }

}