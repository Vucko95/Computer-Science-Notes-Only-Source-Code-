
#! Lec video = next step in python
import os
from fileinput import close
from string import strip

registrer = {}
fin = open("students.txt", "r")
lines = fin.readline()
fin.close()
for line in lines:
    line = line.strip()
    parts = line.split(",")
    student_id = int(parts[0])
    fillname = parts[1]
    register[student_id] = fullname

#! display all
for sid in register:
    print("%d -> %s" % (sid, register[sid]))

# NEXT --->

# ex 1
fin = open("sample.txt", "r")
fout = open("modified.txt", "w")
for line in fin.readline():
    fout.write("Copy: ")
    fout.write(line)

fin.close()
fout.close()

#! what you can do is
year = 2013
d = {"a": 3.0, "b": 0.0, "c": 1.0, }
fout = open("data.txt", "w")

fout.write(str(year) + "\n")
   for f in d:
        fout.write(key + " " + str(d[key]) + "\n")
    fout.close()
year = 2013
d = {"a": 3.0, "b":3.0, "c":3.0,} 
fout = open("data.txt", "w")
fout.write("%d\n" % year)  # ? what is % when we fo that ???? 
   for f in d:
    fout.write("%s, %.1f\n" % (key, d[key]))
fout.close()

#! Exception Handling
try:
    <bloq > 
except < errortype> 
    <error_handle > 

try:
    f = open("file.txt", "r")
except IOError
   print("got error")

    try:
    x = int("ucd")

    except ValueError:
    print("conversion error")
    finally
    print("always prints this")

#! ####################################################

#! MODULE AND IMPORTS

import math
import sys, os

#! important library :
#! sys : program control
#! math : basix mathematical functions

x = math.sqrt(9)
print(x)

#! os : file directory

print(os.getcwd()) # prints the correct directory
os.chdir("/usr/")  # same as
print(os.getcwd())  # same as

os.remove("letter.doc")
os.mkdir("python")
os.listdir("/ipython.files/..") # array of lists

for i in range(3):
    print("Hello World")

# """
# write file in script editor
# save script as .py file
# in terminal dir change directory containing the script
# run python passing the script file name
# eg python hello.py
#  """

#! random : random operations
#! re : regular expression

#! ---> arguments :
`python name.py fred lisa john`

import sys
print("Got %d argument " % len(sys.argv))
print("Script name is %s " % sys.argv[0])

for me in sys.argv[1:]
   print("Hello %s " % name)


    # ? output = """
    # received 4 arguments
    # Script name is name.py
    # received parameter fred
    # received parameter Lisa
    # received parameter john
    # """

# Build fabonacci series up to n

def calc_fib(n):
    series = []
    a = 0
    b = 1
    while b <n:
    series.append(b)  # ? what is b in this case? 
    temp = a
    a = b
    b = temp + b
    return series


    #! execute: in another file  =>
    import fibo
    series = fibo.calc_fib(4)
    print(series)

#! ####################################################
