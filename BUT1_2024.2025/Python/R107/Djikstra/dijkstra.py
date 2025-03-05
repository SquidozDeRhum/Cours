from graphe import Graphe

g = {"A" : {"C": 1},
     "B" : {"C": 2, "E": 3},
     "C" : {"A": 1, "B": 2, "D": 4, "E": 2},
     "D" : {"C": 4},
     "E" : {"C": 2, "B": 3},
     "F" : {}
    }

jaaj = Graphe(g)

def dijkstra(graphe:Graphe, sommet:str):
    D = [float('inf') for i in range(len(graphe))]
