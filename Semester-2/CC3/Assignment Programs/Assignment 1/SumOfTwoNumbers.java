import java.util.Scanner;
public class SumOfTwoNumbers {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter two numbers:");
    int a = in.nextInt(), b = in.nextInt();
    int sum = a + b;
    System.out.println("Sum of " + a + " and " + b + " is " + sum);
    in.close();
  }
}
