for i in range(100):
    if(i==34):
        break #exit the loop right now
    print(i)

print("******************")

for i in range(100):
    if(i==34):
        print("*******here********")
        continue #skip this iteration
    print(i)
