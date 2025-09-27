class employee:
    # Class attributes
    language = "py"
    salary = 25578500

    # Instance method to print info
    def getinfo(self):
        # 'self' refers to the instance (e.g., rohan)
        print(f"The language is {self.language}. The salary is {self.salary}")

# Creating an instance of Employee
rohan = employee()

# Modifying instance attributes (these override class-level values for this instance)
rohan.salary = 1200000
rohan.language = "java"

# Calling instance method using the instance
# This is internally translated as: Employee.getinfo(rohan)
rohan.getinfo()

# Note:
# - 'getinfo()' must take at least one parameter (usually named 'self') to refer to the instance.
# - Without 'self', Python wouldn't know which instance's data to access.
