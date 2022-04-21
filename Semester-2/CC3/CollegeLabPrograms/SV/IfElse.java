/**
 * Author: Darpan Bhattacharya
 * 2nd Semester, RKMVCC Rahara
 * Date: 11.02.2022
 */

/*
Program to find the largest number out of 2 numbers input by the user.
*/

import java.util.Scanner;

public class IfElse {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter 2 numbers:");
        int n1 = sc.nextInt(), n2 = sc.nextInt();
        if (n1 > n2)
            System.out.println("Greater number is: " + n1);
        else if (n2 > n1)
            System.out.println("Greater number is: " + n2);
        else
            System.out.println("Both numbers are equal");
        sc.close();       
    }
}
