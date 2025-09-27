f=open("file.txt")

# f=open for readinng
# w for writing
# a open for appending
# + open for updating
# rb will open for read in binary
# rt will open for read in text mode

#lines=f.readlines()
#print(lines,type(lines))

# line1=f.readline()
# print(line1,type(line1))
# line2=f.readline()
# print(line2,type(line1))
# line3=f.readline()
# print(line3,type(line3))
line=f.readline()
while(line != ""):
    print(line)
    line=f.readline()

f.close()
