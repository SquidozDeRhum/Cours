**Exercice 1** : 

| Déroulement Programme | nb   | compteur | résultat | condition |
| --------------------- | ---- | -------- | -------- | --------- |
| Initialisation        | 3    | 1        | 0        | vraie     |
| Boucle                | 3    | 1        | 10       | vraie     |
| Boucle                | 3    | 2        | 20       | vraie     |
| boucle                | 3    | 3        | 30       | vraie     |
| Fin                   | 3    | 4        | 30       | fausse    |
| Initialisation        | 0    | 1        | 0        | fausse    |
| Fin                   | 0    | 1        | 0        | fausse    |
| Initialisation        | -3   | 1        | 0        | fausse    |
| Fin                   | -3   | 1        | 0        | fausse    |

**Exercice 2** : 

```pseudocode
programme Boucle
	const entier : MIN := 1;
	const entier : MAX := 49;
debut
	entier : input;
	ecrire("Veuillez entrer un nombre entier compris entre 1 et 49 (inclus) : ");
	input := lire();
	tant_que (input > MAX ou input < MIN) faire
		si input > 49 alors
			ecrire("Trop grand !");
		sinon
			ecrire("Trop petit !");
		ecrire("Erreur d'entrée, veuillez réessayer : ");
		input := lire();
	fin_tant_que
	ecrire("L'entrée est bonne :)");
fin
```

**Exercice 3** : 

```pseudocode
programme Suite
	const entier : FIN := -1;
debut
	entier : input, somme;
	tant_que (input != -1) faire
		ecrire("Veuillez saisir un entier positif (tapez ""-1"" pour mettre fin) : ");
		input := lire();
		si (input < 0) alors
			ecrire("Erreur de saisie, veuillez réessayer.");
		sinon si (input == -1) alors
			ecrire("Fin de la boucle");
		sinon
			somme += input;
	fin_tant_que
	ecrire("Somme des entrées : ", somme);
fin

// input = 3, 4, 5, -1 -> somme = 12
// input = -1 -> somme = /
// input = 5, 3, -7, -1 -> somme = 8
```

**Exercice 4** : 

```pseudocode
programme Division
debut
	entier nbTotalG, nbG;
	ecrire("Veuillez donner votre nombre total de gâteaux : ");
	nbTotalG := lire();
	ecrire("Veuillez donner le nombre de gâteaux que vous voulez donner à chaque invité : ");
	pour (entier i := -1; nbTotalG > 0; i++) faire
		nbTotalG -= nbG;
	fin_pour
	ecrire("Vous pouvez invité ", i" personnes, il restera ", -nbTotalG, "gâteaux");
fin
```

