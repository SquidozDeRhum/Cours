# Regex et Grep

***Expression Rationnelle*** : formulation permettant de décrire à l'aide d'une chaîne modèle unique, un ensemble de chaînes de caractères
Forme abrégée : Regex

Sous linux la commande associée au Regex est grep mais nous utiliserons egrep (Extended Grep)

***Options utiles de egrep***

* -i : ne fait pas de différence entre minuscles et majuscules
* -l : affiche seulement le nom des fichiers dont egrep à trouvé une correspondance
* -v : inversion de la correspondance
* -c : affiche le nombre de lignes qui ont matché avec le motif

Q1. egrep blanche < prod

Q2. egrep blan < prod Nous avons le même résultat

Q3. egrep lan < prod

* Nous n'avons pas le même résultat car une partie du motif se trouvait dans des lignes qui ne nous intéressent pas

Q4. egrep [7-9] < prod

Q5. egrep [7-9] -v < prod

Q6. egrep [AEIOU] -i < prod

Q7. egrep [AEIOU][AEIOU] -i < prod

Q8. egrep [AEIOU][AEIOU] -iv < prod

Q9. egrep [AY-] < depts

Un caractère quelconque n'est pas représenté par '?' mais par un point '.'

Q10. egrep 9...C < depts

Q11. egrep a.e < murphy

Pour mettre un point '.' dans le motif il faut le précéder d'un \, de plus il faut mettre le tout entre guillemets

Q12. egrep "\.\.\." < murphy

Q13. egrep "machine virtuelle" < lang

Q14. egrep b[a-z]*e < prod

Q15. egrep b[a-z]*e: < prod

Q16. egrep "\-.*\-" < depts

Q17. egrep [AEIOUY]l+e -i < depts

Q18. egrep 97?0 < lang

Q19. egrep 't,? ' -i  < murphy

Q20. egrep r{2}i < depts

Q21. egrep en{2} < depts

Q22. egrep ^L < murphy

Q23. egrep "\.$" < murphy

Q24. egrep [^A-Za-z0-9:' '] < depts

Q25. egrep "(an){2}" < prod

Q26. egrep "([A-Za-z]{2})\1" < prod

Q27. egrep "^[ck]|(ce)$" < prod