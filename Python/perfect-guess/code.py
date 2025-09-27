import random
n=random.randint(1,100)
a=-1
guess=0
while a!=n:
    guess+=1
    a=int(input("guess the number : "))
    if a<n:
        print("guess higher : ")
    elif a>n:
        print("guess lower : ")
    else:
        print(f"you guessed the number in {guess} attempts")
        break
