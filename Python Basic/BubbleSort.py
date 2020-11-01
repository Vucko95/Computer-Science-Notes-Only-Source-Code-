def bubbleSort(list):
    needNextPass = True
    
    k = 1
    while k < len(list) and needNextPass:
        # List may be sorted and next pass not needed
        needNextPass = False
        for i in range(len(list) - k): 
            if list[i] > list[i + 1]:
                # swap list[i] with list[i + 1]
                temp = list[i]
                list[i] = list[i + 1]
                list[i + 1] = temp
          
                needNextPass = True # Next pass still needed

# A test method 
def main():
    list = [2, 3, 2, 5, 6, 1, -2, 3, 14, 12]
    bubbleSort(list)
    for v in list:
        print(v, end = "")

main()
