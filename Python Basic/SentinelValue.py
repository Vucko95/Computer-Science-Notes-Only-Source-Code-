data = eval(input("Enter an integer (the input exits " + 
    "if the input is 0): "))

# Keep reading data until the input is 0
sum = 0
while data != 0:
    sum += data

    data = eval(input("Enter an integer (the input exits " +
        "if the input is 0): "))

print("The sum is", sum)
