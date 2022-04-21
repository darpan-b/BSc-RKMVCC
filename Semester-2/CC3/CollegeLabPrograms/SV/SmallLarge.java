/**
 * Author: Darpan Bhattacharya
 * 2nd Semester, RKMVCC Rahara
 * Date: 11.02.2022
 */

/*
Program to find the largest and smallest number out of n numbers input by the user.
n should also be taken as input from the user.
*/

import java.util.Scanner;

public class SmallLarge {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements:");
        int n = sc.nextInt();
        System.out.println("Enter " + n + " numbers:");
        int firstNumber = sc.nextInt();
        int smallest = firstNumber, largest = firstNumber;
        for (int i = 2; i <= n; i++) {
            int currentNumber = sc.nextInt();
            if (currentNumber < smallest)
                smallest = currentNumber;
            if (currentNumber > largest)
                largest = currentNumber;
        }
        System.out.println("Smallest number = " + smallest);
        System.out.println("Largest number = " + largest);
        sc.close();
    }
}
