students = [("John", "Smith", 96), ("Susan", "King", 76), 
            ("Kim", "Yao", 99)]
students.sort(key=lambda e: (e[1]))
print(students)
print(sorted(students, key = lambda t: (t[2]), reverse = True))