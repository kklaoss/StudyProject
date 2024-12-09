print('Задание №1')
a = input('x = ')
b = input('y = ')
c = input('z = ')
d = input('d = ')
e = input('e = ')
if int(a) < int(b): a = b
if int(a) < int(c): a = c
if int(a) < int(d): a = d
if int(a) < int(e): a = e
print('Наибольшее число:', a)
