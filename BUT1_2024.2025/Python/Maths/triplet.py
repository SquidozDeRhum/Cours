from math import sqrt

multi = 100

triplet = [(a, b, int(sqrt(a**2 + b**2))) for a in range(1,multi) for b in range(1,multi) if sqrt(a**2 + b**2)%1 == 0]

print(triplet)