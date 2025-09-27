from functools import reduce
# Map example
l=[1,2,3,4,5]

square=lambda x: x*x

sqlist=map(square,l)
print(list(sqlist)) # output : 1,4,9,16,25

# Filter example
def even(n):
    if(n%2==0):
        return True
    return False

onlyeven=filter(even,l)
print(list(onlyeven)) # output : 2,4

# Reduce example
def sum(a,b):
    return a+b

mul = lambda x,y:x*y

print(reduce(sum, l))
print(reduce(mul, l))
