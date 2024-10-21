# Résumé des commandes - TP 5 : Filtres

## Commande `wc` - Compter
- Compte les lignes, les mots et les caractères.
- **Syntaxe** :
  - `wc -l` : Compte les lignes.
  - `wc -c` : Compte les caractères.
  - `wc -w` : Compte les mots.

## Commande `sort` - Trier
- Trie les lignes de texte selon des critères spécifiés.
- **Syntaxe** :
  - `sort -t <sep> -k <champ_deb,champ_fin>` : Trie les lignes en fonction des champs définis, séparés par un caractère spécifique.
- **Options utiles** :
  - `-r` : Tri inversé.
  - `-n` : Tri numérique.
  - `-u` : Garde uniquement les lignes uniques.

## Commande `uniq` - Dédoublonner
- Supprime les doublons dans des lignes triées.
- **Syntaxe** :
  - `uniq` : Enlève les lignes en double.
- **Options utiles** :
  - `-i` : Ignore la casse.
  - `-d` : Affiche uniquement les lignes en double.

## Commande `colrm` - Supprimer des colonnes
- Supprime des colonnes de caractères dans un fichier à positions fixes.
- **Syntaxe** :
  - `colrm col1 [col2]` : Omet les colonnes spécifiées dans le fichier d'entrée.
lang prod | wc -w

## Commande `cut` - Couper des champs
- Extrait des champs dans des fichiers structurés par des séparateurs.
- **Syntaxe** :
  - `cut -d <sep> -f <champs>` : Coupe les champs spécifiés à partir d'un fichier en fonction du séparateur.

## Commande `head` - Garder les premières lignes
- Affiche les premières lignes d'un fichier.
- **Syntaxe** :
  - `head -n <nb>` : Affiche les `n` premières lignes du fichier.

## Commande `tail` - Garder les dernières lignes
- Affiche les dernières lignes d'un fichier.
- **Syntaxe** :
  - `tail -n <nb>` : Affiche les `n` dernières lignes du fichier.
- **Option utile** :
  - `-f` : Suivre le fichier en temps réel (utile pour les logs).

## Commande `tr` - Convertir
- Convertit ou supprime des caractères.
- **Syntaxe** :
  - `tr liste_cars_source liste_cars_rempl` : Convertit les caractères de la source en ceux de remplacement.
  - `tr -d liste_cars` : Supprime les caractères de la source spécifiés.

