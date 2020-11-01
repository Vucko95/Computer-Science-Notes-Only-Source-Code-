from LinkedList import LinkedList

class Queue:
    def __init__(self):
        self.__elements = LinkedList()

    # Adds an element to this queue
    def enqueue(self, e):
        self.__elements.add(e)
    
    # Removes an element from this queue
    def dequeue(self):
        if self.getSize() == 0:
            return None
        else:
            return self.__elements.removeAt(0)
    
    # Return the size of the queue
    def getSize(self):
        return self.__elements.getSize()
    
    # Returns a string representation of the queue
    def __str__(self):
        return self.__elements.__str__()

    # Return true if queue is empty 
    def isEmpty(self):
        return self.getSize() == 0
