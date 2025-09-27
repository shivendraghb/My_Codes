try:
    a=int(input("enter a number: "))
    print(a)

except Exception as e:
    print(e)

else:
    print("i am inisde else")

# sometimes we want to run a piece of code when try is successful
# this is done using else
# else block is executed when try block is successful
