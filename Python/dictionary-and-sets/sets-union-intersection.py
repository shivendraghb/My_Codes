s1={1,45,6}
s2={7,8,1,78}

print(s1.union(s2))
print(s1.intersection(s2))
print({1,6}.issubset(s1))
print({1,6,43,10}.issubset(s1))
print(s1.issuperset({1,6,43,10}))
