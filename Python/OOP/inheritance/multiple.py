class employee:
    company = "google"
    name="shivendra"
    def show(self):
        print(f"the name is {self.name} and the company is {self.company}")

class coder:
    language = "python"
    def printlanguages(self):
        print(f"here is your language: {self.language}")

# class programmer:
#     company = "microsoft"
#     def show(self):
#         print(f"the name is {self.name} and the salary is {self.salary}")

#     def showlanguage(self):
#         print(f"the name is {self.name} and the language is {self.language}")

class programmer(employee,coder):# inherited class employye
    company = "microsoft"
    def showlanguage(self):
        print(f"the name is {self.company} and he is good with {self.language} language")


a= employee()
b= programmer()

b.show()
b.printlanguages()
b.showlanguage()