package test_examples;

import java.util.Arrays;

public class Q2_Solution {
	public static void main (String[] args) {
		// test cases
		
		// should return: [], i.e. an array with zero elements
		System.out.println("test case 1: " + Arrays.toString(getDistinctLCLetters("")));

		// should return: [], i.e. an array with zero elements
		System.out.println("test case 2: " + Arrays.toString(getDistinctLCLetters("BEE")));
		
		// should return: [e]
		System.out.println("test case 3: " + Arrays.toString(getDistinctLCLetters("Bee")));

		// should return: [d, e, l, o, r]
		System.out.println("test case 4: " + Arrays.toString(getDistinctLCLetters("Hello World!")));
	}

	// write this method
	public static char[] getDistinctLCLetters(String str) {
		// Declare and create an array of 26 booleans. The first element in this array is set 
		// to true if the letter 'a' appears in str, the second element is set to true if
		// the letter 'b' appears in str, etc.
		boolean[] isPresent = new boolean[26]; // By default, elements have value false
		for (int i = 0; i < str.length(); i++)
			if(Character.isLowerCase(str.charAt(i)))
				isPresent[str.charAt(i) - 'a'] = true;

		// Count how many elements in array isPresent have value true - this gives the number 
		// of the distinct lowercase letters in str
		int count = 0;
		for (boolean b: isPresent)
			if(b) count++;

		// Declare and create an array to hold the distinct lowercase letters
		char[] distinctLetters = new char[count];

		// Populate array distinctLetters with the distinct lowercase letters
		int index = 0;
		for (int i = 0; i < isPresent.length; i++) 
			if (isPresent[i])
				distinctLetters[index++] = (char)('a' + i);

		return distinctLetters;
	}
}