public class TestStock {
    public static void main(String[] args) {
        final int MAX = 30;

        Produit produit = new Produit(43);
        produit.afficher();
        Produit produit2 = new Produit(47);

        Pile pile = new Pile(MAX);
        for (int i = 0; i < 10; i++) {
            pile.empiler(produit);
            pile.empiler(produit2);
        }
        pile.afficherStock();
    }
}