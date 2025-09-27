class employee:
    language = "py"
    salary = 25578500

    def __init__(self,name,salary,language):#dunder method which is called automatically
        self.name=name
        self.salary=salary
        self.language=language
        print("i am creating an object")

    def getinfo(self):
        print(f"The language is {self.language}. The salary is {self.salary}")

rohan = employee("rohan",43000000,"c++")
# rohan.salary = 1200000
# rohan.language = "java"
# rohan.name="rohan"
#print(rohan.name,rohan.salary,rohan.language)
#output will be the print statement above along with init print
#this is because dunder method is called as soon as an object is created
rohan.getinfo()
class Car:

    def __init__(self, make, model):
        self.make = make
        self.model = model

    def get_info(self):
        print(f"make : {self.make} , model : {self.model}")

car = Car("ferrari" , "sf90")
car.get_info()
