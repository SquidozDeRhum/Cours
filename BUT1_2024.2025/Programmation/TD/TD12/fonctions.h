#pragma once

#include "const.h"
#include "types.h"
#include "globales.h"

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