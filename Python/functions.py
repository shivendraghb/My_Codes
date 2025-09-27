# def avg():
#     total=0
#     for i in range(3):
#         num=int(input("enter your marks: "))
#         total+=num
#     print(total/3)

# avg()

# def greet(name,ending):
#     print("good day, "+name)
#     print(ending)
#     return "done:)"

# a=greet("shivendra","thank you")#without return it will return none
# print(a)                        #if we want to print the value of a we need to return the value of a

def greet(name,ending="thank you"):
    print("good day",name)
    print(ending)

greet("shivendra")#if we provide the value of ending it will take that value otherwise it will take the default value provided in the function
greet("srishti","thank you for your time")
