# ***
# **
# *

# def pattern(n):
#     for i in range(n,0,-1):
#         print("*"*i)

# n=int(input("enter the number of steps: "))
# pattern(n)

def pattern(n):
    if(n==0):
        return
    print("*"*n)
    pattern(n-1)

n=int(input("enter the number of steps: "))
pattern(n)



