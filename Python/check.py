def my_decorator(func):
    def wrapper():
        print("Before function call")
        func()
        print("After function call")
    return wrapper

@my_decorator
def say_hello():
    print("Hello!")

say_hello()

# lower = int(input("Enter lower bound: "))
# upper = int(input("Enter upper bound: "))

# print(f"Prime numbers between {lower} and {upper} are:")

# for num in range(lower, upper + 1):
#     if num < 2:
#         continue
#     is_prime = True
#     for i in range(2, int(num**0.5) + 1):
#         if num % i == 0:
#             is_prime = False
#             break
#     if is_prime:
#         print(num, end=" ")

# Creating nested dictionary
# students = {
#     101: {"name": "Alice", "age": 20, "course": "B.Sc"},
#     102: {"name": "Bob", "age": 21, "course": "BCA"},
#     103: {"name": "Charlie", "age": 19, "course": "B.Com"}
# }

# # Display all students
# for roll, details in students.items():
#     print("Roll No:", roll)
#     print(" Name:", details["name"])
#     print(" Age:", details["age"])
#     print(" Course:", details["course"])
#     print()

# # Retrieve specific student details
# search_roll = int(input("Enter roll number to search: "))

# if search_roll in students:
#     info = students[search_roll]
#     print("Details of roll number", search_roll)
#     print("Name:", info["name"])
#     print("Age:", info["age"])
#     print("Course:", info["course"])
# else:
#     print("Student not found.")

# def tower_of_hanoi(n, source, auxiliary, destination):
#     if n == 1:
#         print(f"Move disk 1 from {source} to {destination}")
#         return
#     tower_of_hanoi(n - 1, source, destination, auxiliary)
#     print(f"Move disk {n} from {source} to {destination}")
#     tower_of_hanoi(n - 1, auxiliary, source, destination)

# # For n = 4
# tower_of_hanoi(4, "A", "B", "C")

# def tower_of_hanoi(n, source, auxillary, destination):
#     if n == 1:
#         print(f"Move disk 1 from {source} to {destination}")
#         return
#     tower_of_hanoi(n - 1, source, destination, auxillary)
#     print(f"Move disk {n} from {source} to {destination}")
#     tower_of_hanoi(n - 1, auxillary, source, destination)

# limit = int(input("Enter the limit: "))

# a, b = 0, 1

# while a <= limit:
#     print(a, end = " ")
#     a, b = b, a + b 

# import tkinter as tk

# def button_click(char):
#     current = entry.get()
#     entry.delete(0, tk.END)
#     entry.insert(0, current + char)

# def clear_entry():
#     entry.delete(0, tk.END)

# def calculate():
#     try:
#         expression = entry.get()
#         result = eval(expression)   # For simple demo; normally avoid eval
#         entry.delete(0, tk.END)
#         entry.insert(0, str(result))
#     except Exception:
#         entry.delete(0, tk.END)
#         entry.insert(0, "Error")

# root = tk.Tk()
# root.title("Simple Calculator")

# entry = tk.Entry(root, width=25, borderwidth=3, font=('Arial', 16))
# entry.grid(row=0, column=0, columnspan=4, padx=10, pady=10)

# buttons = [
#     '7', '8', '9', '/',
#     '4', '5', '6', '*',
#     '1', '2', '3', '-',
#     '0', '.', '=', '+'
# ]

# row = 1
# col = 0

# for char in buttons:
#     if char == '=':
#         btn = tk.Button(root, text=char, width=5, height=2,
#                         command=calculate)
#     else:
#         btn = tk.Button(root, text=char, width=5, height=2,
#                         command=lambda ch=char: button_click(ch))
#     btn.grid(row=row, column=col, padx=5, pady=5)
#     col += 1
#     if col > 3:
#         col = 0
#         row += 1

# clear_btn = tk.Button(root, text="C", width=5, height=2, command=clear_entry)
# clear_btn.grid(row=row, column=0, padx=5, pady=5)

# root.mainloop()

# import matplotlib.pyplot as plt

# # Sample data
# subjects = ['Python', 'C', 'Java', 'DBMS']
# marks = [85, 70, 90, 75]

# # Bar chart
# plt.figure(figsize=(6, 4))
# plt.bar(subjects, marks, color='skyblue')
# plt.title("Marks in Different Subjects")
# plt.xlabel("Subjects")
# plt.ylabel("Marks")
# plt.show()

# # Pie chart
# plt.figure(figsize=(6, 6))
# plt.pie(marks, labels=subjects, autopct='%1.1f%%', startangle=90)
# plt.title("Marks Distribution")
# plt.axis('equal')   # Make circle
# plt.show()

# from tkinter import *
# expr = ""  # Global expression string

# def press(key):
#     global expr
#     expr += str(key)
#     display.set(expr)

# def equal():
#     global expr
#     try:
#         result = str(eval(expr))
#         display.set(result)
#         expr = ""
#     except:
#         display.set("error")
#         expr = ""

# def clear():
#     global expr
#     expr = ""
#     display.set("")

# if __name__ == "_main_":
#     root = Tk()
#     root.configure(bg="light green")
#     root.title("Simple Calculator")
#     root.geometry("270x150")

#     display = StringVar()
#     entry = Entry(root, textvariable=display)
#     entry.grid(columnspan=4, ipadx=70)

# # Number buttons
#     btn1 = Button(root, text='1', fg='black', bg='red', command=lambda: press(1), height=1, width=7)
#     btn1.grid(row=2, column=0)
#     btn2 = Button(root, text='2', fg='black', bg='red', command=lambda: press(2), height=1, width=7)
#     btn2.grid(row=2, column=1)
#     btn3 = Button(root, text='3', fg='black', bg='red', command=lambda: press(3), height=1, width=7)
#     btn3.grid(row=2, column=2)
#     btn4 = Button(root, text='4', fg='black', bg='red', command=lambda: press(4), height=1, width=7)
#     btn4.grid(row=3, column=0)
#     btn5 = Button(root, text='5', fg='black', bg='red', command=lambda: press(5), height=1, width=7)
#     btn5.grid(row=3, column=1)

#     btn6 = Button(root, text='6', fg='black', bg='red', command=lambda: press(6), height=1, width=7)
#     btn6.grid(row=3, column=2)
#     btn7 = Button(root, text='7', fg='black', bg='red', command=lambda: press(7), height=1, width=7)
#     btn7.grid(row=4, column=0)
#     btn8 = Button(root, text='8', fg='black', bg='red', command=lambda: press(8), height=1, width=7)
#     btn8.grid(row=4, column=1)
#     btn9 = Button(root, text='9', fg='black', bg='red', command=lambda: press(9), height=1, width=7)
#     btn9.grid(row=4, column=2)
#     btn0 = Button(root, text='0', fg='black', bg='red', command=lambda: press(0), height=1, width=7)
#     btn0.grid(row=5, column=0)

#     # Operator buttons
#     plus = Button(root, text='+', fg='black', bg='red', command=lambda: press('+'), height=1, width=7)
#     plus.grid(row=2, column=3)
#     minus = Button(root, text='-', fg='black', bg='red', command=lambda: press('-'), height=1, width=7)
#     minus.grid(row=3, column=3)
#     mult = Button(root, text='', fg='black', bg='red', command=lambda: press(''), height=1, width=7)
#     mult.grid(row=4, column=3)
#     div = Button(root, text='/', fg='black', bg='red', command=lambda: press('/'), height=1, width=7)
#     div.grid(row=5, column=3)

#     # Other buttons
#     eq = Button(root, text='=', fg='black', bg='red', command=equal, height=1, width=7)
#     eq.grid(row=5, column=2)
#     clr = Button(root, text='Clear', fg='black', bg='red', command=clear, height=1, width=7)
#     clr.grid(row=5, column=1)
#     dot = Button(root, text='.', fg='black', bg='red', command=lambda: press('.'), height=1, width=7)
#     dot.grid(row=6, column=0)
    
# root.mainloop()

# import numpy as np 
# import matplotlib.pyplot as plt 

# barWidth = 0.25
# fig = plt.subplots(figsize =(12, 8)) 

# IT = [12, 30, 1, 8, 22] 
# ECE = [28, 6, 16, 5, 10] 
# CSE = [29, 3, 24, 25, 17] 

# br1 = np.arange(len(IT)) 
# br2 = [x + barWidth for x in br1] 
# br3 = [x + barWidth for x in br2] 

# plt.bar(br1, IT, color ='r', width = barWidth, 
#         edgecolor ='grey', label ='IT') 
# plt.bar(br2, ECE, color ='g', width = barWidth, 
#         edgecolor ='grey', label ='ECE') 
# plt.bar(br3, CSE, color ='b', width = barWidth, 
#         edgecolor ='grey', label ='CSE') 

# plt.xlabel('Branch', fontweight ='bold', fontsize = 15) 
# plt.ylabel('Students passed', fontweight ='bold', fontsize = 15) 
# plt.xticks([r + barWidth for r in range(len(IT))], 
#         ['2015', '2016', '2017', '2018', '2019'])

# plt.legend()
# plt.show()