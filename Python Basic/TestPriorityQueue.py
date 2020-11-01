from PriorityQueue import PriorityQueue

patient1 = [2, "John"]
patient2 = [1, "Jim"]
patient3 = [5, "Tim"]
patient4 = [7, "Cindy"]

priorityQueue = PriorityQueue()
priorityQueue.enqueue(patient1)
priorityQueue.enqueue(patient2)
priorityQueue.enqueue(patient3)
priorityQueue.enqueue(patient4)
    
while priorityQueue.getSize() > 0:
    print(str(priorityQueue.dequeue()), end = " ")
