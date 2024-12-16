
# TD12 : La programmation modulaire en C

## Exercice 1 : L’instruction #include

1. **Quelle instruction permet de visualiser le fichier créé par le pré-processeur ?**
   - L’instruction suivante permet de visualiser le fichier pré-traité :
     ```bash
     gcc -E main_exo1.c -o main_exo1.i
     ```

2. **Générer et visualiser le fichier créé par le pré-processeur.**
   - Après exécution de la commande ci-dessus, ouvrez le fichier `main_exo1.i` avec un éditeur de texte ou affichez-le dans le terminal :
     ```bash
     cat main_exo1.i
     ```

## Exercice 2 : Découpage du programme du TD11

1. **Compilation de chaque fichier source :**
   - Utilisez la commande suivante pour compiler séparément chaque fichier :
     ```bash
     gcc -c fichier_source.c
     ```
   - Cela génère des fichiers objets avec l'extension `.o`.

2. **Édition de lien :**
   - Liez les fichiers objets pour créer l'exécutable :
     ```bash
     gcc fichier1.o fichier2.o -o programme_executable
     ```

3. **Création d'un fichier système :**
   - Voici un exemple de fichier `Makefile` simplifié :
     ```makefile
     all: programme_executable

     programme_executable: fichier1.o fichier2.o
     	gcc fichier1.o fichier2.o -o programme_executable

     fichier1.o: fichier1.c
     	gcc -c fichier1.c

     fichier2.o: fichier2.c
     	gcc -c fichier2.c

     clean:
     	rm -f *.o programme_executable
     ```

## Exercice 3 : Gestion de la date et de l'heure

1. **Présentation :**
   - La fonction `time(NULL)` retourne le nombre de secondes écoulées depuis le 1er janvier 1970 à 00:00:00.

2. **Fichiers fournis :**
   - `fonctions_date.h` : contient les prototypes de fonctions de gestion de date.
   - `fonctions_date.o` : fichier objet contenant les fonctions compilées.

3. **Test des dates :**
   - Programme de test fourni dans l'énoncé.

4. **Modification de l'application :**
   - Ajoutez le champ `char date[MAX_SIZE];` dans la structure `t_element`.

5. **Ajout de la fonction `supprime_anciens_date()` :**
   - Voici une implémentation possible :
     ```c
     void supprime_anciens_date(t_file *adrFile, char date_limite[]) {
         while (adrFile->nb > 0 && date2int(adrFile->tabElt[0].date) < date2int(date_limite)) {
             defiler(adrFile);
         }
     }
     ```
