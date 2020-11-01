from LinkedList import LinkedList

lst = LinkedList() #Create a linked lst
lst.add(1) 
lst.add(2) 
lst.add(3) 
lst.add(-3) 

for e in lst:
    print(e, end = ' ')
print()

iterator = iter(lst)
print(next(iterator))
print(next(iterator))
print(next(iterator))
print(next(iterator))
print(next(iterator))