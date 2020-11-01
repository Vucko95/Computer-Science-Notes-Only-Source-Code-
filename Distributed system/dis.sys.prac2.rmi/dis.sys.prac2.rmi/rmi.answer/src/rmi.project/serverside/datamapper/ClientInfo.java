

package rmiproject.serverside.datamapper;

public class ClientInfo implements java.io.Serializable { // important 
 	public static final char MALE		   		= 'M'; 
	public static final char FEMALE				= 'F';

	public ClientInfo(String name, char sex, int age, int points, int noClaims, String licenseNumber) {
		this.name = name;
		this.gender = sex;
		this.age = age;
		this.points = points;
		this.noClaims = noClaims;
		this.licenseNumber = licenseNumber;
	}
	
	public ClientInfo() {}

	public String name;
	public char gender;
	public int age;
	public int points;
	public int noClaims;
	public String licenseNumber;
}
