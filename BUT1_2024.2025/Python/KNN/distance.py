import math

def distanceOrigin2D(co :tuple):
    return sqrt(co[0]**2 + co[1]**2)

def d1(A, B):
    distance = 0
    for i in range(len(A)):
        distance += abs(A[i] - B[i])
    return distance

def d2(A, B):
    distance = 0
    for i in range(len(A)):
        distance += (A[i] - B[i]) ** 2
    return sqrt(distance)

def dp(A, B):
    feur = []
    distance = 0
    for i in range(len(A)):
        distance = abs(A[i] - B[i])
        feur.append(distance)
    return max(feur)

def knn(search:tuple, data:list, k:int) -> list:
    feur = list()
    for i in data:
        distance = dp(search[1], data[i][1])
        feur.append((data[i][0]), distance)
    feur.sort(key=lambda x: x[1])
    return feur[:k]