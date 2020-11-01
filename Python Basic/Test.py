myList = [1, 2, 3, 4, 5, 6]
for i in range(4, -1, -1):
    myList[i + 1] = myList[i]

for i in range(0, 6): 
    print(myList[i], end = " ")