import java.util.Scanner;
public class AreaPerimeter {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter the length of the rectangle:");
    int len = in.nextInt();
    System.out.println("Enter the breadth of the rectangle:");
    int brd = in.nextInt();
    int area = len * brd;
    int peri = 2 * (len + brd);
    System.out.println("The area of the rectangle = " + area);
    System.out.println("The perimeter of the rectangle = " + peri);
    in.close();
  }
}
