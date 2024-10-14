**Exercice 1** 

```pseudocode
procédure afficheMoy2Notes(reel note1; reel note2;)
début
	reel moyenne;
	retourne (note1 + note2) / 2;
fin

programme moyenne
debut

	reel algo1, algo2, moyenne;
	
	ecrire("Veuillez entrer votre première note : ");
	algo1 := lire();
	ecrire("Veuillez entrer votre seconde note : ");
	algo2 := lire();
	afficheMoy2Notes(algo1, algo2);
fin
```

**Tableau**

| Instructions | algo1 | algo2 | note1 | note2 | moyenne | commentaire |
| ------------ | ----- | ----- | ----- | ----- | ------- | ----------- |
| debut        | ND    | ND    | ND    | ND    | ND      |             |
| Déclaration  | NI    | NI    | ND    | ND    | NI      |             |
| ecrire       | NI    | NI    | ND    | ND    | NI      |             |
| lire         | 10.5  | NI    | ND    | ND    | NI      |             |
| ecrire       | 10.5  | NI    | ND    | ND    | NI      |             |
| lire         | 10.5  | 12.5  | ND    | ND    | NI      |             |
| fonction     | 10.5  | 12.5  | 10.5  | 12.5  | 11.5    |             |
| ecrire       | 10.5  | 12.5  | ND    | ND    | 11.5    |             |
| fin          | ND    | ND    | ND    | ND    | ND      |             |

 

**Exercice 2**

```pseudocode
procédure afficheRectangle(entier nbCol:entrée, entier nbLig:entrée)
début
	pour(entier i:=0; i< nbLig; i++) faire
		pour(entier p:=0; i<nbCol; p++) faire //Affiche ligne
			ecrire("*");
        fin pour
		ecrire("\n");
	fin pour
fin

programme Rectangle
	procédure afficheRectangle(entier nbCol, entier nbLig);
début
	entier colonnes, lignes;
	ecrire("Veuillez enter un nombre de colonnes : ");
	colonnes := lire();
```

