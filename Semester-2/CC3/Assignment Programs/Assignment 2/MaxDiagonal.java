import java.util.Scanner;
public class MaxDiagonal {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter side of matrix:");
    int side = in.nextInt();
    System.out.println("Enter " + (side * side) + " matrix elements:");
    int[][] mat = new int[side][side];
    for (int i = 0; i < side; i++) {
      for (int j = 0; j < side; j++) mat[i][j] = in.nextInt();
    }
    int lDiag = 0, rDiag = 0;
    for (int i = 0; i < side; i++) {
      lDiag += mat[i][i];
      rDiag += mat[i][side - i - 1];
    }
    if (lDiag > rDiag) System.out.println("Left diagonal sum is greater");
    else if (rDiag > lDiag) System.out.println("Right diagonal sum is greater");
    else System.out.println("Both diagonal sums are same");
    in.close();
  }
}
