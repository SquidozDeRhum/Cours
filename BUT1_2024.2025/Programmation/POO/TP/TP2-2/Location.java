class Location {

    public int numero;
    public Voiture car;
    public Client client;
    public Date dateLoc;
    public Date dateRet;
    public int nbKilometres;

    public static int numGlobal = 0;

    public Location(Voiture car, Client client, Date dateLoc) {
        this.numero = this.numGlobal;
        this.numGlobal++;

        this.car = car;
        this.client = client;
        this.dateLoc = dateLoc;

        this.dateRet = null;

        this.nbKilometres = car.getKilometres();
    }

    public void setDateRet(Date dateRet) {
        this.dateRet = dateRet;
    }

    public Date getDateLoc() {
        return this.dateLoc;
    }

    public Date getDateRet() {
        return this.dateRet;
    }

    public Voiture getVoiture() {
        return this.car;
    }

    public void setKilometres(int kilometres) {
        this.nbKilometres += kilometres;
    }

    public String toString() {
        if (this.dateRet == null) {
            return "--- Location en cours de :\n" + 
            this.car.toString() + "\n--- Par :\n" +
            this.client.toString() + "\n--- Depuis le :\n" + 
            this.dateLoc.toString();
        } else {
            return "--- Location terminée de :\n" + 
            this.car.toString() + "\n--- Par :\n" +
            this.client.toString() + "\n--- Depuis le :\n" + 
            this.dateLoc.toString() + "\n--- Jusqu'au :\n" + 
            this.dateRet.toString();
        }
    }

    public void display() {
        System.out.println(this.toString());
    }
}