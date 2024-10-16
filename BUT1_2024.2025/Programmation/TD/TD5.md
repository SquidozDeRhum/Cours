# TD5 Les fonctions



### Exercice 1

1. Une seule valeur dans la procédure doit être modifié pour quelle soit transformé en fonction

2. Oui on peut toujours

3. ```
   borne1 : entrée
   borne2 : entrée
   resultat : entrée/sortie
   ```

4. ```pseudocode
   fonction fSomme(entier: borne1, entier:borne2) delivre entier
   debut
   	entier: i, som;
   	som := 0;
   	i := borne1;
   	tant_que (i <= borne2) faire
   		some := some+i;
   		i+=1;
   	fin tant_que
   	retourne som
   fin
   ```

5. ```pseudocode
   programme appel
   	procedure pSomme(entier: borne1, entier:borne2, sortie entier:resultat);
   	fonction fSomme(entier: borne1, entier:borne2);
   debut
   	entier : a := 3;
   	entier : b := 10;
   	entier : resultat;
   	psomme(a, b, resultat);
   	ecrire("Appel procédure : ", resultat);
   	ecrire("Appel fonction : ", fsomme(a, b));
   fin
   ```

   

### Exercice 2



1. ```pseudocode
   fonction fMoyenne(entier : a, entier : b) delivre reel
   debut
   	reel : res;
   	res := (a + b) / 2;
   	retourne res
   fin
   
   programme appel
   	fonction fMoyenne(entier: a, entier:b);
   debut
   	entier : a := 3;
   	entier : b := 10;
   	entier : c := 8;
   	entier : d := -2;
   	entier : e := -7;
   	entier : f := -3;
   	ecrire("Appel fonction : ", fsomme(a, b)); // 6.5
   	ecrire("Appel fonction : ", fsomme(c, d)); // 3
   	ecrire("Appel fonction : ", fsomme(e, f)); // -5
   fin
   ```

2. ```pseudocode
   fonction testSomme(entier : a, entier : b, entier : c) delivre booléen
   debut
   	retourne (a + b) == c
   fin
   
   programme appel
   	fonction testSomme(entier: a, entier:b, entier : c);
   debut
   	entier : a := 3;
   	entier : b := 10;
   	entier : c1 := 13;
   	entier : c := 8;
   	entier : d := -2;
   	entier : d1 := 6;
   	entier : e := -7;
   	entier : f := -3;
   	entier : f1 := -8;
   	ecrire("Appel fonction : ", fsomme(a, b, c1)); // vrai
   	ecrire("Appel fonction : ", fsomme(c, d, d1)); // vrai
   	ecrire("Appel fonction : ", fsomme(e, f, f1)); // faux
   fin
   ```

3. ```
   fonction unTestMoyenne(entier : note1, entier : note2, entier : resultatAttendu) delivre booleen
   	constante reel : EPSILON := 20;
   	fonction fMoyenne(entier : a, entier : b);
   debut
   	retourne abs(fMoyenne(note1, note2) - resultatAttendu) < EPSILON
   fin
   
   programme appel
   	fonction fmoyenne(entier: a, entier:b);
   	fonction unTestMoyene(entier : note1, entier : note2, entier : resultatAttendu);
   debut
   	entier : a := 3;
   	entier : b := 10;
   	entier : c := 6.5;
   	ecrire("Appel fonction : ", fsomme(a, b, c)); // vrai
   fin
   ```

4. ```
   fonction borne(entier : min, entier : max)
   debut
   	entier : res;
   	ecrire("Veuillez saisir un nombre compris entre ", a " et ", b);
   	res := lire();
   	tant_que (res < min OU res > max) faire
   		ecrire("Veuillez saisir un nombre compris entre ", a " et ", b);
   		res := lire();
   	fin_tant_que
   	retourne res
   fin
   
   programme feur
   	fonction borne(entier : min, entier : max);
   debut
   	entier : a := 4;
   	entier : b := 90;
   ```
   
   