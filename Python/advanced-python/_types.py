from typing import List,Union,Tuple

# n : int=5

# name : str="hello"

# def sum(a:int,b:int)->int:
#     return a+b

# print(name)
# print(sum(1,2))
# print(n)

#list of integers
numbers : list[int]=[1,2,3,4,5]

#tuple of a string and an integer
person : tuple[str,int]=("anuj",19)

#dictionary with string keys and integer values
scores : dict[str,int]={"anuj":100,"sachin":90}

#union type for variables that can hold multiple types
identifier : Union[str,int]="ID2411708"#Union is case sensitive
#identifier : str|int="ID2411708" #this is also valid in Python 3.10 and above
#identifier=2411708 #also valid

print(numbers)
print(person)
print(scores)
print(f"{identifier} is of type {type(identifier)}")

#these annotations help in making the code self-documenting and allows
#developers to understand the data structures used at a glance
