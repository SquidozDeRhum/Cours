import numpy as np

t1 = [5, 6, 7, 8, 9]
t2 = [1, 1, 1 ,1, 1]
t3 = [[1],
      [2],
      [3]]
t4 = [[1, 2, 4],
      [-1, 2, 3],
      [1, 8, 9]]

m1 = np.array(t1)
m2 = np.array(t2)
m3 = np.array(t3)
m4 = np.array(t4)

m5 = np.append(m1, [10], axis=0)

m6 = np.append(m2, m1, axis=0)

m7 = np.vstack([m1, m2])

m8 = np.vstack([m3, [4]])

m9 = np.append(m4, [[1], [7], [4]], axis=1)

m10 = np.append(m4, [[1], [2], [3]], axis=1)

m12 = np.append([2], m2)

m13 = np.vstack([[9], m3, [8]])

m14 = np.delete(m4, 1, 0)

m15 = np.delete(m1, [0, 2], 0)

m16 = m1
m16[0] = 8
m16[2] = 8

m17 = np.delete(m4, 1, 1)

def absolue(number:int):
      if number < 0:
            number = -number
      return number

def fact(number:int):
            

print(absolue(-0))