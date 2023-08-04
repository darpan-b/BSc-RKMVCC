// Q4. Write a program to insert few integer values in an ArrayList, add 5 to
//     each element and print.

import java.util.*;

public class ArrayListAddition {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter the number of elements:");
    int n = in.nextInt();
    ArrayList<Integer> al = new ArrayList<>();
    System.out.println("Enter " + n + " elements:");
    for (int i = 0; i < n; i++) al.add(in.nextInt());
    System.out.println("ArrayList before modification = " + al);
    for (int i = 0; i < n; i++) al.set(i, al.get(i) + 5);
    System.out.println("Modified ArrayList = " + al);
  }
}
