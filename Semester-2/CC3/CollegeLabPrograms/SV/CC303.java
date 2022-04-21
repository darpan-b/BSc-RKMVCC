/**
 * Name : Darpan Bhattacharya
 * Roll no : 715
 * Problem : Arrays, Sorting
 */

package cc303;

import java.util.Scanner;

/* Define a one-dimensional array of type double dynamically.
 * Find sum, average, minimum, maximum, and average of the array elements.
 * Sort the array elements in increasing order using bubble sort.
 */

public class CC303 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = 0;
		
		do {
			System.out.print("Enter an integer (5-20):");
			if(sc.hasNext()) {
				if(sc.hasNextInt()) {
					num = sc.nextInt();
				} else {
					sc.next();
				}
			}
		}while (num < 5 || num > 20);
		
		double[] arr = new double[num];
		System.out.println("Enter " + num + " array elements:");
		for(int i = 0; i < num; i++) {
			arr[i] = sc.nextDouble();
		}
		
		double min, max, sum = 0, avg;
		min = max = arr[0];
		for (int i = 1; i < num; i++) {
			if (arr[i] < min) min = arr[i];
			if (arr[i] < max) max = arr[i];
			sum += arr[i];
		}
		avg = sum / num;
		
		System.out.println("Minimum = " + min);
		System.out.println("Maximum = " + max);
		System.out.println("Sum = " + sum);
		System.out.println("Average = " + avg);
		
		System.out.println("Before sort:");
		for (double x : arr) System.out.print(x + " ");
		System.out.println();
		
		// sorting
		for (int i = 1; i < num; i++) {
			for(int j = 0; j < num - i; j++) {
				if(arr[j] > arr[j + 1]) {
					double temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
		
		System.out.println("After sort:");
		for (double x : arr) System.out.print(x + " ");
		System.out.println();
		
		sc.close();
	}

}
