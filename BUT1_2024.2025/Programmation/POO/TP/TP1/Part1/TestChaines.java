import java.util.Scanner;

public class TestChaines {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);

        // System.out.println("Question 1");
        // int entier = 213;
        // String chaine = String.valueOf(entier);
        // System.out.println("Chaîne convertie : " + chaine);
        
        // System.out.println("\nQuestion 2");
        // System.out.println("Entrez un entier : ");
        // int entier2 = keyboard.nextInt();
        // System.out.println("Entier entré : " + entier2);

        // System.out.println("\nQuestion 3");
        // System.out.println("Entrez un flottant : ");
        // float flottant = Float.parseFloat(keyboard.next());
        // flottant += 1.1;
        // System.out.println("Flottant entré + 1.1 : " + flottant);

        // keyboard.nextLine();

        // System.out.println("\nQuestion 4");
        // String ville = keyboard.nextLine();
        // System.out.println(ville.toUpperCase().strip());

        // System.out.println("\nQuestion 5");
        // System.out.println("Première chaîne : ");
        // String s1 = keyboard.nextLine();

        // System.out.println("Seconde chaîne : ");
        // String s2 = keyboard.nextLine();

        // if (s1.charAt(0) == s2.charAt(0)) {
        //     System.out.println("Ces deux chaînes commencent par le même caractère");
        // } else {
        //     System.out.println("Ces deux chaînes ne commencent pas par le même caractère");
        // }

        // System.out.println("\nQuestion 6");
        // System.out.println("Première chaîne : ");
        // String s21 = keyboard.nextLine();

        // System.out.println("Seconde chaîne : ");
        // String s22 = keyboard.nextLine();

        // Boolean test = s21==s22;

        // System.out.println("s21==s22 : " + test.toString());
        // System.out.println("s21.equals(s22) : " + s21.equals(s22));
        // System.out.println("s21.compareTo(s22) : " + s21.compareTo(s22));
        // System.out.println("s21.compareToIgnoreCase(s22) : " + s21.compareToIgnoreCase(s22));

        // System.out.println("\nQuestion 7");
        // System.out.println("Première chaîne : ");
        // String s31 = keyboard.nextLine();

        // System.out.println("Seconde chaîne : ");
        // String s32 = keyboard.nextLine();

        // if (s31.startsWith(s32)) {
        //     System.out.println("\nS1 commence par S2");
        // } else {
        //     System.out.println("\nS1 ne commence pas par S2");
        // }

        // if (s31.endsWith(s32)) {
        //     System.out.println("\nS1 finie par S2");
        // } else {
        //     System.out.println("\nS1 ne finie pas par S2");
        // }

        // if (s31.contains(s32)) {
        //     System.out.println("\nS1 contient S2");
        // } else {
        //     System.out.println("\nS1 ne contient pas S2");
        // }

        System.out.println("\nQuestion 8");
        System.out.println("Première chaîne : ");
        String s41 = keyboard.nextLine();

        System.out.println("Seconde chaîne : ");
        String s42 = keyboard.nextLine();

        if (s41.contains(s42)) {
            System.out.println("S1 privé de S2");
            System.out.println(s41.substring(0, s41.indexOf(s42)));
        } else {
            System.out.println(s41);
        }

        keyboard.close();
    }
}
