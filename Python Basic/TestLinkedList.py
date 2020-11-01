from LinkedList import LinkedList

list = LinkedList()

# Add elements to the list
list.add("America") # Add it to the list
print("(1)", list)

list.insert(0, "Canada") # Add it to the beginning of the list
print("(2)", list)

list.add("Russia") # Add it to the end of the list
print("(3)", list)

list.addLast("France") # Add it to the end of the list
print("(4)", list)

list.insert(2, "Germany") # Add it to the list at index 2
print("(5)", list)

list.insert(5, "Norway") # Add it to the list at index 5
print("(6)", list)

list.insert(0, "Poland") # Same as list.addFirst("Poland")
print("(7)", list)

# Remove elements from the list
list.removeAt(0) # Remove the element at index 0
print("(8)", list)

list.removeAt(2) # Remove the element at index 2
print("(9)", list)

list.removeAt(list.getSize() - 1) # Remove the last element
print("(10)", list)
