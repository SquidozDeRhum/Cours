# TD7 - Structures

### Exercice 1

1. ```pseudocode
   type structure
   debut
       chaine : nom;
       entier : age;
       entier : nbVoix;
   fin : t_Candidat;
   ```

2. ```pseudocode
   fonction saisie() delivre t_Candidat
   debut
       t_Candidat : candidat
       ecrire("Entrez le nom du candidat : ");
       candidat.nom := lire();
       ecrire("Entrez l'âge du candidat : ");
       candidat.age := lire();
       ecrire("Entrez le nombre de voix du candidat : ");
       candidat.nbVoix := lire();
       retourne candidat;
   fin
   ```

3. ```pseudocode
   fonction compare(t_Candidat : c1, t_Candidat : c2) delivre entier
   debut
       si (c1.nbVoix > c2.nbVoix) alors
           retourne 1;
       sinon_si (c1.nbVoix < c2.nbVoix) alors
           retourne -1;
       sinon_si (c1.age > c2.age) alors
           retourne 1;
       sinon_si (c1.age < c2.age) alors
           retourne -1;
       sinon
           retourne 0;
       fin_si
   fin
   ```

4. ```pseudocode
   programme main
   debut
       t_Candidat : candidat1, candidat2;
       entier : resultat;
   
       candidat1 := saisie();
       candidat2 := saisie();
       resultat := compare(candidat1, candidat2);
   
       si (resultat = 1) alors
           ecrire("Le candidat élu est : ", candidat1.nom);
       sinon_si (resultat = -1) alors
           ecrire("Le candidat élu est : ", candidat2.nom);
       sinon
           ecrire("Les candidats sont à égalité.");
       fin_si
   fin
   ```

### Exercice 2

1. ```pseudocode
   procedure afficherLivre(t_livre : livre)
   debut
       ecrire("Référence : ", livre.ref);
       ecrire("Titre : ", livre.titre);
       ecrire("Auteur : ", livre.auteur);
       si (livre.present) alors
           ecrire("Statut : Disponible");
       sinon
           ecrire("Statut : Emprunté");
       fin_si
   fin
   ```

2. ```pseudocode
   fonction saisirLivre() delivre t_livre
   debut
       t_livre : livre;
       ecrire("Entrez la référence du livre : ");
       livre.ref := lire();
       ecrire("Entrez le titre du livre : ");
       livre.titre := lire();
       ecrire("Entrez l'auteur du livre : ");
       livre.auteur := lire();
       livre.present := vrai;
       retourne livre;
   fin
   ```

3. ```pseudocode
   procedure insererLivre(sortie t_bib : biblio, t_livre : livre)
   debut
       si (biblio.nbre < MAXL) alors
           biblio.contenu[biblio.nbre] := livre;
           biblio.nbre := biblio.nbre + 1;
       sinon
           ecrire("Erreur : La bibliothèque est pleine.");
       fin_si
   fin
   ```

4. ```pseudocode
   procedure afficherBibliotheque(t_bib : biblio)
   debut
       entier : i;
       pour (i := 0 ; i < biblio.nbre ; i := i + 1) faire
           afficherLivre(biblio.contenu[i]);
       fin_pour
   fin
   ```

5. ```pseudocode
   procedure emprunterLivre(sortie t_bib : biblio, entier : refLivre)
   debut
       entier : i;
       pour (i := 0 ; i < biblio.nbre ; i := i + 1) faire
           si (biblio.contenu[i].ref = refLivre) alors
               si (biblio.contenu[i].present) alors
                   biblio.contenu[i].present := faux;
                   ecrire("Livre emprunté avec succès.");
               sinon
                   ecrire("Le livre est déjà emprunté.");
               fin_si
           fin_si
       fin_pour
       ecrire("Livre non trouvé dans la bibliothèque.");
   fin
   ```

6. ```pseudocode
   type structure
   debut
       entier : numero;
       chaine : nom;
       tableau(entier)[MAXL] : livresEmpruntes;
       entier : nbEmprunts;
   fin : t_lecteur;
   ```

   