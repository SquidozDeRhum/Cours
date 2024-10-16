# TD6 - Les tableaux

### Exercice 1

```pseudocode
procédure table()
début
	pour (entier : x := 0; x < 10; x++) faire
		pour (entier : y := 0; y < 10; y++) faire
			ecrire(x, " * ", y " = " x*y);
		fin_pour
	fin_pour
fin

programme usage
	procédure table();
début
	table();
fin
```

### Exercice 2

1. ```pseudocode
   procédure remplirTableau(tableau(entier)[n] : tab)
   début
   	pour (entier : i := 0; i < n; i++)
   		ecrire("Veuillez saisir un élément : ");
   		tab[i] := lire();
   	fin_pour
   fin
   
   procédure remplirTableau(tableau(entier)[n] : sortie tab, entier : nbElt)
   début
   	pour (entier : i := 0; i < nbElt; i++)
   		ecrire("Veuillez saisir un élément : ");
   		sortie tab[i] := lire();
   	fin_pour
   fin
   
   programme usage
   	constante entier : MAX := 100;
   	procédure remplirTableau(tableau(entier)[n] : tab, entier : nbElt);
   début
   	tableau(entier)[MAX] : tab;
   	remplirTableau(tab, MAX);
   fin
   ```

2. ```pseudocode
   procédure afficheTableau(tableau(entier)[n] : tab)
   début
   	pour (entier : i := 0; i < n; i++)
   		ecrire(tab[i]);
   	fin_pour
   fin
   
   programme usage
   	constante entier : MAX := 100;
   	procédure remplirTableau(tableau(entier)[n] : tab, entier : nbElt);
   	procédure afficheTableau(tableau(entier)[n] : tab);
   début
   	tableau(entier)[MAX] : tab;
   	remplirTableau(tab, MAX);
   	afficheTableau(tab);
   fin
   ```

   

