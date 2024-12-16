#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "fonctions.h"

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