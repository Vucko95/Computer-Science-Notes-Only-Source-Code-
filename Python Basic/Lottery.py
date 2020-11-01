import random

# Generate a lottery
lottery = random.randint(0, 99)

# Prompt the user to enter a guess
guess = eval(input("Enter your lottery pick (two digits): "))

# Get digits from lottery
lotteryDigit1 = lottery // 10
lotteryDigit2 = lottery % 10

# Get digits from guess
guessDigit1 = guess // 10
guessDigit2 = guess % 10

print("The lottery number is", lottery)

# Check the guess
if guess == lottery:
    print("Exact match: you win $10,000")
elif (guessDigit2 == lotteryDigit1 and \
  guessDigit1 == lotteryDigit2):
    print("Match all digits: you win $3,000")
elif (guessDigit1 == lotteryDigit1 
        or guessDigit1 == lotteryDigit2 
        or guessDigit2 == lotteryDigit1 
        or guessDigit2 == lotteryDigit2):
    print("Match one digit: you win $1,000")
else:
    print("Sorry, no match")
