package test_examples;

import java.util.Arrays;

public class Q2 {
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
		return new char[0]; // i.e. an array with zero elements
	}
}