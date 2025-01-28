import java.lang.*;
import java.util.*;

class Saisir {
    
    static public int entier() {
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Veuillez saisir un entier : ");
        String entier = keyboard.next();
        keyboard.close();
        return Integer.parseInt(entier);
    }

    static public double reeld() {
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Veuillez saisir un dobule : ");
        String doubleS = keyboard.next();
        keyboard.close();
        return Double.parseDouble(doubleS);
    }

    static public float reelf() {
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Veuillez saisir un dobule : ");
        String floatS = keyboard.next();
        keyboard.close();
        return Float.parseFloat(floatS);
    }

    static public String chaine() {
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Veuillez saisir un dobule : ");
        String chaineS = keyboard.next();
        keyboard.close();
        return chaineS;
    }

    static public char car() {
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Veuillez saisir un dobule : ");
        String chaineS = keyboard.next();
        keyboard.close();
        return chaineS.charAt(0);
    }

}