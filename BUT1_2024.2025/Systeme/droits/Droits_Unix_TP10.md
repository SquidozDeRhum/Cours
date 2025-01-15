
# R1.04 - TP 10 - Droits Unix (suite)

## Partie 1 : Commandes et Droits Associés

Voici les droits nécessaires pour exécuter les commandes mentionnées dans le TP. Pour chaque commande, nous détaillons les ressources nécessaires et les droits (rwx) à appliquer.

### Commande `ls`
- **Ressource** : répertoire actuel.
- **Droits nécessaires** : 
  - Lecture (`r`) pour lister le contenu du répertoire.

### Commande `more actuels/doc.txt`
- **Ressource** : fichier `actuels/doc.txt` et répertoires parents.
- **Droits nécessaires** : 
  - Lecture (`r`) sur `doc.txt`.
  - Exécution (`x`) sur les répertoires parents.

### Commande `cd actuels/projet1`
- **Ressource** : répertoires `actuels` et `projet1`.
- **Droits nécessaires** : 
  - Exécution (`x`) sur chaque répertoire du chemin.

### Commande `ls actuels/projet1`
- **Ressource** : répertoire `actuels/projet1`.
- **Droits nécessaires** : 
  - Exécution (`x`) sur les répertoires parents.
  - Lecture (`r`) sur le répertoire pour lister son contenu.

### Commande `cp actuels/doc.txt anciens`
- **Ressource** : fichier `doc.txt`, répertoires `actuels` et `anciens`.
- **Droits nécessaires** : 
  - Lecture (`r`) sur `doc.txt`.
  - Exécution (`x`) sur les répertoires.
  - Écriture (`w`) dans `anciens` pour créer une copie.

## Partie 2 : Configuration des Droits

Voici les configurations des propriétaires, groupes et droits pour chaque situation décrite.

### Situation 1
- **Objectif** : Tout le monde peut entrer dans `actuels` et lister les fichiers. Seul Ben peut créer des sous-répertoires.
- **Configuration** : 
  - Propriétaire : Ben.
  - Groupe : tech.
  - Droits : 
    - Ben : `rwx`.
    - Groupe et autres : `r-x`.

### Situation 2
- **Objectif** : Ada a tous les droits sur `projet1`, Carl peut uniquement le lister, les autres n'ont aucun droit.
- **Configuration** : 
  - Propriétaire : Ada.
  - Groupe : tech.
  - Droits :
    - Ada : `rwx`.
    - Carl : `r-x`.
    - Ben et Dora : aucun droit.

### Situation 3
- **Objectif** : Tous peuvent accéder à `projet2`, seuls certains utilisateurs peuvent lister ou modifier.
- **Configuration** : 
  - Propriétaire : Carl.
  - Groupe : tech.
  - Droits : 
    - Carl : `rwx`.
    - Ada et Ben : `r-x`.
    - Autres : `--x`.

### Situation 4
- **Objectif** : Carl et Dora peuvent entrer dans `anciens` sans lister, Ben et Ada peuvent copier des fichiers.
- **Configuration** : 
  - Propriétaire : Carl.
  - Groupe : biz.
  - Droits :
    - Carl et Dora : `--x`.
    - Ben et Ada : `rwx`.

## Partie 3 : Concepts Complémentaires

### Setgid
Le setgid permet aux fichiers créés dans un répertoire d’hériter du groupe du répertoire parent.

```bash
# Exemple
ls -ld /FILER/ano*/SYS2017/tmps/
```

### Sticky Bit
Le sticky bit empêche les utilisateurs de supprimer des fichiers qui ne leur appartiennent pas, même s’ils ont les droits d’écriture sur le répertoire.

```bash
# Exemple
ls -ld /tmp
```

---
_Fichier généré automatiquement pour les exercices sur les droits Unix._
