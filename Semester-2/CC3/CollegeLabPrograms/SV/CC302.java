/**
 * Name : Darpan Bhattacharya
 * Roll no : 715
 * Problem : Factorial
 */

package cc302;

import java.util.Scanner;

/*
 * Program to compute the factorial of a given number
 */

public class CC302 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num = 0;
		do {
			System.out.println("Enter a number (0-10):");
			num = in.nextInt();
		} while(num < 0 || num > 10);
		
		// computing the factorial
		long fact = 1L;
		for (int i = num; i >= 1; i--) fact *= i;
		System.out.println("Factorial of " + num + " is " + fact);
		in.close();
	}

}
