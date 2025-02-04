

public class Pile {
    private Produit[] tabProd;
    private int indice;
    private int MAX;

    public Pile(int max) {
        this.indice = 0;
        this.tabProd = new Produit[max];
        this.MAX = max;
    }

    public boolean pileVide() {
        return this.indice == 0;
    }

    public boolean pilePleine() {
        return this.indice == this.MAX;
    }

    public void empiler(Produit p) {
        if (!pilePleine()) {
            this.tabProd[this.indice] = p;
            this.indice++;
        } else {
            System.out.println("Pile pleine ! ");
        }
    }

    public void depiler() {
        if (!pileVide()) {
            this.indice--;
        } else {
            System.out.println("La pile est vide !");
        }
    }

    public Produit sommet() {
        Produit prod = null;
        if (!pileVide()) {
            prod = this.tabProd[this.indice];
            this.indice--;
        } else {
            System.out.println("La pile est vide !");
        }
        return prod;
    }

    public String toString() {
        String display = new String();
        for (int i = 0; i < this.indice; i++) {
            display += "Produit " + i + "\n";
            display += this.tabProd[i].toString();
        }
        return display;
    }

    public void afficherStock() {
        System.out.println(this.toString());
    }
}