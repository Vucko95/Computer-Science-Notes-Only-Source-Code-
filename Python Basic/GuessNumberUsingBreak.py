import random

#Generate a random number to be guessed
number = random.randint(0, 100) 

print("Guess a magic number between 0 and 100")

while True: 
    #Prompt the user to guess the number
    guess = eval(input("Enter your guess: "))

    if guess == number: 
        print("Yes, the number is " + str(number))
        break
    elif guess > number:
        print("Your guess is too high")
    else:
        print("Your guess is too low")
