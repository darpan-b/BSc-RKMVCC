import java.util.Scanner;
interface specialArithmetic {
  int[] all_divisors(int n);
}
class CalcDivisors implements specialArithmetic {
  public int[] all_divisors(int n) {
    int countDiv = 0;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        if (i * i == n) countDiv++;
        else countDiv += 2;
      }
    }
    int[] div = new int[countDiv];
    int curIdx = 0;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        div[curIdx++] = i;
        if (i * i != n) div[curIdx++] = n / i;
      }
    }
    return div;
  }
}
public class Divisors {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter a number:");
    int n = in.nextInt();
    CalcDivisors cdiv = new CalcDivisors();
    int[] div = cdiv.all_divisors(n);
    System.out.print("Divisors of " + n + " are: ");
    for (int d : div) System.out.print(d + " ");
    System.out.println();
    in.close();
  }
}
