import math
import random
import numpy as np

class DataPoint:
    """
    Class representing a data point with attributes (x) and class (y)

    :param x: list of float ; attributes of the data point
    :param y: int ; class of the data
    :param cles: list of str ; names of the attributes
    """
    def __init__(self, x, y, cles):
        self.x = {}
        for i in range(len(cles)):
            self.x[cles[i]] = float(x[i])
        self.y = int(y)
        self.dim = len(self.x)
        
    def __repr__(self):
        return 'x: '+str(self.x)+', y: '+str(self.y)


def load_data(filelocation):
    """
    Load data from a csv file
    The first line of the file must be the names of the attributes
    The last column must be the class of the data
    :param filelocation: str ; path to the file
    :return: list of DataPoint ; list of data points
    """
    with open(filelocation,'r') as f:
        data = []
        attributs = f.readline()[:-1].split(',')[:-1]
        for line in f:
            z = line.split(',')
            if z[-1] == '\n':
                z = z[:-1]
            x = z[:-1]
            y = int(z[-1])
            data.append(DataPoint(x,y,attributs))
    return data


class Noeud:
    """
    Class representing a node in a decision tree

    :param profondeur_max: int ; maximum depth of the tree
    """
    def __init__(self, profondeur_max=np.inf):
        self.question = None
        self.enfants = {}
        self.profondeur_max = profondeur_max
        self.proba = None
        self.hauteur = 0

    def prediction(self, x):
        """
        Predict the class of a data point

        :param x: list of float ; attributes of the data point
        :return: dict ; class probabilities
        """
        if self.question is None:
            return self.proba
        if question_inf(x, self.question[0], self.question[1]):
            return self.enfants["L"].prediction(x)
        else:
            return self.enfants["R"].prediction(x)
        
    def grow(self, data, min_size=1):
        """
        Grow the tree from a dataset

        :param data: list of DataPoint ; dataset
        :param min_size: int ; minimum number of data points in a node to split ; default is 1
        :return: null
        """
        self.proba = proba_empirique(data)
        if entropie(data) <= 0 or self.profondeur_max <= 0:
            return
        key, value = best_split(data)
        if key is None:
            return
        d1, d2 = split(data, key, value)
        if len(d1) >= min_size and len(d2) >= min_size:
            self.question = (key, value)
            self.enfants["L"] = Noeud(self.profondeur_max - 1)
            self.enfants["L"].grow(d1)
            self.enfants["R"] = Noeud(self.profondeur_max - 1)
            self.enfants["R"].grow(d2)
            self.hauteur = max(self.enfants["L"].hauteur, self.enfants["R"].hauteur) + 1

    def elagage(self, alpha, data):
        """
        Reduce the size of the tree by removing nodes with a gain of entropy lower than alpha, starting from the leaves

        :param alpha: float ; threshold for the gain of entropy
        :param data: list of DataPoint ; dataset
        :return: null
        """
        if self.question is None:
            return
        for enfant in self.enfants.values():
            enfant.elagage(alpha, data)
        if self.enfants["L"].question is None and self.enfants["R"].question is None:
            if gain_entropie(data, self.question[0], self.question[1]) < alpha:
                self.question = None
                self.enfants = {}
                self.hauteur = 0
        self.update_haut()

    def update_haut(self):
        """
        Update the height of the tree

        :return: null
        """
        if self.question is None:
            self.hauteur = 0
        else:
            self.enfants["L"].update_haut()
            self.enfants["R"].update_haut()
            self.hauteur = max(self.enfants["L"].hauteur, self.enfants["R"].hauteur) + 1

    def grow_partial(self, data, k, min_size=1):
        """
        Grow the tree from a dataset with a random subset of attributes

        :param data: list of DataPoint ; dataset
        :param k: int ; number of attributes to consider at each node
        :param min_size: int ; minimum number of data points in a node to split ; default is 1
        :return: null
        """
        self.proba = proba_empirique(data)
        if entropie(data) <= 0 or self.profondeur_max <= 0:
            return
        key, value = best_split_random(data, k)
        if key is None:
            return
        d1, d2 = split(data, key, value)
        if len(d1) >= min_size and len(d2) >= min_size:
            self.question = (key, value)
            self.enfants["L"] = Noeud(self.profondeur_max - 1)
            self.enfants["L"].grow_partial(d1, k)
            self.enfants["R"] = Noeud(self.profondeur_max - 1)
            self.enfants["R"].grow_partial(d2, k)
            self.hauteur = max(self.enfants["L"].hauteur, self.enfants["R"].hauteur) + 1


class ForetAleatoire:
    def __init__(self, n, profondeur_max=np.inf):
        self.n = n
        self.profondeur_max = profondeur_max
        self.foret = [Noeud(profondeur_max) for _ in range(n)]

    def grow_simple(self, data, k, min_size=1):
        for i in range(self.n):
            self.foret[i].grow_partial(data, k, min_size)

    def grow(self, data, k, n, min_size=1):
        for i in range(self.n):
            bootstrap_data = bootstrap(data, n)
            self.foret[i].grow_partial(bootstrap_data, k, min_size)

    def prediction(self, x):
        predictions = [noeud.prediction(x) for noeud in self.foret]
        return {key: sum([p[key] for p in predictions]) / len(predictions) for key in predictions[0].keys()}


def proba_empirique(data):
    """
    Compute the empirical class probabilities of a dataset

    :param data: list of DataPoint ; dataset
    :return: dict ; class probabilities
    """
    proportion = {}
    for d in data:
        classe = d.y
        if proportion.get(classe) is None:
            proportion[classe] = 1
        else:
            proportion[classe] += 1
    for key in proportion.keys():
        proportion[key] /= len(data)
    return proportion


def question_inf(x, a, s):
    """
    Ask a question on an attribute of a data point

    :param x: list of float ; attributes of the data point
    :param a: int ; attribute index
    :param s: float ; threshold
    :return: bool ; True if x[a] < s, False otherwise
    """
    return x[a] < s


def split(data, a, s):
    """
    Split a dataset according to a question on an attribute

    :param data: list of DataPoint ; dataset
    :param a: int ; attribute index
    :param s: float ; threshold
    :return: tuple of list of DataPoint ; data points for which x[a] < s, data points for which x[a] >= s
    """
    d1 = []
    d2 = []
    for d in data:
        if question_inf(d.x, a, s):
            d1.append(d)
        else:
            d2.append(d)
    return d1, d2


def list_separ_attributs(data, a):
    """
    List the possible values of an attribute in a dataset

    :param data: list of DataPoint ; dataset
    :param a: int ; attribute index
    :return: list of float ; possible values of the attribute
    """
    values = list(set([d.x[a] for d in data]))
    values.sort()
    return [(values[i] + values[i+1])/2 for i in range(len(values)-1)]


def liste_questions(data):
    """
    List the possible questions on the attributes of a dataset

    :param data: list of DataPoint ; dataset
    :return: dict ; possible questions on the attributes
    """
    questions = {}
    for key in data[0].x.keys():
        questions[key] = list_separ_attributs(data, key)
    return questions


def entropie(data, base=2):
    """
    Compute the entropy of a dataset

    :param data: list of DataPoint ; dataset
    :param base: int ; logarithm base ; default is 2 ; for better results, use the number of classes
    :return: float ; entropy
    """
    proportion = proba_empirique(data)
    h = 0
    for value in proportion.values():
        h -= value * math.log(value, base) if value != 0 else 0
    return h


def gain_entropie(data, a, s):
    """
    Compute the gain of entropy of a dataset after a split on an attribute

    :param data: list of DataPoint ; dataset
    :param a: int ; attribute index
    :param s: float ; threshold
    :return: float ; gain of entropy
    """
    d1, d2 = split(data, a, s)
    r1, r2 = len(d1) / len(data), len(d2) / len(data)
    return entropie(data) - (r1*entropie(d1)) - (r2*entropie(d2))


def best_split(data):
    """
    Find the best split on the attributes of a dataset

    :param data: list of DataPoint ; dataset
    :return: tuple of int, float ; attribute index, threshold
    """
    questions = liste_questions(data)
    best_gain, best_key, best_value = 0, None, None
    for key in questions.keys():
        for value in questions[key]:
            gain = gain_entropie(data, key, value)
            if gain > best_gain:
                best_key = key
                best_value = value
                best_gain = gain
    return best_key, best_value


def best_split_random(data, k):
    """
    Find the best split on a random subset of attributes of a dataset

    :param data: list of DataPoint ; dataset
    :param k: int ; number of attributes to consider
    :return: tuple of int, float ; attribute index, threshold
    """
    questions = liste_questions(data)
    best_gain, best_key, best_value = 0, None, None

    random_keys = list(questions.keys())
    random.shuffle(random_keys)
    random_keys = random_keys[:min(k, len(random_keys))]

    for key in random_keys:
        for value in questions[key]:
            gain = gain_entropie(data, key, value)
            if gain > best_gain:
                best_key = key
                best_value = value
                best_gain = gain
    return best_key, best_value


def most_likely_class(vector):
    """
    Find the class with the highest probability in a vector

    :param vector: dict ; class probabilities
    :return: tuple of int, float ; class, probability
    """
    max_value = None
    max_key = None
    for key in vector.keys():
        if max_value is None or vector[key] > max_value:
            max_value = vector[key]
            max_key = key
    return max_key, max_value


def precision(noeud, data):
    """
    Compute the precision of a tree on a dataset

    :param noeud: Noeud ; tree to evaluate
    :param data: list of DataPoint ; data to evaluate on
    :return: float ; precision of the tree
    """
    correct = 0
    for d in data:
        if most_likely_class(noeud.prediction(d.x))[0] == d.y:
            correct += 1
    return correct / len(data)


def precision_foret(foret, data, method="vote"):
    """
    Compute the precision of a forest on a dataset
    \n "average" computes the average precision of the trees in the forest
    \n "best" computes the precision of the best tree in the forest
    \n "vote" computes the precision of the forest by majority vote

    :param foret: ForetAleatoire ; forest to evaluate
    :param data: list of DataPoint ; data to evaluate on
    :param method: str ; method to compute the precision of the forest. Can be "average", "best" or "vote"
    :return: float ; precision of the forest
    :raises: ValueError ; if method is not "average", "best" or "vote"
    """
    if method == "average":
        return sum([precision(noeud, data) for noeud in foret.foret]) / len(foret.foret)
    elif method == "best":
        return max([precision(noeud, data) for noeud in foret.foret])
    elif method == "vote":
        correct = 0
        for d in data:
            votes = {}
            for noeud in foret.foret:
                prediction = noeud.prediction(d.x)
                for key in prediction.keys():
                    if votes.get(key) is None:
                        votes[key] = prediction[key]
                    else:
                        votes[key] += prediction[key]
            if most_likely_class(votes)[0] == d.y:
                correct += 1
        return correct / len(data)
    else:
        raise ValueError("method must be 'average', 'best' or 'vote'")


def bootstrap(data, n):
    """
    Generate a random sample of n elements from data
    Uniformly sample with replacement
    :param data: list of DataPoint ; data to sample from
    :param n: int ; number of elements to sample
    :return: list of DataPoint ; sample
    """
    return [data[random.randint(0, len(data)-1)] for _ in range(n)]