import mygraph as gr

graphe =   {"A " :{"C"},
            "B" : {"C", "E"},
            "C" : {"A", "B", "D", "E"},
            "D" : {"C"},
            "E" : {"C", "B"},
            "F" : set()
           }

g=gr.Graphe(graphe)
print(g.all_aretes())
print(g.all_sommets())
g.add_sommet("J")
g.add_arete(("F", "C"))
print(g.all_sommets())
print(g.all_aretes())