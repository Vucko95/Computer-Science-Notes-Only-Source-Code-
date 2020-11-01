import re

regex = "\d{3}-\d{2}-\d{4}"
text = input("Enter a text: ")
match1 = re.search(regex, text)

if match1 != None:
    print(text, " contains a SSN")
    print("start position of the matched text is " + 
        str(match1.start()))
    print("start and end position of the matched text is " +
        str(match1.span()))
else:
    print(text, " does not contain a SSN")

