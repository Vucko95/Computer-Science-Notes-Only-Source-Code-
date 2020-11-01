# The function for finding a key in the list 
def linearSearch(lst, key):
    for i in range(len(lst)): 
        if key == lst[i]:
            return i
  
    return -1