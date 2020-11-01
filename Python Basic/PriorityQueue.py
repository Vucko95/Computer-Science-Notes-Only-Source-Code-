from Heap import Heap

class PriorityQueue:
    def __init__(self):
        self.__heap = Heap()

    # Adds an element to this queue
    def enqueue(self, e):
        self.__heap.add(e)
    
    # Removes an element from this queue
    def dequeue(self):
        if self.getSize() == 0:
            return None
        else:
            return self.__heap.remove()
    
    # Return the size of the queue
    def getSize(self):
        return self.__heap.getSize()
