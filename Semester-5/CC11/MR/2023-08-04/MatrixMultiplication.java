// Q3. Write a program to multiply two matrices.

import java.util.*;

public class MatrixMultiplication {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int r1, c1, r2, c2;
    System.out.println("Enter the number of rows of the first matrix:");
    r1 = in.nextInt();
    System.out.println("Enter the number of columns of the first matrix:");
    c1 = in.nextInt();
    System.out.println("Enter the number of rows of the second matrix:");
    r2 = in.nextInt();
    System.out.println("Enter the number of columns of the second matrix:");
    c2 = in.nextInt();
    if (r1 != c2) {
      System.out.println("Matrices of dimensions " + r1 + " x " + c1 + " and " + r2 + " x " + c2 + " cannot be multiplied!");
      return;
    }
    int[][] mat1 = new int[r1][c1];
    int[][] mat2 = new int[r2][c2];
    System.out.println("Enter the elements of the first matrix:");
    for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c1; j++) {
        mat1[i][j] = in.nextInt();
      }
    }
    System.out.println("Enter the elements of the second matrix:");
    for (int i = 0; i < r2; i++) {
      for (int j = 0; j < c2; j++) {
        mat2[i][j] = in.nextInt();
      }
    }
    int[][] newMat = new int[r1][c2];
    for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c2; j++) {
        for (int k = 0; k < r2; k++) {
          newMat[i][j] += mat1[i][k] * mat2[k][j];
        }
      }
    }
    System.out.println("Resultant matrix = ");
    for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c2; j++) {
         System.out.print(newMat[i][j] + " ");
      }
      System.out.println();
    }
  }
}
