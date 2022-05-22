import java.util.Scanner;
class Calculator {
  int add(int[] a) {
    int res = 0;
    for (int i = 0; i < a.length; i++) res += a[i];
    return res;
  }
  int sub(int[] a) {
    int res = a[0];
    for (int i = 1; i < a.length; i++) res -= a[i];
    return res;
  }
  int mul(int[] a) {
    int res = 1;
    for (int i = 0; i < a.length; i++) res *= a[i];
    return res;
  }
}
public class Calculation {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter the number of elements in the list:");
    int n = in.nextInt();
    int[] arr = new int[n];
    System.out.println("Enter " + n + " numbers:");
    for (int i = 0; i < n; i++) arr[i] = in.nextInt();
    Calculator cal = new Calculator();
    int sum = cal.add(arr);
    int diff = cal.sub(arr);
    int prod = cal.mul(arr);
    System.out.println("Sum of the numbers = " + sum);
    System.out.println("Difference of the numbers = " + diff);
    System.out.println("Product of the numbers = " + prod);
    in.close();
  }
}
