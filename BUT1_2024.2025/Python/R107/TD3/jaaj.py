import mygraph as gr
import math
from time import sleep

graphe =   {"A" :{"C"},
            "B" : {"C", "E"},
            "C" : {"A", "B", "D", "E"},
            "D" : {"C"},
            "E" : {"C", "B"},
            "F" : set()
           }

graphe2 =  {"A" : {"F", "D"},
            "B" : {"C"},
            "C" : {"B", "D", "E"},
            "D" : {"A", "F", "C"},
            "E" : {"C"},
            "F" : {"A", "D"}
           }

g=gr.Graphe(graphe)
g2=gr.Graphe(graphe2)

def BFS(sommet:str, graphe:gr.Graphe) -> tuple:
    Q=graphe.all_sommets()
    D=[(i, float("inf")) for i in Q]
    D=dict(D)
    D[sommet] = 0
    T=dict()
    while Q:
        v=Q.pop()
        for w in graphe._graphe_dict[v]:
            if D[w] == float('inf'):
                D[w] = D[v] + 1
                Q.insert(0, w)
                T[v] = w
    return (D, T)

def DFS(sommet:str, graphe:gr.Graphe) -> tuple:
    P = [sommet]
    D = {i: float("inf") for i in graphe.all_sommets()}
    D[sommet] = 0
    T = {}
    while P:
        v = P.pop()
        for w in graphe._graphe_dict[v]:
            if D[w] == float('inf'):
                D[w] = D[v] + 1
                P.append(w)
                T[w] = v
    return (D, T)

print(BFS("A", g2)[0])
print(DFS("A", g2)[0])