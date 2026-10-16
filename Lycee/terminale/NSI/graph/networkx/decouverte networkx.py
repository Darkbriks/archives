import networkx as nx
import matplotlib.pyplot as plt
#création d'un graphe dont le nom est g1
g1 = nx.Graph()
#ajouter des sommets à g1
g1.add_node(1)
g1.add_node(2)
g1.add_node(3)
g1.add_node(4)
g1.add_node(5)
g1.add_node(6)
#ajouter des arcs entre les sommets de g1
g1.add_edge(1,2)
g1.add_edge(1,3)
g1.add_edge(1,4)
g1.add_edge(2,3)
g1.add_edge(2,4)
g1.add_edge(2,6)
#dessiner g1
#nx.draw(g1, with_labels=True, font_weight='bold', node_size=800, node_color='lightgrey')
#montrer g1
#plt.show()
#nx.draw(g1)
#enregistrer l'image
#plt.savefig("mon_beau_graphe.png")
"""
#nombre de noeuds, de sommets
print('sommet : ', nx.number_of_nodes(g1))
#nbr d'arêtes
print('arete : ',nx.number_of_edges(g1))

# voisins du sommet 1
for elt in nx.neighbors(g1,1):
    print('voisins de 1',elt)
    
# ou list(nx.neighbors(g1,1))
    
for elt in nx.all_neighbors(g1,2):
    print('voisins de 2',elt)

#degré du sommet 1
print('degré de 1',nx.degree(g1, 1))
#liste de tous les sommets avec le degré
print(nx.degree(g1))
    
#création d'un graphe orienté à partir de listes
liste1=['a','b','c','d','e','f','g','h']
g2 = nx.DiGraph()
g2.add_nodes_from(liste1)
liste2=[('a','b'),('a','c'),('b','d'),('b','e'),('c','d'),('d','e'),
('e','g'),('e','f'),('g','f'),('g','h')]
g2.add_edges_from(liste2)
#nx.draw(g2, with_labels=True)
#plt.show()

G=nx.Graph()
#Pour créer un ou plusieurs nœuds, on procède de la façon suivante: 
G.add_node('Picsou')
# ajouter un seul nœud au nom de 1
G.add_nodes_from(['Riri','Fifi','Loulou'])
# ajouter des nœuds à partir d'une liste
#Maintenant, on va ajouter les arêtes entre le noeuds. 
G.add_edges_from([('Riri', 'Picsou') ,( 'Riri','Fifi'), ('Fifi', 'Picsou') ,('Loulou', 'Picsou'),( 'Fifi','Loulou')])
nx.draw(G, with_labels=True, pos=nx.planar_layout(G))
#nx.draw(G)
plt.show()"""

G=nx.Graph()
G.add_nodes_from(['Nice','Marseille','Montpellier','Toulouse','Rennes','Paris','Nancy','Lyon'])
G.add_edges_from([('Nice','Marseille'),('Nice', 'Lyon'),('Marseille','Lyon'),
('Marseille','Montpellier'),('Montpellier','Toulouse'),('Toulouse','Rennes'),
('Toulouse','Paris'),('Rennes','Paris'),('Paris','Nancy'),('Paris','Lyon'),('Nancy','Lyon')])
nx.draw(G, with_labels=True, font_weight='bold', node_size=800, node_color='lightgrey')
plt.show()

"""
>>> g1 = nx.Graph()
>>> g1.add_node(1)
>>> g1.add_node(2)
>>> g1.add_node(3)
>>> g1.add_node(4)
>>> g1.add_edge(1, 2)
>>> g1.add_edge(1, 4)
>>> g1.add_edge(3, 4)
>>> g1.add_edge(3, 2)
>>> nx.draw(g1, with_labels=True, font_weight='bold', node_size=800, node_color='lightgrey')
>>> plt.show()
>>> g2 = nx.Graph()
>>> g2.add_nodes_from([1,2,3,4,5,6,9,10,11,12])
>>> g2.add_edges_from([(1,2),(1,3),(1,4),(2,3),(3,5),(4,5),(4,6),(9,10),(9,11),(9,12)])
>>> nx.draw(g2, with_labels=True, font_weight='bold', node_size=800, node_color='lightgrey')
>>> plt.show()
"""