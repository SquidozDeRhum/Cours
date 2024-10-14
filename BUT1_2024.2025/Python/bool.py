#Exercice 1

note1 = 1

if note1 == 3:
    print("Bravo !!")
elif note1 >= 1.5:
    print("Pas mal !")
else:
    print("Vivement le prochain QCM :/")

#Exercice 2

note2 = 1

if note1 == 3 and note2 == 3:
    print("Quel(le) genie !")
elif (note1 == 3 or note2 == 3) and (note1 >= 1.5 or note2 >= 1.5):
    print("Bravo !")
elif note1 < 1.5 and note2 < 1.5:
    print("Vivement le prochain QCM :/")
if note2 > note1:
    print("En progrès :)")
elif note1 < note2:
    print("Attention !")
elif note1 == note2:
    print("Belle constance")

#Exercice 3

notes = [3, 3, 3, 3]

liste3 = list()

for i in notes:
    if i == 3:
        liste3.append(True)

if all(liste3):
    print("Très bel objectif !")
elif any(liste3):
    print("Bel objectif !")
else :
    print("Vise plus haut.")

#Exercice 4

Ljour=['roux','noir','gris']
Lnuit=['gris', 'gris', 'gris']

boolL = list()

choix = input("Veuillez choisir jour ou nuit : ")
print(choix)

if choix == 'jour':
    for i in Ljour:
        if i == 'gris':
            boolL.append(True)
else:
    for i in Lnuit:
        if i == 'gris':
            boolL.append(True)

if all(boolL):
    print("Tous les chats sont gris !")
else:
    print("Les chats ne sont pas tous gris ;()")