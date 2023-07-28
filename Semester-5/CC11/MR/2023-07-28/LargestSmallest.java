// Write a program to find the largest and smallest elements in the array
import java.util.Scanner;

public class LargestSmallest {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter the number of elements:");
    int n = in.nextInt();
    int[] arr = new int[n];
    System.out.println("Enter " + n + " numbers:");
    for (int i = 0; i < n; i++) arr[i] = in.nextInt();
    int largest = Integer.MIN_VALUE, smallest = Integer.MAX_VALUE;
    for (int i = 0; i < n; i++) {
      largest = Math.max(largest, arr[i]);
      smallest = Math.min(smallest, arr[i]);
    }
    System.out.println("Largest value = " + largest);
    System.out.println("Smallest value = " + smallest);
  }
}
