# A stub for printMonth may look like this 
def printMonth(year, month): 
    print("printMonth")
  
# A stub for printMonthTitle may look like this 
def printMonthTitle(year, month): 
    print("printMonthTitle")

# A stub for getMonthBody may look like this 
def printMonthBody(year, month): 
    print("printMonthBody")

# A stub for getMonthName may look like this 
def getMonthName(month): 
    print("getMonthName")

# A stub for getStartDay may look like this 
def getStartDay(year, month): 
    print("getStartDay")

# A stub for getTotalNumberOfDays may look like this 
def getTotalNumberOfDays(year, month): 
    print("getTotalNumberOfDays")

# A stub for getNumberOfDaysInMonth may look like this 
def getNumberOfDaysInMonth(year, month): 
    print("getNumberOfDaysInMonth")

# A stub for isLeapYear may look like this 
def isLeapYear(year): 
    print("isLeapYear")

def main():
    # Prompt the user to enter year and month 
    year = eval(input("Enter full year (e.g., 2001): "))
    month = eval(input((
        "Enter month as number between 1 and 12: ")))

    # Print calendar for the month of the year
    printMonth(year, month)
 
main()
