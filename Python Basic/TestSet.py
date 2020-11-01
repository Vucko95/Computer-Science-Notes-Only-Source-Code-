from Set import Set
    
set = Set()  # Create an empty set
set.add(45)
set.add(13)
set.add(43)
set.add(43)
set.add(1)
set.add(2)

print("Elements in set: " + str(set))
print("Number of elements in set: " + str(set.getSize()))
print("Is 1 in set? " + str(set.contains(1)))
print("Is 11 in set? " + str(set.contains(11)))

set.remove(2)
print("After deleting 2, the set is " + str(set))
print("The internal table for set is " + set.getTable())

set.clear()
print("After deleting all elements")
print("The internal table for set is " + set.getTable())