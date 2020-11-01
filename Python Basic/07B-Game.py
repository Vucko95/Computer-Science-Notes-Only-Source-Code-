__author__ = 'pythonspot.com'

age = 24
 
print("Guess my age, you have 1 chance!")
guess = int(raw_input("Guess: "))
 
if guess != age:
    print("Wrong!")
else:
    print("Correct")
