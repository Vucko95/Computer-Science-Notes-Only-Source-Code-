class Stack:
    def __init__(self):
        self.__elements = []

    # Return true if the tack is empty
    def isEmpty(self):
        return len(self.__elements) == 0
    
    # Returns the element at the top of the stack 
    # without removing it from the stack.
    def peek(self):
        if self.isEmpty():
            return None
        else:
            return self.__elements[len(elements) - 1]

    # Stores an element into the top of the stack
    def push(self, value):
        self.__elements.append(value)

    # Removes the element at the top of the stack and returns it
    def pop(self):
        if self.isEmpty():
            return None
        else:
            return self.__elements.pop() 
    
    # Return the size of the stack
    def getSize(self):
        return len(self.__elements)