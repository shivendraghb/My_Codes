def remove_strip(l,word):
    n=[]
    for item in l:
        if not(item==word):
            n.append(item.strip(word))

l=["shivendra","rohan","srishti","an"]
