try:
    a=int(input("enter a number: "))
    print(a)

except ValueError as v:
    print("wrong")
    print("invalid input",v)

except Exception as e:
    print(e)

print("thank you")

