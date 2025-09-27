marks={
    "harry":100,
    "shubham":56
}

print(marks.items())
print(marks.keys())#gives the left hand side terms
print(marks.values())
marks.update({"harry": 99,"shivendra": 100})#dictionary is mutable
print(marks)

print(marks.get("srishti"))#output none
# print(marks["aditi"])#returns an error

#pop()
#popitem()takes no argument
marks.pop("harry")
print(marks)
marks.popitem()
print(marks)

