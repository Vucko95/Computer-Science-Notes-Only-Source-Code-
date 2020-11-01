# Prompt the user for input
seconds = eval(input("Enter an integer for seconds: "))

# Get minutes and remaining seconds
minutes = seconds // 60     # Find minutes in seconds
remainingSeconds = seconds % 60   # Seconds remaining
print(seconds, "seconds is", minutes,  
  "minutes and", remainingSeconds, "seconds")
