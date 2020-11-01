/*
 * Suppose you play Pick-10 lotto. Each ticket has 10 numbers ranging from 1 to 99, inclusive. 
 * Assume that the numbers in a ticket are picked randomly. 
 * Further, assume that the same number may appear in a ticket more than once.
 * Over all your tickets, you wish to have all the numbers from 1 to 99 included at least once. 
 * Write a program that generates lotto tickets. Print the tickets to the standard output. 
 * The program should exit when all numbers from 1 to 99 are included at least once in the 
 * tickets, and the number of tickets generated should be displayed.
*/

package chapter7_examples;

public class LottoTickets {
	public static void main(String[] args) {
		
		// Declare and create an array of booleans with 99 elements 
		// (to cover the numbers 1 to 99, inclusive).
		// The first element of this array (index 0) indicates whether 
		// the number 1 is included at least once in all the tickets generated.
		boolean[] isCovered = new boolean[99]; // Default element values are false

		// Keep track of the number of tickets generated
		int numberTickets = 0; 

		// In each iteration of the do-while loop, a new ticket is generated 
		do {
			// Increment numberTickets by 1
			numberTickets++;
			
			// Declare and create an array of integers to represent a ticket
			int[] ticket = new int[10];

			// Fill the elements in array ticket with randomly generated 
			// numbers between 1 and 99, inclusive
			for (int i = 0; i < ticket.length; i++)
				ticket[i] = 1 + (int) (Math.random() * 99);

			// Print the ticket
			System.out.printf("Ticket No. %2d:\t", numberTickets);
			for (int i = 0; i < ticket.length; i++)
				System.out.printf("%4d", ticket[i]);
			System.out.println();

			// Update the array isCovered
			for (int i = 0; i < ticket.length; i++)
				isCovered[ticket[i] - 1] = true;

			// Check if each number between 1 and 99 inclusive has been included
			// at least once in the tickets generated so far
			boolean allCovered = true; // Assume all numbers are included
			
			for (int i = 0; i < isCovered.length; i++)
				if (!isCovered[i]) { // Found a number that is not included
					allCovered = false; // Set allCovered to false
					break; // Exit the for loop
				}

			// If all numbers are included, exit the while loop; otherwise iterate over the loop again
			if (allCovered) 
				break; 
		 
		} while (true);

		// Print the number of tickets generated
		System.out.println("\nNumber of tickets needed to include all numbers at least once is: " + numberTickets);
	}
}
