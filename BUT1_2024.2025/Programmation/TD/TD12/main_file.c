#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "const.h"
#include "types.h"
#include "fonctions.h"

int main(){
    // Declaration des variables
    t_file maFile;
    t_element elt;
    t_message msg;
    int choix;
    // initialisation
    maFile = initialiser();
    // ajouter quelques elements diractement 
    // ajouter quelques elements directement
    strcpy(maFile.tabElt[0].message,"message 0");
    strcpy(maFile.tabElt[1].message,"message 1");
    strcpy(maFile.tabElt[2].message,"message 2");
    maFile.nb = 3;
    
    do{ // menu
        printf("----------------------------------------------------\n");
        printf("0 : quitter\n");
        printf("1 : afficher le nombre d'elements dans la file ?\n");
        printf("2 : ajouter un element a la file\n");
        printf("3 : retirer un element et afficher le message \n");
        printf("4 : afficher le message de la tete de file\n");
        printf("5 : vider la file\n");
        printf("6 : la file est-elle vide ?\n");
        printf("7 : la file est-elle pleine ?\n");
        printf("8 : supprimer les messages trop anciens\n");
        printf("9 : sauvegarde dans un fichier texte et vider\n");
        printf("10: lecture des messages du fichier texte\n");
        printf("votre choix : ");
        scanf("%d", &choix);
        printf("----------------------------------------------------\n");
        // traitement
        switch(choix){
            case -1 :   afficheTous(maFile);
            case 0:     break;
            case 1:     // afficher le nombre d'elements dans la file
                        printf("nombre d'éléménts dans la file : %d\n", maFile.nb);   
                        break;
            case 2:     // ajouter un element (à donner aux étudiants)
                        printf("saisir un nouveau message : ");
                        fgets(msg,MAX_CAR, stdin);  // vider le buffeur de caractères
                        fgets(msg, MAX_CAR, stdin); // saisie d'une chaine de caractères sécurisée
                        msg[strlen(msg)-1]='\0';
                        strcpy(elt.message,msg);
                        enfiler(&maFile, elt);
                        break;
            case 3:     // retirer un element et afficher le message
                        elt = defiler(&maFile);
                        printf("%s\n", elt.message);
                        break;
            case 4:     // afficher le message de la tete de file
                        printf("tete de file %s\n", tete(maFile).message);
                        break; 
            case 5:     // vider la file
                        vider(&maFile);
                        break;
            case 6:     // la file est-elle vide ?
                        printf("file vide ? : %d\n", estVide(maFile));
                        break;
            case 7:     // la file est-elle pleine ?
                        printf("file pleine ? : %d\n", estPleine(maFile));
                        break;
            case 8:     // supprimer les messages trop anciens
                        {   int nb;
                            printf("combien de messages à supprimer ?");
                            scanf("%d", & nb);
                            supprimer_trop_anciens(&maFile, nb);
                        }
                        break;
            case 9:     //sauvegarde dans un fichier texte et vider
                        sauvegardeFichier(&maFile, "message.txt");
                        break;
            case 10:    //lecture des messages du fichier texte
                        lectureFichier(&maFile, "message.txt");
                        break;
            default :   printf("erreur de saisie\n");
        }
    }while(choix != 0);
    return EXIT_SUCCESS;
}