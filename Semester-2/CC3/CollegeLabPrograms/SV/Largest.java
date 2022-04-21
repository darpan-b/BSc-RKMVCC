/**
 * Author: Darpan Bhattacharya
 * 2nd Semester, RKMVCC Rahara
 * Date: 11.02.2022
 */

 /*
 Program to find the largest number out of 3 numbers input by the user.
*/

import java.util.Scanner;

public class Largest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter three numbers:");
        int n1 = sc.nextInt(), n2 = sc.nextInt(), n3 = sc.nextInt();
        int answer = n1;
        if (n2 > answer)
            answer = n2;
        if (n3 > answer)
            answer = n3;
        System.out.println("Largest number = " + answer);
        sc.close();
    }
}
