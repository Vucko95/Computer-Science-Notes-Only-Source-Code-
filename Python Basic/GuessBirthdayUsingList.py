def main():
    day = 0 # Day to be determined

    dates = [
      [[ 1,  3,  5,  7],
       [ 9, 11, 13, 15],
       [17, 19, 21, 23],
       [25, 27, 29, 31]],
      [[ 2,  3,  6,  7],
       [10, 11, 14, 15],
       [18, 19, 22, 23],
       [26, 27, 30, 31]],
      [[ 4,  5,  6,  7],
       [12, 13, 14, 15],
       [20, 21, 22, 23],
       [28, 29, 30, 31]],
      [[ 8,  9, 10, 11],
       [12, 13, 14, 15],
       [24, 25, 26, 27],
       [28, 29, 30, 31]],
      [[16, 17, 18, 19],
       [20, 21, 22, 23],
       [24, 25, 26, 27],
       [28, 29, 30, 31]]]
    
    for i in range(5):
        print("Is your birthday in Set" + str(i + 1) + "?")       
        for j in range(4):
             for k in range(4):
                 print(format(dates[i][j][k], '4d'), end = " ")
             print()

        answer = eval(input("Enter 0 for No and 1 for Yes: "))

        if answer == 1:
            day += dates[i][0][0]

    print("Your birth day is " + str(day))

main() # Call the main function
