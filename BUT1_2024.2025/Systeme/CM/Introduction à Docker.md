**Introduction à Docker** 

**Virtualisation **: Un concept très ancien, démocratisation récente

* Principe : Emuler un ordinateur

**Terminologie**

* Host : machine physique
* Guest : la machine logique hébergée sur l'hôte
* Emulation : reproduction exacte d'un système dans un autre système
* Simulation : reproduction d'un système qui a l'apparence d'un autre système mais est totalement incompatible avec lui

**Avant la virtualisation** 

* c'était lourd (chiant) de faire de la maintenance

* Le système était indisponible pendant une migration de matériel

* "Scalabilité" (donner de plus en plus de puissance selon les besoins) compliqué

**Avec la virtualisation** 

* on  a un gros serveur physique qui host plusieurs VMs

* la migration et la scalabilité est bien plus simple car il n'y a besoin de changer l'OS que d'une machine

**Intérêts**

* Plusieurs Vms sur une seule machine
* Cloisonnement des VMs
* Administration et maintenance simplifiée
* Coûts mieux maîtrisés
  * Seules les VMs utiles sont lancées
  * Ressources concentrées sur moins de matériels et d'infrastructure
* Assurance d'un matériel standard du point de vue de la VM : le matériel est émulé, la VM ne voit pas le matériel physique
* Meilleures performances : affectation des ressources en fonction des besoins, parfois ponctuels

**Inconvénients**

* Une perte de performance avec la virtualisation du matériel
  * CPU
  * Accs disque
  * Réseau
  * Hyperviseur
* Une perte de performance avec la multiplication des OS

**Conteneurisation** : Une "sorte" de virtualisation mais en beaucoup plus léger

* Une machine host qui accueille des conteneurs (sortes de "machines logiques")
* Cloisonnement : environnement des conteneurs

**Différences fondamentales**

* Pas d'émulation
* Pas d'OS (kernel) pour les machines invitées
* Un cloisonnement par Name Spaces (Process, Mount, IPC, User et Network)
* Conteneurs ne voient pas les processus host
* L'Hôte voit les processus des conteneurs

Un conteneur est un processus du point de vue de l'host

**Avantages** 

* Architecture très légère
* Pas de surcharge CPU
* Une consommation de ressources maîtrisée
* Un démarrage très rapide
* Pas de pollution de l'hôte
* Elimination des incompatibilités

**Inconvénients**

* Le même OS pour tous les conteneurs, pas possible d'avoir des versions de noyau différentes
* Une gestion des droits plus complexe
* Nécessité d'avoir des droits admin pour certaines actions ou certaines configuration
* Pour Docker : uniquement Linux, mais des solutions existent pour Windows et macOS

**En standard, un conteneur c'est**

* Un processus
* Un noyau partagé avec l'host
* Une arborescence privée
* Un réseau privé local
* Une vision privée des processus + remappage des PIDs
* Un remappage des Users

**Un conteneur peut**

* Partager un bout de l'arborescence du FS avec son hôte
* Avoir un VPN partagé avec d'autres conteneur ciblés
* Partager la même pile TCP/IP que l'host
* Avoir root dans conteneur = root host

> [!NOTE]
>
> La sécurité, le cloisonnement et le partage de certains Name Spaces est géré par l'host

**Terminologie**

* **Image** : Un modèle de départ pour les conteneurs
  * construction par couches (Layers)
  
  * Layers ~= Calques
  
  * Un calque modifie la pile de calques du dessous
  
  * Tous les calques sont en lecture seule
  
  * Se base sur une autre image
  
  * Apporte ses adaptations (ajout de layers)
  
  * Peut servir de base à d'autres images
  
  * Layers en lecture seule = immuables, pas de risque de casser des images qu'il utilise
  
* **Conteneur (container)**
  * Une instanciation d'une image
  * Utilise les layers de l'images
  * Ajoute un layer supplémentaire
  * Les layers des images en RO sont partagés entre conteneurs
  * Est volatile
    * Par défaut les données sont dans le conteneur
    * Suppresion conteneur = données perdues
    * Pour persister les données : les volumes
  
* **Par image**

  * Historique de versions = tags

  * Tag "latest" = Dernière version

  * Conservation des versions
* **Networks**
  * Un conteneur voit son host, voit les autres conteneurs configurés aussi par défaut, accède au monde extérieur
  * Il n'accepte pas de connexion de l'extérieur


**Commande Docker**

* Types
  * Image
  * Container
  * Network
  * Volume

Syntaxe : docker <type> commande

Exemple :

```dockerfile
docker image pull --help
```

* run
  * Instancie un conteneur ) parti d'une image et démarre son exécution
  * Syntaxe : docker container run <image>[:tag]

Quand le processus d'un conteneur s'arrête, le conteneur s'arrête aussi

* 
