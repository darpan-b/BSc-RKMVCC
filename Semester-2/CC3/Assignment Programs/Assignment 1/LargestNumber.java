import java.util.Scanner;
public class LargestNumber {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter 4 numbers:");
    int a = in.nextInt(), b = in.nextInt(), 
        c = in.nextInt(), d = in.nextInt();
    int max = (a >= b && a >= c && a >= d ? a :
               b >= a && b >= c && b >= d ? b :
               c >= a && c >= b && c >= d ? c : d);
    System.out.println("Max among 4 numbers = " + max);
    in.close();
  }
}
