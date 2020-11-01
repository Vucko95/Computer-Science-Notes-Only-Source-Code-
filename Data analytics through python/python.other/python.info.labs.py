#! ==============================================================================
#! NEW SECTION - Lab 1
#! ==============================================================================

english = ["hello", "cat", "dog", "yes", "tomorrow", "yesterday",
           "difficult", "easy", "bad", "no", "tuesday", "january"]
french = ["bonjour", "chat", "chien", "oui", "demain", "hier",
          "difficile", "facile", "mauvais", "non", "mardi", "janvier"]
if(len(english) % 2 == 0 and len(french) % 2 == 0):
    print("They are both even")
else:
    print("Lists are not both even")

#! next =========================== >

english = ["hello", "cat", "dog", "yes", "tomorrow", "yesterday",
           "difficult", "easy", "bad", "no", "tuesday", "january"]

#! next =========================== >

english = ["hello", "cat", "dog", "yes", "tomorrow", "yesterday",
           "difficult", "easy", "bad", "no", "tuesday", "january"]
french = ["bonjour", "chat", "chien", "oui", "demain", "hier",
          "difficile", "facile", "mauvais", "non", "mardi", "janvier"]
# Creating the Dictionary
english_and_french = {}
# They are both same length so can run loop for length of either one
for counter in range(len(english)):
    english_and_french[english[counter]] = french[counter]
print(english_and_french)

#! next =========================== >

english_french = {k: v for k, v in english_and_french.items() if(len(v) > 4)} print(english_french)

#! next =========================== >

print(english_french)

#! next =========================== >


def translate(dictionary, word_to_translate, default_word):
    if(word_to_translate in dictionary.keys()):
        print("Word found, translating...")
        print(dictionary[word_to_translate])
        print("Completed")
        return dictionary[word_to_translate]
           else:
                print("Not found")
            return default_word  # End of the function


response = translate(english_french, "dog", "Not in the dictionary")
print("Response is: ", response)

#! next =========================== >

english = ["hello", "cat", "dog", "yes", "tomorrow", "yesterday",
           "difficult", "easy", "bad", "no", "tuesday", "january"]

#! next =========================== >

english = ["hello", "cat", "dog", "yes", "tomorrow", "yesterday",
           "difficult", "easy", "bad", "no", "tuesday", "january"]
french = ["bonjour", "chat", "chien", "oui", "demain", "hier",
          "difficile", "facile", "mauvais", "non", "mardi", "janvier"]
if(len(english) % 2 == 0 and len(french) % 2 == 0):
    print("They are both even")
else:
	print("Lists are not both even")

#! next =========================== >

english = ["hello", "cat", "dog", "yes", "tomorrow", "yesterday",
           "difficult", "easy", "bad", "no", "tuesday", "january"]
french = ["bonjour", "chat", "chien", "oui", "demain", "hier",
          "difficile", "facile", "mauvais", "non", "mardi", "janvier"]
# Creating the Dictionary
english_and_french = {}
# They are both same length so can run loop for length of either one
for counter in range(len(english)):
    english_and_french[english[counter]] = french[counter]
print(english_and_french)

#! next =========================== >


def translate(dictionary, word_to_translate, default_word): if(word_to_translate in dictionary.keys()):


print("Word found, translating...") print(dictionary[word_to_translate])
print("Completed")
return dictionary[word_to_translate]
else:
print("Not found")
return default_word
# End of the function
response = translate(english_french, "dog", "Not in the dictionary")
print("Response is: ", response)

#! ==============================================================================
#! NEW SECTION - Lab 2
#! ==============================================================================

# Setting global variable for practice
# How to get 2 decimal places: "{:1.2f}".format(x) total = 0;
# Function which takes in csv file path and sums up each row


def getTotal(file_path): try:


f = open(file_path, "r") lines = f.readlines()
f.close()
except IOError:
print("Unable to read from file", file_path)  # file path is correct
lineCounter = 1
for line in lines:  # Using global variable in this scope
global total
# line is the whole line #parts is a list of strings, need to convert each parts = line.split(",")
line = line.strip()
parts = (list(map(float, parts)))
total += sum(parts)
response = '''\
This is a {lineCounter}
Here is a {total}
'''.format(lineCounter=lineCounter, total="{:1.2f}".format(total))
print(response)
lineCounter += 1
total = 0
# end of for loop
return total
print(getTotal("scores.csv"))

#! next =========================== >


def reverse_numbers(input_file_path, output_file_path): try:


fin = open(input_file_path, "r") fout = open(output_file_path, "w") lineCounter = 1
for line in fin.readlines():
fout.write("Line Number ") fout.write(str(lineCounter))
fout.write("\n")
parts = line.split(",")
parts = (list(map(float, parts)))
# Returns None, but acts on the original list parts parts.reverse()
# parts is now in reverse order
fout.write(str(parts)) fout.write("\n") lineCounter += 1
# Close connections
fin.close()
fout.close() except IOError:
print("Unable to read from files given",
      input_file_path, " ", output_file_path)
# end of function
reverse_numbers("scores.csv", "reverse_numbers.csv")


#! ==============================================================================
#! NEW SECTION
#! ==============================================================================
