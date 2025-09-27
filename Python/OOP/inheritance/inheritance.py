class employye:
    company = "google"
    def shoe(self):
        print(f"the name is {self.name} and the salary is {self.salary}")


# class programmer:
#     company = "microsoft"
#     def show(self):
#         print(f"the name is {self.name} and the salary is {self.salary}")

#     def showlanguage(self):
#         print(f"the name is {self.name} and the language is {self.language}")

class programmer(employye):# inherited class employye
    company = "microsoft"
    def showlanguage(self):
        print(f"the name is {self.name} and the language is {self.language}")


a= employye()
b= programmer()
print(a.company, b.company)
