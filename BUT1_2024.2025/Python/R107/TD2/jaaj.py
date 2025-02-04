import mygraph as gr

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
"""
print(g.all_aretes())
print(g.all_sommets())
print(g.all_sommets())
print(g.all_aretes())
"""

g.add_sommet("J")
g.add_arete(("F", "C"))

print(g.all_sommets())
print(g2.trouve_tous_chemins("A", "E"))