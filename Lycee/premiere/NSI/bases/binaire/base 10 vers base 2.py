def base10_to_base2(base10) :
    base2 = []
    while base10 > 2 :
        base2.append(base10%2)
        base10 = base10//2
    return base2
        