from Course import Course

def main():
    course1 = Course("Data Structures")
    course2 = Course("Database Systems")

    course1.addStudent("Peter Jones")
    course1.addStudent("Brian Smith")
    course1.addStudent("Anne Kennedy")

    course2.addStudent("Peter Jones")
    course2.addStudent("Steve Smith")

    print("Number of students in course1:",
        course1.getNumberOfStudents())
    students = course1.getStudents()
    for student in students:
        print(student, end = ", ")
    
    print("\nNumber of students in course2:",
        course2.getNumberOfStudents())

main() # Call the main function
