from Queue import Queue

queue = Queue()# Create a queue

# Add elements to the queue
queue.enqueue("Tom") # Add it to the queue
print("(1)", queue)

queue.enqueue("John") # Add it to the queue
print("(2)", queue)

queue.enqueue("George") # Add it to the queue
queue.enqueue("Michael") # Add it to the queue
print("(3)", queue)

# Remove elements from the queue
print("(4)", queue.dequeue())
print("(5)", queue.dequeue())
print("(6)", queue)
