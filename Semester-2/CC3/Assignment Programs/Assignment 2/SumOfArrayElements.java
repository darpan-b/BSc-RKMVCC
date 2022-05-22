import java.util.Scanner;

public class SumOfArrayElements {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter number of array elements:");
    int len = in.nextInt();
    System.out.println("Enter " + len + " numbers:");
    int[] arr = new int[len];
    for (int i = 0; i < len; i++) arr[i] = in.nextInt();
    int sum = 0;
    for (int i = 0; i < len; i++) sum += arr[i];
    System.out.println("Sum of array elements = " + sum);
    in.close();
  }
}
