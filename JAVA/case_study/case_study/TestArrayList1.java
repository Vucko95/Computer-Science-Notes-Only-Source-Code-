package case_study;

import java.util.ArrayList;
import java.util.List;

public class TestArrayList1 {
	public static void main(String[] args) {
		// Create a list to store cities
		List<String> cityList = new ArrayList<>();

		// Add some cities in the list
		cityList.add("London"); 
		cityList.add("Denver"); 
		cityList.add("Paris");  
		cityList.add("London"); 

		// Display the contents in the list
		System.out.println(cityList.toString());
		
		// Insert a new city at index 2
		cityList.add(2, "Xian"); 
		
		// Display the contents in the list
		System.out.println(cityList.toString());
		
		// Remove a city from the list
		cityList.remove("Paris"); 

		// Display the contents in the list
		System.out.println(cityList.toString());
		
		System.out.println("List size: " + cityList.size()); 
		
		System.out.println("Is Miami in the list? " +
				cityList.contains("Miami")); 
		
		System.out.println("The location of London in the list? "
				+ cityList.indexOf("London")); 
	}
}