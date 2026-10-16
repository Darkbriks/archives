note_une = input('rentrer la premiére note')
if note_une != 'ab' :
    note_une = float(note_une)
    
note_deux = input('rentrer la deuxieme note')
if note_deux != 'ab' :
    note_deux = float(note_deux)

if note_une != 'ab' :
    if note_deux != 'ab' :
        print((note_une + note_deux)/2)
    else :
        print('moyenne non signficative')