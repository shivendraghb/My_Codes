# '''
# 1 for snake
# -1 for water
# 0 for gun
# '''

# import random
# import time

# random.seed(int(time.time()))
# number=random.randint(0,100)
# print(number)
import random

computer= random.choice([-1,0,1])
youstr = input("enter your choice: ")
youdict={"s":1,"w":-1,"g":0}

you=youdict[youstr]

if(computer==you):
    print("draw")
else:
    if(computer==-1 and you==1):
        print("you win")
    elif(computer==-1 and you==0):
        print("you lose")
    elif(computer==1 and you==-1):
        print("you lose")
    elif(computer==1 and you==0):
        print("you win")
    elif(computer==0 and you==-1):
        print("you win")
    elif(computer==0 and you==1):
        print("you lose")
    else:
        print("something went wrong")
