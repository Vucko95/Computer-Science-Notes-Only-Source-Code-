def main():
    try:
        number1, number2 = eval(
          input("Enter two numbers, separated by a comma: "))      
        result = number1 / number2
        print("Result is " + str(result))
    except ZeroDivisionError:
        print("Division by zero!")
    except SyntaxError:
        print("A comma may be missing in the input")
    except:
        print("Something wrong in the input")
    else:
        print("No exceptions")
    finally:
        print("The finally clause is executed")

main()