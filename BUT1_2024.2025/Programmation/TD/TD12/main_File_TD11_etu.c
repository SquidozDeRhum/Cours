#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// déclaration des constantes symboliques
# define MAX_MESSAGES 10
# define MAX_CAR 80

// définition des types
typedef char t_message [MAX_CAR];
typedef struct{
    t_message message;
}t_element;
typedef struct{
    t_element tabElt[MAX_MESSAGES];
    int nb;
}t_file;

// definition des constantes
const t_element ELTVIDE =   {"-----MESSAGE VIDE---------"};

// prototypes des fonctions
void afficheTous(t_file f); // fonction secrete
t_file initialiser();
void enfiler(t_file* adrFile, t_element elt);
void enfiler1(t_file* adrFile, t_element elt);
t_element defiler(t_file* adrFile);
t_element defiler1(t_file* adrFile);
void vider(t_file *adrFile);
t_element tete(t_file f);
int estVide(t_file p);
int estPleine(t_file p);
void supprimer_trop_anciens(t_file *adrFile, int nb_a_supprimer);
void sauvegardeFichier(t_file *adrfile, char nomFichier[]);
void lectureFichier(t_file *adrFile, char nomFichier[]);

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

// Definitions des fonctions
void afficheTous(t_file f){ // fonction secrete
    for(int i=0 ; i<MAX_MESSAGES ; i++){
        printf("%d %s\n",i, f.tabElt[i].message);
    }
}
t_file initialiser() {
	t_file f;
	for (int i=0; i<MAX_MESSAGES; i++)
		f.tabElt[i] = ELTVIDE; // tous les éléments de la file sont initialisés
	f.nb=0 ;
	return f;
}
void enfiler(t_file *adrFile, t_element elt){
	if (!(estPleine(*adrFile))){
		adrFile->tabElt[adrFile->nb]=elt ;
		adrFile->nb++;
		// Attention aux indices du tableau
	}
	else{
		printf("ATTENTION La file est pleine\n");
	}
}

t_element defiler(t_file *adrFile){
	t_element elt;
	if (!(estVide(*adrFile))){
        elt = adrFile->tabElt[0];
        for(int i=0 ; i< adrFile->nb-1; i++){
            adrFile->tabElt[i] = adrFile->tabElt[i+1];
        }
        adrFile->tabElt[adrFile-> nb-1] = ELTVIDE;
        adrFile-> nb--;
    }
    else{
        elt = ELTVIDE;
    }
	return elt;
}

void vider(t_file *adrFile){
	while (adrFile->nb >0){
		adrFile->tabElt[adrFile->nb-1] = ELTVIDE;
		(adrFile->nb)-- ;
    }
}

t_element tete(t_file f){
    return f.tabElt[0];
}

void supprimer_trop_anciens(t_file *adrFile, int nb_a_supprimer){
    printf("cette fonctionnalité n'est pas implantee, a vous de l'ecrire ...\n");
}
int estVide(t_file f){
	return (f.nb == 0);
}
int estPleine(t_file f){
	return (f.nb==MAX_MESSAGES);
}
void sauvegardeFichier(t_file *adrFile, char nomFichier[]){
    FILE *fich;
    fich = fopen(nomFichier,"w");
    while (adrFile->nb > 0){
        fprintf(fich,"%s\n", defiler(adrFile).message);
    }
    fclose(fich);
}
void lectureFichier(t_file *adrFile, char nomFichier[]){
    FILE *fich;
    t_message msg;
    t_element elt;
    vider(adrFile);
    fich = fopen(nomFichier,"r");
    // lecture de la premiere ligne
    fgets(msg,MAX_CAR,fich);
    while (!feof(fich)){
        msg[strlen(msg)-1]='\0'; // '\0' dans la dernière case
        //printf("%s  ",msg);
        strcpy(elt.message, msg);
        enfiler(adrFile, elt);
        // lecture nouvelle ligne
        fgets(msg,MAX_CAR,fich);
    }
    fclose(fich);
}