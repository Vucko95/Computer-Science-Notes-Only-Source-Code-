# Prompt the user to enter three numbers
number1, number2, number3 = eval(input(
  "Enter three numbers separated by commas: "))

# Compute average
average = (number1 + number2 + number3) / 3

# Display result
print("The average of", number1, number2, number3,
    "is", average)
