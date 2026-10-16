from tables import*
from time import *

modif=open('reciter.txt','a')

#The time() function returns the number of seconds passed since epoch.
#For Unix system, January 1, 1970, 00:00:00 at UTC is epoch (the point where time begins).
temps_seconds = time()
#ctime() function takes seconds passed since epoch as an argument and
# returns a string representing local time.
date= ctime(temps_seconds)

note=evaluer()

note=str(note)

modif.write(date+'la note est : '+note+'\n')

modif.close()


