
import java.text.SimpleDateFormat;
import java.util.*;

public class Ex1 {
    public static void main(String args[]) {

        String[] mois = {"janvier", "février", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "octobre", "nomvembre", "décembre"};
        String[] jours = {"lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche"};

        long millis = System.currentTimeMillis();
        long seconds = millis/1000;

        System.err.println("Nombre de secondes écoulées : " + seconds);

        Calendar c = Calendar.getInstance();

        System.out.println("Nous sommes le " + jours[(c.get(Calendar.DAY_OF_WEEK) - 2) % 7] + " " + c.get(Calendar.DAY_OF_MONTH) + " " + mois[c.get(Calendar.MONTH)] + " " + c.get(Calendar.YEAR));

        Date d = new Date();
        SimpleDateFormat F = new SimpleDateFormat("EEEEEE dd MMMMMM yyyy à HH:mm:ss");
        System.out.println("Date autrement : " + F.format(d));
    }
}
