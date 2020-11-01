set1 = {"green", "red", "blue", "red"} # Create a set
print(set1)

set2 = set([7, 1, 2, 23, 2, 4, 5]) # Create a set from a list
print(set2)

print("Is red in set1?", "red" in set1)

print("length is", len(set2)) # Use function len
print("max is", max(set2)) # Use max
print("min is", min(set2)) # Use min
print("sum is", sum(set2)) # Use sum

set3 = set1 | {"green", "yellow"} # Set union
print(set3)

set3 = set1 - {"green", "yellow"} # Set difference
print(set3)

set3 = set1 & {"green", "yellow"} # Set intersection
print(set3)

set3 = set1 ^ {"green", "yellow"} # Set exclusive or
print(set3)

list1 = list(set2) # Obtain a list from a set
print(set1 == {"green", "red", "blue"}) # Compare two sets

set1.add("yellow")
print(set1)

set1.remove("yellow")
print(set1)
