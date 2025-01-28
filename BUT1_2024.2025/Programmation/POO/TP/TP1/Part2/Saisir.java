import java.time.chrono.ThaiBuddhistChronology;
import java.util.Scanner;

public class Saisir {

    static private Scanner keyboard = new Scanner(System.in);
    
    static public int entier() {
        return this.keyboard.nextInt();
    }
}
