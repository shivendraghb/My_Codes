def func():
    print("hello world")


if __name__ == "__main__":
    #if this code is directly executed by running the file its present in:
    print("we are running the main file")
    func()
    print(__name__)

# __name__ evaluates to the name of the module in python from where the program is ran
#  if the module is being run directly from the command line, the '__name__' is set to
# string "__main__". Thus, this behaviour is used to check whether the module is run
# directly or imported to another file.
