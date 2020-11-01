__author__ = 'pythonspot.com'

class User:
    name = ""
 
    def __init__(self, name):
        self.name = name
 
    def sayHello(self):
        print("Hello, my name is " + self.name)
 
# create virtual objects
james = User("James")
david = User("David")
eric = User("Eric")
 
# call methods owned by virtual objects
james.sayHello()
david.sayHello()
