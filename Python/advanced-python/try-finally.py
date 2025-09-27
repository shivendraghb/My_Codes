def main():
    try:
        a=int(input("enter a number: "))
        print(a)
        return

    except Exception as e:
        print(e)
        return

    finally:
        print("i am inside finally")

main()

# finally block is executed no matter what
# finally block is used to close the resources
