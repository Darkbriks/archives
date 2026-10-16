petite_base= [('RIBOT','Alexandre',101422011,[19,20,20,17,17,18,20]),
('GARGA', 'Amel', 20231343, [12, 8, 11, 17, 9]),
('POLO', 'Marcello', 20342241, [9, 11, 19, 3]),
('AMANGEAI', 'Hildegard', 20244229, [15, 11, 7, 14, 12]),
('DENT', 'Arthur', 42424242, [8, 4, 9, 4, 12, 5]),
('ALEZE', 'Blaise', 30012024, [17, 15, 20, 14, 18, 16, 20,4,15]),
('D2', 'R2', 10100101, [10, 14, 10, 7, 19, 10]),
('BLAISE','Pascal',10100111,[5,4,8,3,1,0,0])]
"""
1)petite_base est de type liste, les éléments de liste sont des tuples
2)obtenir tous les renseignements sur Garga : >>> petite_base[1]
3)obtenir le prénom de Garga : >>> petite_base[1][1]
4)obtenir le n° de Garga : >>> petite_base[1][2]
5)obtenir le notes de Aleze : >>> petite_base[5][3]
6)la deuxième note de Blaise:>>> petite_base[7][3][1]
7)la meilleur note de D2 : >>> max(petite_base[6][3])
8)print([etudiant[2] for etudiant in petite_base]) : la liste des numéros des étudiants
9)liste des noms de famille : print([etudiant[0] for etudiant in petite_base])
10)liste des meilleurs notes de chaque étudiant : print([max(etudiant[3]) for etudiant in petite_base])
11)la liste des tuples nom,nombre de devoirs pour les étudiants:
print([(etudiant[0],len(etudiant[3])) for etudiant in petite_base])
12)Le plus grand nombre de devoirs faits par un étudiant : >>> max([len(etudiant[3]) for etudiant in petite_base])
"""