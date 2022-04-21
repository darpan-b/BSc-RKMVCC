import java.util.Scanner;

/*
Program to find the sum and average of some numbers input by the user.
*/

public class SumAverage {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sum = 0;
        int count = 0;
        float average = 0.0F;
        System.out.println("Enter some numbers and press Ctrl + D to terminate");
        while (sc.hasNextInt()) {
            int num = sc.nextInt();
            count++;
            sum += num;
        }
        average = (float) sum / count;
        System.out.println("Total number of numbers entered = " + count);
        System.out.println("Sum of the entered numbers = " + sum);
        System.out.println("Average of the numbers entered = " + average);
        sc.close();
    }
}
