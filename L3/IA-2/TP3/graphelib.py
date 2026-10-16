import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np


class Graphe:
	def __init__(self):
		self.dic_noeud = {} #La clé est le numéro de département, la valeur le Noeud correspondant.
		self.lire_villes()
		self.lire_routes()

	def lire_villes(self, villes="villes.dat"):
		with open(villes, 'r') as f_villes:
			for line in f_villes:
				data_noeud = line.split(";")
				try:
					num_departement = int(data_noeud[0])
					nom_chef_lieu = data_noeud[1]
					position = [int(data_noeud[2]), int(data_noeud[3])]
					self.dic_noeud[num_departement] = Noeud(num_departement, nom_chef_lieu, position)
				except:
					pass
	
	def lire_routes(self, routes="routes.dat"):
		with open(routes, 'r') as f_routes:
			for line in f_routes:
				data_route = line.split(";")
				try:
					n = self.dic_noeud[int(data_route[0])]
					for num_v_s in data_route[1:]:
						voisin = self.dic_noeud[int(num_v_s)]
						n.aretes.append([voisin, distance_km(n, voisin)])
				except:
					pass
	
	def afficher_carte(self, carte_loc="france.png"):
		carte = mpimg.imread(carte_loc)
		plt.imshow(carte)

	"""
	Implémentation de l'algorithme de Dijkstra

	:param depart: un objet de la classe Noeud
	:param arrivee: un objet de la classe Noeud
	:return: un tuple (predecesseurs, distances)
	"""
	def dijkstra(self, depart, arrivee) -> tuple[dict, dict]:
		nb_noeuds_visites = 0
		non_visites = list(self.dic_noeud.values())
		distances = {n: np.inf for n in non_visites}
		distances[depart] = 0
		predecesseurs = {n: None for n in non_visites}

		while non_visites:
			sommet = min(non_visites, key=lambda x: distances[x])
			if sommet == arrivee:
				return predecesseurs, distances, nb_noeuds_visites
			non_visites.remove(sommet)
			nb_noeuds_visites += 1

			for voisin, distance in sommet.aretes:
				if voisin in non_visites:
					new_distance = distances[sommet] + distance
					if new_distance < distances[voisin]:
						distances[voisin] = new_distance
						predecesseurs[voisin] = sommet

		return predecesseurs, distances, nb_noeuds_visites

	"""
	Implémentation de l'algorithme A*
	La fonction heuristique est distance_km
	
	:param depart: un objet de la classe Noeud
	:param arrivee: un objet de la classe Noeud
	:return: un tuple (predecesseurs, distances, nb_noeuds_visites)
	"""
	def astar(self, depart, arrivee) -> tuple[dict, dict, int]:
		nb_noeuds_visites = 0
		non_visites = list(self.dic_noeud.values())
		distances = {n: np.inf for n in non_visites}
		distances[depart] = 0
		predecesseurs = {n: None for n in non_visites}

		while non_visites:
			sommet = min(non_visites, key=lambda x: distances[x] + distance_km(x, arrivee))
			if sommet == arrivee:
				return predecesseurs, distances, nb_noeuds_visites
			non_visites.remove(sommet)
			nb_noeuds_visites += 1

			for voisin, distance in sommet.aretes:
				if voisin in non_visites:
					new_distance = distances[sommet] + distance
					if new_distance < distances[voisin]:
						distances[voisin] = new_distance
						predecesseurs[voisin] = sommet

		return predecesseurs, distances, nb_noeuds_visites


class Carte:
	
	def __init__(self, graphe, carte_loc="france.png"):
		self.graphe = graphe
		self.carte = mpimg.imread(carte_loc)
		self.hauteur = self.carte.shape[0]
		
	def afficher(self):
		plt.imshow(self.carte)
		for n in self.graphe.dic_noeud.values():
			x1, y1 = n.position[0], n.position[1]
			for a in n.aretes:
				x2, y2 = a[0].position[0], a[0].position[1]
				plt.plot([x1,x2], [self.hauteur-y1, self.hauteur-y2], color="black", lw=1)
	
	def afficher_chemin(self, liste_noeud, color="red"):
		self.afficher()
		for i in range(len(liste_noeud)-1):
			x1, y1 = liste_noeud[i].position[0], liste_noeud[i].position[1]
			x2, y2 = liste_noeud[i+1].position[0], liste_noeud[i+1].position[1]
			plt.plot([x1,x2], [self.hauteur-y1, self.hauteur-y2], color=color, lw=1)

def distance_km(ville1, ville2):
	dx = ville1.position[0] - ville2.position[0]
	dy = ville1.position[1] - ville2.position[1]
	return 1.9 * np.sqrt(dx**2 + dy**2) #le facteur 1.9 convertit environ la distance entre pixels en kilomètres

class Noeud:
	
	def __init__(self, num, nom, pos):
		self.numero = num
		self.chef_lieu = nom
		self.position = pos
		self.aretes = [] #Une arete est de forme [N, d], où N est un Noeud et d la distance entre les deux Noeuds.


"""
Transforme le résultat de Dijkstra en le plus court chemin.

:param predecesseurs: un dictionnaire de la forme {Noeud: Noeud}
:param depart: un objet de la classe Noeud
:param arrivee: un objet de la classe Noeud
:return: une liste de Noeuds
"""
def plus_court_chemin(predecesseurs: dict, depart: Noeud, arrivee: Noeud) -> list[Noeud]:
	liste_noeud = [arrivee]
	n = arrivee
	while n != depart:
		n = predecesseurs[n]
		liste_noeud.append(n)
	return liste_noeud[::-1]