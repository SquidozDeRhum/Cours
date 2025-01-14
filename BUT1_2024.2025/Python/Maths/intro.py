import random

#Exercice 3

#1.
for i in range(0,9):
    print(i)

#2.
for i in range(2, 9, 2):
    print(i)

#3.
n = 600
S = int()

for i in range(n+1):
    S += i

Sb = 0.5*n*(n+1)

if Sb == S:
    print("L'affirmation est vrai !")
else:
    print("C'est pas vrai")

#Exercice 4

#1.
MaListe = list()
for i in range(10):
    MaListe.append(random.randint(0, 50))

print(MaListe)

max = MaListe[0]
for i in range(1, len(MaListe)):
    if MaListe[i] > max:
        max = MaListe[i]

print(max)