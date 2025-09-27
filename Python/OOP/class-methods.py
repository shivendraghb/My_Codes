class employee:
    a=1
#a class method is a method which is bound to the class and not the object of the class
# @classmethod decorator is used to create a class method
    @classmethod
    def show(self):
        print(f"the class attribute of a is {self.a}")

e=employee()
e.a=45

e.show()
