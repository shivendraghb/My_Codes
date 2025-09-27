words={
    "apple": "seb",
    "banana": "kela",
    "chutiya": "asshole",
    "school": "vidyalaya"
}

word=input("enter the word: ")
if word in words:
    print(f"the menaing of {word} is {words[word]}")
else:
    print("word not found")
    addword=input("do you want to add this word? (yes/no):")
    if addword.lower()=="yes":
        meaning=input("enter the meaning: ")
        words[word]=meaning

print(words[word])
