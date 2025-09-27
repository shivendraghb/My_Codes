class employee:
    def __init__(self):
        print("constructor of employee class")
    a=1

class programmer(employee):
    def __init__(self):
        print("constructor of programmer class")
    b=2

class manager(programmer):
    def __init__(self):
        super().__init__()#suepr() is used to call the constructor of the parent class
        #here it will call the constructor of programmer class
        print("constructor of manager class")
    c=3

# o=employee()
# print(o.a)#prints the a attribute
#print(o.b)#shows an errror as b is not an attribute of employee

# o=programmer()
# print(o.a,o.b)

o=manager()
print(o.a,o.b,o.c)
