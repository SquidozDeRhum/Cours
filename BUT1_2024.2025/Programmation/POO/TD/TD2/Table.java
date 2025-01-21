import package.Domino;

public class Table {
    private Domino[nb] tabdom;
    private int nbDominos;

    public Table(int n) {
        this.tabdom = new Domino[n];
        this.nbDominos = 0;
    }
}
