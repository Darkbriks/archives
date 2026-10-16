import numpy.random

import interfacelib
import numpy as np

import time

class Joueur:
    def __init__(self, partie, couleur, opts={}):
        self.couleur = couleur
        self.couleurval = interfacelib.couleur_to_couleurval(couleur)
        self.jeu = partie
        self.opts = opts

    def demande_coup(self):
        pass


class Humain(Joueur):

    def demande_coup(self):
        pass



class IA(Joueur):
    def __init__(self, partie, couleur, opts={}):
        super().__init__(partie,couleur,opts)
        self.temps_exe = 0
        self.nb_appels_jouer = 0

class Random(IA):
    def demande_coup(self):
        start_time = time.time()
        liste_coups_valides = self.jeu.plateau.liste_coups_valides(self.couleurval)
        coup = liste_coups_valides[numpy.random.randint(0, len(liste_coups_valides))]
        self.temps_exe, self.nb_appels_jouer = time.time() - start_time, 1
        return coup

class Minmax(IA):
    def __init__(self, partie, couleur: str, opts: dict = None):
        super().__init__(partie, couleur, opts)
        if opts is None:
            opts = {}
        self.profondeur_max = opts.get("profondeur", 3)

    def demande_coup(self) -> list:
        """
        Retourne le meilleur coup en utilisant l'algorithme Minimax.
        """
        start_time = time.time()
        _, meilleur_coup = self.jeu.plateau.minimax(self.profondeur_max, self.couleurval, True, self)
        self.temps_exe += time.time() - start_time
        return meilleur_coup

class AlphaBeta(IA):
    def __init__(self, partie, couleur: str, opts: dict = None):
        super().__init__(partie, couleur, opts)
        if opts is None:
            opts = {}
        self.profondeur_max = opts.get("profondeur", 3)
        self.tri = opts.get("tri", False)

    def demande_coup(self):
        """
        Retourne le meilleur coup en utilisant l'algorithme Alpha-Beta.
        """
        start_time = time.time()
        _, meilleur_coup = self.jeu.plateau.alphabeta(self.profondeur_max, -np.inf, np.inf, self.couleurval, True, self.tri, self)
        self.temps_exe += time.time() - start_time
        return meilleur_coup
