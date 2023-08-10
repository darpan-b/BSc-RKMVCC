// Q5. Write a program  to insert few elements in an ArrayList, compute their sum, and print.
import java.util.*;

public class ArrayListSum {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    ArrayList<Integer> arl = new ArrayList<>();
    while (true) {
      System.out.println("Enter an integer to be added to the arraylist; Press -1 to exit:");
      int x = in.nextInt();
      if (x == -1) break;
      else arl.add(x);
    }
    int answer = 0;
    for (int i = 0; i < arl.size(); i++) answer += arl.get(i);
    System.out.println("Sum of all elements of the arraylist = " + answer);
  }
}
