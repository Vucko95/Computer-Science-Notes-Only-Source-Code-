class Course: 
    def __init__(self, courseName):
        self.__courseName = courseName
        self.__students = []
  
    def addStudent(self, student):
        self.__students.append(student)
  
    def getStudents(self):
        return self.__students

    def getNumberOfStudents(self):
        return len(self.__students)

    def getCourseName(self):
        return self.__courseName

    def dropStudent(student): 
        print("Left as an exercise")
