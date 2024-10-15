***Docker***

Un conteneur : 
* Nécessite un ordinateur physique pour fonctionner
* Nécessite un hôte Linux
* Un conteneur est un espace confiné où s'éxécutent un ou des processus
* Permet de cloisonner et d'isoler son contenu
* Peut toujours partager des fichiers avec son hôte ou d'autres conteneurs

Syntaxe de pull d'images : docker image pull <nom_image>
Syntaxe pour lancer une image : docker container run <nom_image>
Syntaxe paramètres : docker container run <nom_image> which <paramètre>
Lister les conteneurs : docker container ps (-a)
Stopper un conteneur : docker container stop <ID>

Q1. Oui on trouve tictac, containerd-shim l'a lancé, l'utilisateur est 165536, PID : 17155

Q2. Non

Q3. L'emplacement de tictac, /bin/tictac
    Non on ne voit pas which car l'éxécution du docker s'est terminé

Q4. L'ensemble des conteneurs actifs

Q5. L'ensemble des conteneurs qui ont été actifs

Q6. Non Ctrl+C ne fonctionne pass

Q7. T1 s'est stoppé

Q8. Le conteneur à redémarré

Q9. Non il n'a pas repris