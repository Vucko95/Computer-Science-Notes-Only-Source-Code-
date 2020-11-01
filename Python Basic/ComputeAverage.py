# Prompt the user to enter three numbers
number1 = eval(input("Enter the first number: "))
number2 = eval(input("Enter the second number: "))
number3 = eval(input("Enter the third number: "))

# Compute average
average = (number1 + number2 + number3) / 3

# Display result
print("The average of", number1, number2, number3, 
    "is", average)
