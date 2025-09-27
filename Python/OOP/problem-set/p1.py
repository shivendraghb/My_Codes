class programmer:
    company="microsoft"
    def __init__(self,name,salary,pin):
        self.name=name
        self.salary=salary
        self.pin=pin


p=programmer("harry",1200000,273008)
print(p.name,p.salary,p.pin,p.company)
r=programmer("rohan",1200000,273008)
print(r.name,r.salary,r.pin,r.company)
