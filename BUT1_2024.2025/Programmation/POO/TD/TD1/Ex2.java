import java.lang.*;
import java.util.*;
public class Ex2 {
    public static void main(String args[]) {
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Veuillez saisir une chaîne : ");
        String ligne = keyboard.nextLine();

        String jeej = new StringBuffer(ligne).reverse().toString();

        if (ligne.equals(jeej)) {
            System.out.println("C'est un palindrome");
        }
        else {
            System.out.println("Non");
        }
    }
}