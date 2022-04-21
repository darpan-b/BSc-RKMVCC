/**
 * Author: Darpan Bhattacharya
 * 2nd Semester, RKMVCC Rahara
 * Date: 11.02.2022
 */

 /*
 Program to find the sum of 3 numbers.
 */

import java.util.Scanner;

public class Sum {
   public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       System.out.println("Enter 3 numbers:");
       int n1 = sc.nextInt(), n2 = sc.nextInt(), n3 = sc.nextInt();
       int sum = n1 + n2 + n3;
       System.out.println("Sum = " + sum);
       sc.close();
   } 
}
