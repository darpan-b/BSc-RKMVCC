import java.util.Scanner;
public class ConcatStrings {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter two strings:");
    String s1 = in.nextLine(), s2 = in.nextLine();
    String cString = s1.concat(s2);
    System.out.println("Concatenated string = " + cString);
    in.close();
  }
}
