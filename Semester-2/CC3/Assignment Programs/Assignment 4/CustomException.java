import java.util.Scanner;
class MyException extends Exception {
  public MyException() {
    super("MyException encountered");
  }
}
public class CustomException {
  public static void main(String[] args) throws MyException {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter a number:");
    int n = in.nextInt();
    in.close();
    if (n % 2 == 0 || n > 2000) throw new MyException();
  }  
}
