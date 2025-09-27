class calculator:
    def __init__(self,n):
        self.n=n

    def square(self,n):
        self.n=n
        print(f"the square is {self.n*self.n}")
    def cube(self,n):
        self.n=n
        print(f"the cube is {self.n*self.n*self.n}")
    def squareroot(self,n):
        self.n=n
        print(f"the square root is {self.n**0.5}")

a=calculator(4)
a.square(6)
a.squareroot(49)
a.cube(5)
