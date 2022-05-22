import java.util.Scanner;
public class Marksheet {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter marks entered out of 100:");
    int marks = in.nextInt();
    String grade = "";
    if (marks >= 95) grade = "O";
    else if (marks >= 85) grade = "A+";
    else if (marks >= 75) grade = "A";
    else if (marks >= 60) grade = "B";
    else if (marks >= 50) grade = "C";
    else if (marks >= 40) grade = "D";
    else grade = "F";
    System.out.println("Grade obtained = " + grade);
    in.close();
  }
}
