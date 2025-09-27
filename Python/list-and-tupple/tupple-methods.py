a=(1,45,23,1,54,45,436,2,False,"shivendra")
print(a)
print(type(a))

no=a.count(45)
print(no)
i=a.index(45)
print(i)
#in keyword
print(False in a)
print(len(a))
#unpacking
#p,q,r=a The problem with the unpacking part is that you're trying to unpack a tuple with more than 3 elements into only 3 variables:
# Unpack only 3 values from the tuple:
p, q, r = a[0], a[1], a[2]
print(p, q, r)

#if you want the first value in p, the last in r, and everything else in between in q:

p, *q, r = a
print(p, q, r)
