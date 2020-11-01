package student.core;

public class StudentRecord {
	public String student_number;
	public String firstname;
	public String surname;
	public String sex;
	public String dateofbirth;
	public String home_address;
	
	public StudentRecord(String student_number, String firstname, String surname, String sex, String dateofbirth,
			String home_address) {
		this.student_number = student_number;
		this.firstname = firstname;
		this.surname = surname;
		this.sex = sex;
		this.dateofbirth = dateofbirth;
		this.home_address = home_address;
	}

	public void merge(StudentRecord record) {
		if (student_number == null)
			student_number = record.student_number;
		if (firstname == null)
			firstname = record.firstname;
		if (surname == null)
			surname = record.surname;
		if (sex == null)
			sex = record.sex;
		if (dateofbirth == null)
			dateofbirth = record.dateofbirth;
		if (home_address == null)
			home_address = record.home_address;
	}

	public String toString() {
		return student_number + " = { " + firstname + " " + surname + ", " + sex + ", " + dateofbirth + ", "
				+ home_address + " }";
	}
}
