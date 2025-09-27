a=int(input("enter a number: "))
b=int(input("enter second number: "))

if(b==0):
    raise ZeroDivisionError("division by zero is not allowed")
else:
    print(f"the divison of {a} and {b} is {a/b}")
