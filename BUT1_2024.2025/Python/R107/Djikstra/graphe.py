"""
Une classe Python pour creer et manipuler des graphes
"""
class Graphe(object):
    def __init__(self, graphe_dict=dict()):
        """ 
        initialise un objet graphe.
        Si aucun dictionnaire n'est
        créé ou donné, on en utilisera un
        vide
        """
        self._graphe_dict = graphe_dict
    def aretes(self, sommet):
        """ retourne une liste de toutes les aretes d'un sommet"""
        return self._graphe_dict[sommet]
    def all_sommets(self):
        """ retourne tous les sommets du graphe """
        sommets = list()
        for key, value in self._graphe_dict.items():
            sommets.append(key)
        return sommets
    def all_aretes(self):
        """ 
        retourne toutes les aretes du graphe
        à partir de la méthode privée,_list_aretes, à définir
        plus bas.
        Ici on fera donc simplement appel à cette méthode.
        """
        return self.__list_aretes()
    def add_sommet(self, sommet):
        """ 
        Si le "sommet" n'set pas déjà présent
        dans le graphe, on rajoute au dictionnaire
        une clé "sommet" avec une liste vide pour valeur.
        Sinon on ne fait rien.
        """
        if sommet not in self._graphe_dict.keys():
            self._graphe_dict[sommet] = dict()
    def add_arete(self, arete:list):
        """ 
        l'arete est de type set, tuple ou list;
        Entre deux sommets il peut y avoir plus
        d'une arete (multi-graphe)
        """
        for i in range(len(arete)):
            if type(arete[i]) == str:
                self._graphe_dict[arete[i]] += {arete[i + 1] : arete[i + 2]}
                self._graphe_dict[arete[i + 1]] += {arete[i] : arete[i + 2]}
    def __list_aretes(self):
        """ 
        Methode privée pour récupérers les aretes.
        Une arete est un ensemble (set)
        avec un (boucle) ou deux sommets.
        """
        aretes = list()
        for key, value in self._graphe_dict.items():
            for jaaj in value.keys():
                if key <= jaaj:
                    aretes.append((key, jaaj))
        return aretes
    def __iter__(self):
        """ 
        on crée un itérable à partir du graphe
        """
        self._iter_obj = iter(self._graphe_dict)
        return self._iter_obj
    def __next__(self):
        """ 
        Pour itérer sur les sommets du graphe 
        """
        return next(self._iter_obj)
    def __str__(self):
        res = "sommets: "
        for k in self._graphe_dict:
            res += str(k) + " "
        res += "\naretes: "
        for arete in self.__list_aretes():
            res += str(arete) + " "
        return res