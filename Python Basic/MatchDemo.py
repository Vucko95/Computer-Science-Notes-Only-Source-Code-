import re

regex = "\d{3}-\d{2}-\d{4}"
ssn = input("Enter SSN: ")
match1 = re.match(regex, ssn)

if match1 != None:
    print(ssn, " is a valid SSN")
    print("start position of the matched text is " + 
        str(match1.start()))
    print("start and end position of the matched text is " +
        str(match1.span()))
else:
    print(ssn, " is not a valid SSN")
    