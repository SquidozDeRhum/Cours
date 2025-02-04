package EX1;

public class Main {
    public static void main(String[] args) {
        Personne numero1 = new Personne("Joestar", "Joseph", "USA");
        Personne numero2 = new Personne("Joestar", "Jotaro", "JA");

        numero1.afficher();
        numero2.afficher();

        Compte compte1 = new Compte("001", numero1);
        Compte compte2 = new Compte("002", numero2);

        System.out.println("Depot de 100 trucs compte 1");
        compte1.deposit(100.0);

        System.out.println("Depot de 40 trucs compte 2");
        compte2.deposit(40.0);

        System.out.println("Retrait de 50 compte 1");
        compte1.whithdraw(50.0);

        System.out.println("Retrait de 50 compte 2");
        compte2.whithdraw(50.0);

        Entreprise e1 = new Entreprise("Feur", numero2);

        CompteEntreprise ce1 = new CompteEntreprise("101", e1);

        ce1.afficher();

        Banque b = new Banque("Crédit IUT");
        b.addCompte(ce1);
        b.addCompte(compte1);
        b.afficher();
        compte2.deposit(200);
        b.afficher();
    }
}