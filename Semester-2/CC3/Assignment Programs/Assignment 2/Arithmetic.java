import java.util.Scanner;
public class Arithmetic {
  int add(int a, int b) { return a + b; }
  int sub(int a, int b) { return a - b; }
  int mul(int a, int b) { return a * b; }
  int div(int a, int b) { return a / b; }
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter two numbers:");
    int a = in.nextInt(), b = in.nextInt();
    Arithmetic cal = new Arithmetic();
    System.out.println("Sum = " + cal.add(a, b));
    System.out.println("Difference = " + cal.sub(a, b));
    System.out.println("Product = " + cal.mul(a, b));
    System.out.println("Quotient = " + cal.div(a, b));
    in.close();
  }
}
