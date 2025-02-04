import java.util.*;
public class Ex1 {
    public static void main(String args[]) {
        Scanner keyboard = new Scanner(System.in);
        System.out.println("Veuillez saisir une chaîne : ");
        String ligne = keyboard.nextLine();
        
        StringBuffer jaaj =  new StringBuffer(ligne);

        char car;

        for (int i = 0; i < jaaj.length(); i++) {
            car = jaaj.charAt(i);                   // Des petits commentaires ^^
            car = (char)((int)(Character.toLowerCase(car) + 2 - 97) % 26 + 97);
            jaaj.setCharAt(i, car);
        }

        ligne = new String(jaaj);

        System.out.println(ligne);

        keyboard.close();
    }
}