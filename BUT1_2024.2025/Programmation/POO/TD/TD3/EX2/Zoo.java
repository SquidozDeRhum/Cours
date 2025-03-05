package EX2;

public class Zoo {
    public static void main(String[] args) {
        final int MAX = 10;
        int nba=0;
        Ane a1 = new Ane(3);
        a1.afficher();

        Animal[] ta = new Animal[MAX];
        ta[0]=a1;
        nba++;

        System.out.println("Liste des " + nba + " animaux");
        for (int i = 0; i < nba; i++) {
            ta[i].afficher();
        }
    }
}

abstract class Animal {

    private int num;

    public Animal(int num) {
        this.num = num;
    }

    public int getNum() {
        return this.num;
    }

    public abstract String cri();

    public void afficher() {
        System.out.println("L'animal\n" + this.toString() + "et son cri est : " + this.cri());
    }
}

class Ane extends Animal {

    public Ane(int num) {
        super(num);
    }

    public String toString() {
        return "Ane numéro : " + super.getNum();
    }

    public String cri() {
        return "L'ANE !";
    }

}

class Chouette extends Animal {

    public Chouette(int num) {
        super(num);
    }

    public String toString() {
        return "Chouette numéro : " + super.getNum();
    }

    public String cri() {
        return "OU OU";
    }
}

class Lion extends Animal {

    public Lion(int num) {
        super(num);
    }

    public String toString() {
        return "Lion numéro : " + super.getNum();
    }

    public String cri() {
        return "JAAJ";
    }
}