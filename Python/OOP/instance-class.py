#instance attribute take preference
#over class attribute during assignment and retrieval

class employee:
    language="py" #this is a class attribute
    salary=25578500

# anuj=employee()
# anuj.name="shivendra" #this is an instance attribute
# print(anuj.name,anuj.language,anuj.salary)

rohan=employee()
# rohan.name="rohan roro robinson"
rohan.salary=1200000
rohan.language="java"
print(rohan.salary,rohan.language)

# here name is instance attribute and salary and language are the class
# attributes as they directly belong to the class

