import java.util.Scanner;
public class Pattern {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter the number of lines:");
    int n = in.nextInt();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        System.out.print((int)Math.pow(i, j) + " ");
      }
      System.out.println();
    }
    in.close();
  }
}
