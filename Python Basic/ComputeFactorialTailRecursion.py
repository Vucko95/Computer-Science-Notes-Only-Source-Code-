# Return the factorial for a specified number 
def factorial(n):
    return factorialHelper(n, 1) # Call auxiliary function
  
# Auxiliary tail-recursive function for factorial 
def factorialHelper(n, result):
    if n == 0:
       return result
    else:
       return factorialHelper(n - 1, n * result) # Recursive call
