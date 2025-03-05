import java.util.ArrayList;
import java.util.Scanner;

class Agence {
    private String nom;
    private ArrayList<Voiture> parc;
    private ArrayList<Client> clientele;
    private ArrayList<Location> contrats;

    final static int max = 100;

    static Scanner keyboard = new Scanner(System.in);

    public Agence(String nomAgence) {
        this.nom = nomAgence;
        this.parc = new ArrayList<Voiture>(max);
        parc.add(new Voiture("Jaaj", "Jeej", 12, (float)600));
        parc.add(new Voiture("Juuj", "Jeej", 12, (float)14.5));
        parc.add(new Voiture("Jiij", "Jeej", 12, (float)600));

        this.clientele = new ArrayList<Client>(max);
        clientele.add(new Client("Axel", "Leme"));
        clientele.add(new Client("Quentin", "Gonzales"));
        clientele.add(new Client("Feur", "Paris"));

        this.contrats = new ArrayList<Location>(max);
        contrats.add(new Location(this.parc.get(1), this.clientele.get(0), new Date(12, 9, 2025)));
        contrats.add(new Location(this.parc.get(2), this.clientele.get(1), new Date(24, 3, 2026)));

        contrats.get(1).setDateRet(new Date(2, 3, 2027));
    }

    public void displayCars() {
        System.out.println("Affichage des voitures");

        for (int i = 0; i < this.parc.size(); i++) {
            System.out.println("----------------");
            this.parc.get(i).display();
        }
    }

    public void displayClients() {
        System.out.println("Affichage de la clientele");

        for (int i = 0; i < this.clientele.size(); i++) {
            System.out.println("----------------");
            this.clientele.get(i).display();
        }
    }

    public void displayContrats() {
        System.out.println("Affichage des contrats");

        for (int i = 0; i < this.contrats.size(); i++) {
            System.out.println("----------------");
            this.contrats.get(i).display();
        }
    }

    public void registerLoc() {
        int numCli;
        int indexImmat = 0;
        String immat;
        boolean dispo = false;
        System.out.println("Enregistrement location");
        System.out.print("Numéro client : ");
        numCli = Integer.parseInt(keyboard.nextLine());
        while (numCli >= Client.getnbClients()) {
            System.out.println("Ce numéro client n'existe pas");
            System.out.print("Numéro client : ");
            numCli = Integer.parseInt(keyboard.nextLine());
        }
        this.displayCars();
        System.out.print("Immat voiture : ");
        immat = keyboard.nextLine();
        for (int i = 0; i < this.parc.size(); i++) {
            if (this.parc.get(i).getImma().equals(immat)) {
                dispo = true;
            }
        }

        while (dispo == false) {
            System.out.println("Cette immatriculation n'existe pas");
            this.displayCars();
            System.out.print("Immat voiture : ");
            immat = keyboard.nextLine();
            for (int i = 0; i < this.parc.size(); i++) {
                if (this.parc.get(i).getImma().equals(immat)) {
                    dispo = true;
                    indexImmat = i;
                }
            }
        }

        Location location = new Location(this.parc.get(indexImmat), this.clientele.get(numCli), new Date());

        this.contrats.add(location);
    }

    public int getVoitureIndex(String immat) {
        boolean present = false;
        int i = 0;
        int index = -1;
        while (!present && i < this.parc.size()) {
            if (this.parc.get(i).getImma().equals(immat)) {
                present = true;
                index = i;
            }
            i++;
        }
        return index;
    }

    public int getLocIndex(String immat) {
        boolean present = false;
        int i = this.contrats.size() - 1;
        int index = -1;
        while (!present && i >= 0) {
            if (this.contrats.get(i).getVoiture().getImma().equals(immat)) {
                present = true;
                index = i;
                System.out.println(i);
            }
            i--;
        }
        return index;
    }

    public void locReturn() {
        String immat;
        Date date;
        int kilometrage;
        Location location;
        Voiture voiture;
        System.out.print("Immat voiture : ");
        immat = keyboard.nextLine();
        while (getVoitureIndex(immat) == -1 || this.contrats.get(getLocIndex(immat)).getDateRet() != null) {
            System.out.println("Erreur de saisie, veuillez recommencer.");
            System.out.print("Immat voiture : ");
            immat = keyboard.nextLine();
        }

        // Création d'une copie de la voiture pour plus de lisibilité
        voiture = this.parc.get(getVoitureIndex(immat));

        date = new Date();
        location = this.contrats.get(getLocIndex(immat));
        location.display();

        this.contrats.get(getLocIndex(immat)).setDateRet(date);

        System.out.print("Kilométrage de retour : ");
        kilometrage = Integer.parseInt(keyboard.nextLine());


        while (kilometrage <= voiture.getKilometres()) {
            System.out.println("Erreur de saisie, veuillez recommencer.");
            System.out.print("Kilométrage de retour : ");
            kilometrage = Integer.parseInt(keyboard.nextLine());
        }


        System.out.println("Distance parcourue : " + (kilometrage - voiture.getKilometres()));
        System.out.println("Prix kilométrique : " + voiture.getTarif() + "€/KM");
        System.out.println("Prix : " + ((kilometrage - voiture.getKilometres()) * voiture.getTarif()));
        
        this.parc.get(getVoitureIndex(immat)).setKilometres(kilometrage);

        this.contrats.get(getLocIndex(immat)).setKilometres(kilometrage - voiture.getKilometres());
    }
}