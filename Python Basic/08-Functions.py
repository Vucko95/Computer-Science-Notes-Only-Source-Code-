#!/usr/bin/python
 
__author__ = 'pythonspot.com'

def highFive():
    return 5
 
def f(x,y):
    z = highFive()    # we get the variable contents from highFive()
    return x+y+z      # returns x+y+z. z is reachable becaue it is defined above
 
result = f(3,2)
print(result)
