
# R1.04 - TP 5 - Filtres (suite)

## Fichier `prod`

1. **Convertir chaque ligne en majuscules :**
   ```bash
   cat prod | tr 'a-z' 'A-Z'
   ```

2. **Afficher les produits et les quantités, triés par quantité :**
   ```bash
   cut -d ',' -f 1,2 prod | sort -t ',' -k2,2n
   ```

3. **Afficher les couleurs uniques et leur nombre d’occurrences :**
   ```bash
   cut -d ',' -f 3 prod | sort | uniq -c
   ```

## Fichier `lang`

4. **Supprimer les espaces redondants :**
   ```bash
   tr -s ' ' < lang
   ```

5. **Trier le fichier sur l’année, puis sur le nom :**
   ```bash
   tr -s ' ' < lang | sort -k2,2 -k1,1
   ```

6. **Afficher les années uniques sans le siècle :**
   ```bash
   cut -d ' ' -f 2 lang | cut -c 3-4 | sort -u
   ```

7. **Compter les langages dont le nom ne dépasse pas 3 lettres :**
   ```bash
   awk '{ if (length($1) <= 3) print $1 }' lang | wc -l
   ```

## Fichier `depts`

8. **Remplacer les apostrophes par des espaces :**
   ```bash
   sed "s/'/ /g" depts
   ```

9. **Lister les initiales uniques des départements :**
   ```bash
   cut -c 1 depts | sort -u
   ```

10. **Afficher pour chaque lettre le nombre de départements, trié par ordre décroissant :**
   ```bash
   cut -c 1 depts | sort | uniq -c | sort -nr
   ```

## Fichier `murphy`

11. **Remplacer chaque espace par un underscore :**
   ```bash
   tr ' ' '_' < murphy
   ```

12. **Supprimer les espaces :**
   ```bash
   tr -d ' ' < murphy
   ```

13. **Supprimer les points-virgules :**
   ```bash
   tr -d ';' < murphy
   ```

## Fichier `lorem`

14. **Supprimer les voyelles :**
   ```bash
   tr -d 'aeiouyAEIOUY' < lorem
   ```

15. **Convertir les minuscules en majuscules et inversement :**
   ```bash
   tr 'a-zA-Z' 'A-Za-z' < lorem
   ```

16. **Remplacer les retours à la ligne par des espaces :**
   ```bash
   tr '
' ' ' < lorem
   ```

17. **Ne garder qu’un seul espace partout où il y en a plusieurs :**
   ```bash
   tr -s ' ' < lorem
   ```

18. **Supprimer les points :**
   ```bash
   tr -d '.' < lorem
   ```

19. **Afficher tous les mots, un par ligne :**
   ```bash
   tr -s ' ' '
' < lorem
   ```

20. **Lister chaque mot et son nombre d’occurrences :**
   ```bash
   tr -s ' ' '
' < lorem | sort | uniq -c
   ```

21. **Afficher les 3 mots les plus fréquents avec leur comptage :**
   ```bash
   tr -s ' ' '
' < lorem | sort | uniq -c | sort -nr | head -3
   ```

22. **Nettoyer pour ne garder que les 3 mots les plus fréquents :**
   ```bash
   tr -s ' ' '
' < lorem | sort | uniq -c | sort -nr | head -3 | awk '{print $2}'
   ```

23. **Corriger pour ne pas faire de différence entre les écritures :**
   ```bash
   tr -s ' ' '
' < lorem | tr 'A-Z' 'a-z' | sort | uniq -c | sort -nr | head -3
   ```

## Code César

24. **Passer en majuscules le fichier clair et créer le fichier `cesar` :**
   ```bash
   tr 'a-z' 'A-Z' < clair > cesar
   ```

25. **Coder le fichier `cesar` avec un décalage de 1 caractère vers la droite et créer `crypto` :**
   ```bash
   tr 'A-Z' 'B-ZA' < cesar > crypto
   ```

26. **Décoder le fichier `crypto` avec un décalage de 1 caractère vers la gauche :**
   ```bash
   tr 'A-Z' 'ZA-Y' < crypto
   ```

27. **Coder le fichier `cesar` avec un décalage de 13 caractères vers la droite et créer `crypto13` :**
   ```bash
   tr 'A-Z' 'N-ZA-M' < cesar > crypto13
   ```

28. **Coder à nouveau le fichier `crypto13` et observer le résultat :**
   ```bash
   tr 'A-Z' 'N-ZA-M' < crypto13
   ```

29. **Est-ce qu’un décalage de 13 nécessite une commande de décodage ?**
   Non, car appliquer un décalage de 13 deux fois redonne le texte original. Cela ne fonctionnerait pas avec l'alphabet russe car il a plus de 26 lettres.

30. **Tester la commande précédente sur le fichier `proverbes` :**
   ```bash
   tr 'A-Z' 'N-ZA-M' < proverbes
   ```
