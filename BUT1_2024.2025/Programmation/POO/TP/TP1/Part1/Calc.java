import java.lang.*;
import java.util.*;

public class Calc {
    public static void main(String args[]) {

        final String COSINUS = "C";
        final String SINUS = "S";
        final String TANGEANTE = "T";
        final String STOP = "Q";

        String input;
        double result;

        Scanner keyboard = new Scanner(System.in);
    
        String choice = new String();
        
        while (!choice.equals("Q")) {
            System.out.println("C : calcul d'un cosinus");
            System.out.println("S : calcul d'un sinus");
            System.out.println("T : calcul d'une tangeante");
            System.out.println("Q : quitter le programme");

            System.out.println("Votre choix : ");

            choice = keyboard.nextLine();

            if (!choice.equals("Q")) {
                System.out.println("Angle : ");
                input = keyboard.nextLine();

                switch (choice) {
                    case COSINUS:
                        result = Math.cos(Double.parseDouble(input));
                        break;
    
                    case SINUS:
                        result = Math.sin(Double.parseDouble(input));
                        break;
    
                    case TANGEANTE:
                        result = Math.tan(Double.parseDouble(input));
                        break;
    
                    default:
                        System.out.println("Erreur de saisie");
                        result = -1;
                }
                System.out.println("Résultat : " + result);
            }
        }
        System.out.println("Fin du programme");
    }
}