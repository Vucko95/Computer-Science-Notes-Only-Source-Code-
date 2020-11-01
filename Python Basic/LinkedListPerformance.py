from LinkedList import LinkedList
import time

startTime = time.time()
list = LinkedList()
for i in range(100000):
   list.insert(0, "Chicago")
elapsedTime = time.time() - startTime
print("Time for LinkedList is", elapsedTime, "seconds")

startTime = time.time()
list = []
for i in range(100000):
   list.insert(0, "Chicago")
elapsedTime = time.time() - startTime
print("Time for list is", elapsedTime, "seconds")
