class employee:
    a=1

    @classmethod
    def show(cls):
        print(f"the class attribute if a is {cls.a}")

    @property
    def name(self):
        return f"{self.name1} {self.name2} {self.name3}"

    @name.setter
    def name(self,value):
        self.name1=value.split(" ")[0]
        self.name2=value.split(" ")[1]
        self.name3=value.split(" ")[2]

e=employee()
e.a=45

e.name="shivendra pratap srivastava"
print(e.name1,e.name2,e.name3)

e.show()

