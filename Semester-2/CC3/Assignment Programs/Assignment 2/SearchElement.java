import java.util.Scanner;
public class SearchElement {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter the number of array elements:");
    int len = in.nextInt();
    System.out.println("Enter " + len + " numbers:");
    int[] arr = new int[len];
    for (int i = 0; i < len; i++) arr[i] = in.nextInt();
    System.out.println("Enter element to be searched:");
    int toSearch = in.nextInt();
    boolean present = false;
    for (int i = 0; i < len; i++) {
      if (arr[i] == toSearch) present = true;
    }
    if (present) System.out.println(toSearch + " is present in array");
    else System.out.println(toSearch + " is not present in array");
    in.close();
  }
}
