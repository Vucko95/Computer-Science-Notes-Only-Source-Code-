#! Lec video = next step in python
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
    # for sid in register:
    print("%d -> %s" % (sid, register[sid]))

# NEXT --->
