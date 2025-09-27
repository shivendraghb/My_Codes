dict1={'a':1,'b':2}
dict2={'b':3,'c':4}

# Merge dict2 into dict1
merged = dict1 | dict2
print(merged)  # Output: {'a': 1, 'b': 3, 'c': 4}

# Update dict1 with dict2
dict1.update(dict2)
print(dict1)  # Output: {'a': 1, 'b': 3, 'c': 4}
# The original dict1 is modified
# The merged dictionary is a new dictionary, while the update method modifies the original dictionary in place.
