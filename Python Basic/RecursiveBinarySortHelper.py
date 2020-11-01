def recursiveBinarySearch(list, key):
    low = 0
    high = len(list) - 1
    return recursiveBinarySearch(list, key, low, high)

def recursiveBinarySearchHelper(list, key, low, high):
    if low > high:  # The list has been exhausted without a match
        return -low - 1

    mid = (low + high) // 2
    if key < list[mid]:
        return recursiveBinarySearchHelper(list, key, low, mid - 1)
    elif key == list[mid]:
        return mid
    else:
        return recursiveBinarySearchHelper(list, key, mid + 1, high)

def main():
    list = [3, 5, 6, 8, 9, 12, 34, 36]
    print(list, 3)
    print(list, 4)

main()