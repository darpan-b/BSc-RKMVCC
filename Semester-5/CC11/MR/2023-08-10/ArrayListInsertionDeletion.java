import java.util.*;

public class ArrayListInsertionDeletion {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter the initial number of elements:");
    int n = in.nextInt();
    ArrayList<Integer> arl = new ArrayList<>();
    System.out.println("Enter " + n + " numbers:");
    for (int i = 0; i < n; i++) arl.add(in.nextInt());
    while (true) {
      System.out.println("Press 1 to insert element in list, 2 to remove element from list.");
      System.out.println("Press any other number to exit.");
      System.out.println("Enter your choice:");
      int ch = in.nextInt();
      switch (ch) {
        case 1:
        System.out.println("Enter index to insert element in (in range [0, " + arl.size() + "]");
        int idx = in.nextInt();
        System.out.println("Enter the number to insert:");
        int x = in.nextInt();
        arl.add(idx, x);
        break;
        
        case 2:
        System.out.println("Enter index to delete element from (in range [0, " + (arl.size() - 1) + "]");
        idx = in.nextInt();
        arl.remove(idx);
        break;
        
        default:
        break;
      }
      if (ch != 1 && ch != 2) break;
    }
    System.out.println("List is = " + arl);
  }
}
