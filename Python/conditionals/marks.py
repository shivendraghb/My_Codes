marks=int(input("enter your marks: "))

if(marks<=100 and marks>=90):
    grade="Ex"
elif(marks<=90 and marks>=80):
    garde="A"
elif(marks<=80 and marks>=70):
    garde="B"
elif(marks<=70 and marks>=60):
    garde="C"
elif(marks<=60 and marks>=50):
    garde="D"
elif(marks<50):
    grade="F"

print("your grade is:",grade)
