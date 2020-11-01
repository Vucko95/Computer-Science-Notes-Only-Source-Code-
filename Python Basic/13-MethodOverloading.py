#!/usr/bin/env python
 
__author__ = 'pythonspot.com'

class Human:
 
    def sayHello(self, name=None):
 
        if name is not None:
            print('Hello ' + name)
        else:
            print('Hello ')
 
# Create instance
obj = Human()
 
# Call the method
obj.sayHello()
 
# Call the method with a parameter
obj.sayHello('Guido')
