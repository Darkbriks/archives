nombre=int(input("entrez un entier "))
print('20 premiers multiples à partir de 0')
for pas in range(20):
    print(nombre,'x',pas,' = ',pas*nombre)

pas=0
while pas<20:
    print(nombre,'x',pas,' = ',pas*nombre)
    pas=pas+1

print('multiples inf à 15')
pas=0
while pas*nombre<=15:
    print(nombre,'x',pas,' = ',pas*nombre)
    pas=pas+3

    